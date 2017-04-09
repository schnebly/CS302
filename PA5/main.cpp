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
void simulate1Q1T();
void simulate1Q3T();
void simulate3Q3T();
void processArrival(eventQueue& PQ, lineQueue& CQ, bool& TA, int pTime, int tTime,int num );
void processDeparture(eventQueue& PQ, lineQueue& CQ, bool& TA, int pTime, int tTime,int num, int wTime, int& totWait, int& max );


int main()
{
	createInputFile();
	
	simulate1Q1T();
	//simulate1Q3T();
	//simulate3Q3T();

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

void simulate1Q1T()
{
	cout << endl << "----------1Q1T Simulation Begin----------" << endl << endl;
	
	lineQueue bankLine;//create customer line
	eventQueue eventPriorityQueue;//create queue of events

	int totWait = 0;
	int maxWait = 0;

	
	bool tellerAvailable = true;
	
	eventPriorityQueue.loadEventQueue();//enq the arrival events into the PQ
	
	int i = 0;
	int j = 0;


	//event loop
	while(eventPriorityQueue.isEmpty() != 1)
	{
		//get current time
		int currentTime = eventPriorityQueue.getFrontpTime();
		

		if(eventPriorityQueue.getFrontADtype() == 'A')
		{	
			
			i++;
			j = 0;
			processArrival(eventPriorityQueue,bankLine,tellerAvailable,eventPriorityQueue.getFrontpTime()
							,eventPriorityQueue.getFrontTransTime(),i);


		}
		else
		{
			j++;
			processDeparture(eventPriorityQueue,bankLine,tellerAvailable,eventPriorityQueue.getFrontpTime()
							,eventPriorityQueue.getFrontTransTime(),i, eventPriorityQueue.getFrontwaitTime(), totWait, maxWait);
		}
	}

	cout << endl << endl << "1Q1T Simulation Over" << endl << endl;

	cout << "----------Statistics---------- " << endl
		<< "Total number of people processed: " << i << endl
		<< "Average amount of time spent waiting: " << (double) totWait/MAX_EVENTS << endl << endl;

	cout << "----------Added 7.b Statistics---------- " << endl
		<< "Max Wait:  " << maxWait << endl
		<< "Min Wait: " << 0 << endl
		<< "Min Line Size: " << 0 << endl
		<< "Max Line Size: " << j << endl << endl;
}

void simulate1Q3T()
{

}
void simulate3Q3T()
{

}

void processArrival( eventQueue& PQ, lineQueue& CQ, bool& TA, int pTime, int tTime, int num)
{
	cout << "Processing ARRIVAL at time: " << pTime << endl;
	
	PQ.pop();
	int departureTime;
	int waitTime = 0;

	if (CQ.isEmpty() && TA)
	{
		departureTime = pTime + tTime;
		PQ.push(departureTime, 'D', 0, waitTime);
		TA = false;
		waitTime = 0;
	}
	else
	{
		CQ.push(num, tTime, pTime);
	}
}

void processDeparture(eventQueue& PQ, lineQueue& CQ, bool& TA, int pTime, int tTime,int num, int wTime, int& totWait, int& max)
{
             		
	int departureTime;
	int currentTime = pTime;
	int waitTime = 0;

	totWait += wTime;
	if (wTime > max)
	{
		max = wTime;
	}

	PQ.pop();
	if (!CQ.isEmpty())
	{
		departureTime = currentTime + CQ.getFronttTime();
		waitTime = currentTime - CQ.getFrontpTime();
		CQ.pop();
		PQ.push(departureTime, 'D', 0, waitTime);

		TA = false;
		
	}
	else
		TA = true;

		

	cout << "Processing DEPARTURE at time: " << pTime << "   " << " Customer waited: " << wTime << endl;
}
