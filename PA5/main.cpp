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
void simulate();
void processArrival(eventQueue& PQ, lineQueue& CQ, bool& TA, int pTime, int tTime,int num );
void processDeparture(eventQueue& PQ, lineQueue& CQ, bool& TA, int pTime, int tTime,int num );


int main()
{
	createInputFile();
	cout << "test" << endl;
	simulate();

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

void simulate()
{
	cout << "test 1" << endl;
	lineQueue bankLine;//create customer line
	eventQueue eventPriorityQueue;//create queue of events

	cout << "test 2" << endl;
	bool tellerAvailable = true;
	cout << "test 3" << endl;
	eventPriorityQueue.loadEventQueue();//enq the arrival events into the PQ
	cout << "test 4" << endl;
	int i = 0;


	//event loop
	while(eventPriorityQueue.isEmpty() != 1)
	{
		//get current time
		int currentTime = eventPriorityQueue.getFrontpTime();
		cout << "test 5" << endl;

		if(eventPriorityQueue.getFrontADtype() == 'A')
		{	
			cout << "test 6" << endl;
			i++;
			processArrival(eventPriorityQueue,bankLine,tellerAvailable,eventPriorityQueue.getFrontpTime(),eventPriorityQueue.getFrontTransTime(),i);
		}
		else
			cout << "test 7" << endl;
			processDeparture(eventPriorityQueue,bankLine,tellerAvailable,eventPriorityQueue.getFrontpTime(),eventPriorityQueue.getFrontTransTime(),i);
	}
	cout << "test 8" << endl;
}

void processArrival( eventQueue& PQ, lineQueue& CQ, bool& TA, int pTime, int tTime, int num )
{
	PQ.pop();
	int departureTime;

	if (CQ.isEmpty() && TA)
	{
		departureTime = pTime + PQ.getFrontTransTime();
		PQ.push(departureTime, 'D', 0);
		TA = false;
	}
	else
	{
		CQ.push(num, tTime, pTime);
	}
}

void processDeparture(eventQueue& PQ, lineQueue& CQ, bool& TA, int pTime, int tTime,int num )
{
	int departureTime;

	PQ.pop();
	if (!CQ.isEmpty())
	{
		CQ.pop();

		departureTime = pTime + tTime;
		PQ.push(departureTime, 'D', 0);
		TA = false;
	}
	else
		TA = true;
}
