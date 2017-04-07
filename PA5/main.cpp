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
	
	lineQueue bankLine;//create customer line
	eventQueue eventPriorityQueue;//create queue of events

	
	bool tellerAvailable = true;
	
	eventPriorityQueue.loadEventQueue();//enq the arrival events into the PQ
	
	int i = 0;


	//event loop
	while(eventPriorityQueue.isEmpty() != 1)
	{
		//get current time
		int currentTime = eventPriorityQueue.getFrontpTime();
		

		if(eventPriorityQueue.getFrontADtype() == 'A')
		{	
			
			i++;
			processArrival(eventPriorityQueue,bankLine,tellerAvailable,eventPriorityQueue.getFrontpTime(),eventPriorityQueue.getFrontTransTime(),i);
		}
		else
			
			processDeparture(eventPriorityQueue,bankLine,tellerAvailable,eventPriorityQueue.getFrontpTime(),eventPriorityQueue.getFrontTransTime(),i);
	}

	cout << "Simulation Over" << endl;
	
}

void processArrival( eventQueue& PQ, lineQueue& CQ, bool& TA, int pTime, int tTime, int num )
{
	PQ.pop();
	int departureTime;

	if (CQ.isEmpty() && TA)
	{
		departureTime = pTime + tTime;
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
