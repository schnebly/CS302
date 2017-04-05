//Created by: James Schnebly
//PA05
//Bank Simulation

//main.cpp (test driver)

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

#include "lineQueue.cpp"
#include "eventQueue.cpp"


using namespace std;

void createInputFile();

int main()
{
	createInputFile();

	eventQueue events;
	events.loadEventQueue();

	cout << "PQ has been loaded" << endl;

	events.printNodes();

	
	return 0;

}

void createInputFile()
{
	ofstream fout;

	fout.clear();

	fout.open("input.txt");

	srand (time(NULL));


	for (int i = 0; i < MAX_EVENTS; ++i)
	{
		fout << rand() % 540 + 1 << "		"<< rand() % 20 + 1 << endl;
	}

	fout.close();
}