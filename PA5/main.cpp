//Created by: James Schnebly
//PA05
//Bank Simulation

//main.cpp (test driver)

#include <iostream>
#include <fstream>

#include "lineQueue.cpp"
#include "eventQueue.cpp"

using namespace std;

int main()
{
	eventQueue events;
	events.loadEventQueue();

	cout << "PQ has been loaded" << endl;

	events.printNodes();
	return 0;

}