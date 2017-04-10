//Created by: James Schnebly
//PA05
//Bank Simulation

//main.cpp (test driver)

/////////////////**MUST BE COMPILED USING -std=c++11  **/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

#include "lineQueue.cpp"
#include "eventQueue.cpp"


using namespace std;

//helping functions
void createInputFile();
int getShortestLine(lineQueue line[3]);
bool checkLineEmpty(lineQueue lines[3]);
bool checkTA ( bool availiableTellers[3]);

//Quesion 6 and 7b
void simulate1Q1T();
void processArrival(eventQueue& PQ, lineQueue& CQ, bool& TA, int pTime, int tTime,int num );
void processDeparture(eventQueue& PQ, lineQueue& CQ, bool& TA, int pTime, int tTime,int num, int wTime, int& totWait, int& max );

//Quesion 7b + 7d
void simulate1Q3T();
void processArrival2(int pTime, int tTime, bool availiableTellers[3], eventQueue& PQ, lineQueue& CQ);
void processDeparture2(int& wTime, int pTIme, bool availiableTellers[3], eventQueue& PQ, lineQueue& CQ, int& max);

//Question 7b + 7d
void simulate3Q3T();
void processArrival3(int pTime, int tTime, bool availiableTellers[3], eventQueue& PQ, lineQueue lines[3]);
void processDeparture3(int& wTime, int pTime, bool availiableTellers[3], eventQueue& PQ, lineQueue lines[3], int& max );

int main()
{
	int input;

	createInputFile();

	//display menu
	cout << endl << "input.txt has been generated" << endl << endl;
	cout << "----------Command Menu----------" << endl << endl
		<< "1. One Queue One Teller" << endl
		<< "2. Three Queues Three Tellers" << endl
		<< "3. One Queue One Teller" << endl 
		<< "4. Regenerate input.txt with new numbers" << endl
		<< "5. Exit the program" << endl;

		cout << "Enter command: ";
		cin >> input; 

	while(input != 5)
	{
		switch(input)
		{
			case 1:
			{
				simulate1Q1T();
				break;
			}

			case 2:
			{
				simulate3Q3T();
				break;
			}

			case 3:
			{
				simulate1Q3T();
				break;
			}

			case 4:
			{
				createInputFile();
				cout << endl << "input.txt has been generated" << endl << endl;
				break;
			}

			default:
			{	
				cout << "Please Enter a Valid Command!" << endl << endl;
				
			}
		}

		cout << "----------Command Menu----------" << endl << endl
		<< "1. One Queue One Teller (#6)" << endl
		<< "2. Three Queues Three Tellers (#7c)" << endl
		<< "3. One Queue Three Teller (#7d)" << endl 
		<< "4. Regenerate input.txt with new numbers" << endl
		<< "5. Exit the program" << endl;

			cout << "Enter command: ";
			cin >> input;
	}
	cout << endl <<"**********Program terminated by User Input**********" <<endl << endl;
	return EXIT_SUCCESS;
}

//create the input file
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

//Question 6+7b: 1 Queue 1 Teller run function
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
		<< "Min Wait: " << 0 << endl
		<< "Max Wait:  " << maxWait << endl
		<< "Min Line Size: " << 0 << endl
		<< "Max Line Size: " << j << endl << endl;
}

//process arrival events for 1Q1T
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

//process departure events for 1Q1T
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

//Question 7d: 1 Queue 3 Tellers run function
void simulate1Q3T()
{
	lineQueue bankLine;
	eventQueue eventPriorityQueue;

	int totWait = 0;
	double avgWait = 0.0;
	int j = 0;
	int i = 0;
	

	bool tellers[3] = {1,1,1};

	eventPriorityQueue.loadEventQueue();
	cout << "---------1Q3T Simulation Begin---------" << endl;

	while(eventPriorityQueue.isEmpty() == 0)
	{
		if (eventPriorityQueue.getFrontADtype() == 'A')
		{
			cout << "Processing ARRIVAL at time: " << eventPriorityQueue.getFrontpTime() << endl;

			j = 0;

			processArrival2(eventPriorityQueue.getFrontpTime(), eventPriorityQueue.getFrontTransTime(),
				tellers, eventPriorityQueue, bankLine);
		}
		else if (eventPriorityQueue.getFrontADtype() == 'D')
		{
			cout << "Processing DEPARTURE at time: " << eventPriorityQueue.getFrontpTime() << endl;
			j++;
			processDeparture2(totWait, eventPriorityQueue.getFrontpTime(), tellers, eventPriorityQueue,
			 	bankLine, i);
		}
	}
	avgWait = totWait/MAX_EVENTS;

	cout << endl << endl << "1Q3T Simulation Over" << endl << endl;

	cout << "----------Statistics---------- " << endl
		<< "Total number of people processed: " << MAX_EVENTS << endl
		<< "Average amount of time spent waiting: " << avgWait << endl << endl;

	cout << "----------Added 7.b Statistics---------- " << endl
		<< "Min Wait: " << 0 << endl
		<< "Max Wait: " << i << endl
		<< "Min Line Size: " << 0 << endl
		<< "Max Line Size: " << j << endl << endl;
}

//checks to see if any of the three tellers are open
bool checkTA ( bool availiableTellers[3])
{
	if (availiableTellers[0] == true || availiableTellers[1] == true || availiableTellers[2] == true)
	{
		return true;
	}
	else
		return false;
}

//process arrival events for 1Q3T
void processArrival2(int pTime, int tTime, bool availiableTellers[3], eventQueue& PQ, lineQueue& CQ)
{
	int departureTime;
	bool isTA;

	PQ.pop();

	isTA = checkTA(availiableTellers);

	if (CQ.isEmpty() && isTA)
	{
		departureTime = pTime + tTime;
		PQ.push(departureTime, 'D', 0, 0);

		if (availiableTellers[0] == 1)
		{
			availiableTellers[0] = 0;
		}
		else if (availiableTellers[0] == 0 && availiableTellers[1] == 1)
		{
			availiableTellers[1] = 0;
		}
		else if (availiableTellers[0] == 0 && availiableTellers[1] == 0)
		{
			availiableTellers[2] = 0;
		}
	}
	else
	{
		CQ.push(0, tTime, pTime);
	}	
}

//process departure events for 1Q3T
void processDeparture2(int& wTime, int pTime, bool availiableTellers[3], eventQueue& PQ, lineQueue& CQ, int& max)
{
	int departureTime = 0;
	int wait = 0;

	PQ.pop();

	if (CQ.isEmpty() == 0)
	{
		departureTime = pTime + CQ.getFronttTime();
		wTime += (pTime - CQ.getFrontpTime());
		wait = pTime - CQ.getFrontpTime();
		CQ.pop();
		PQ.push(departureTime, 'D',0, wait);
	}
	else
	{
		availiableTellers[0] = true;
	}
	if(wait > max)
	{
		max = wait;
	}
}

//Question 7c: 3 Queue 3 Tellers run function
void simulate3Q3T()
{
	lineQueue lines[3];
	eventQueue eventPriorityQueue;

	int totWait = 0;
	double avgWait = 0.0;
	int j = 0;
	int i = 0;

	bool tellers[3] = {1,1,1};

	eventPriorityQueue.loadEventQueue();
	cout << "----------3Q3T Simulation Begin----------" << endl;

	while(eventPriorityQueue.isEmpty() == 0)
	{
		if (eventPriorityQueue.getFrontADtype() == 'A')
		{
			cout << "Processing ARRIVAL at time: " << eventPriorityQueue.getFrontpTime() << endl;

			j = 0;

			processArrival3(eventPriorityQueue.getFrontpTime(), eventPriorityQueue.getFrontTransTime(),
				tellers, eventPriorityQueue, lines);
		}
		else if (eventPriorityQueue.getFrontADtype() == 'D')
		{
			cout << "Processing DEPARTURE at time: " << eventPriorityQueue.getFrontpTime() << endl;
			j++;
			processDeparture3(totWait, eventPriorityQueue.getFrontpTime(), tellers, eventPriorityQueue,
			 	lines, i);
		}
	}
	avgWait = totWait/MAX_EVENTS;
	cout << endl << endl << "3Q3T Simulation Over" << endl << endl;

	cout << "----------Statistics---------- " << endl
		<< "Total number of people processed: " << MAX_EVENTS << endl
		<< "Average amount of time spent waiting: " << avgWait << endl << endl;

	cout << "----------Added 7.b Statistics---------- " << endl
		<< "Min Wait: " << 0 << endl
		<< "Max Wait: " << i << endl
		<< "Min Line Size: " << 0 << endl
		<< "Max Line Size: " << j << endl << endl;
}

//process arrival events for 3Q3T
void processArrival3(int pTime, int tTime, bool availiableTellers[3], eventQueue& PQ, lineQueue lines[3])
{
	int departureTime;
	bool isTA;
	bool isLineEmpty;

	PQ.pop();

	isTA = checkTA(availiableTellers);
	isLineEmpty = checkLineEmpty(lines);

	if (isLineEmpty && isTA)
	{
		departureTime = pTime + tTime;
		PQ.push(departureTime, 'D', 0, 0);

		if (availiableTellers[0] == 1)
		{
			availiableTellers[0] = 0;
		}
		else if (availiableTellers[0] == 0 && availiableTellers[1] == 1)
		{
			availiableTellers[1] = 0;
		}
		else if (availiableTellers[0] == 0 && availiableTellers[1] == 0)
		{
			availiableTellers[2] = 0;
		}
	}
	else
	{
		lines[getShortestLine(lines)].push(0, tTime, pTime);
	}	
}

//process departure events for 3Q3T
void processDeparture3(int& wTime, int pTime, bool availiableTellers[3], eventQueue& PQ, lineQueue lines[3], int& max )
{
	int departureTime = 0;
	int wait = 0;
	bool isAnyEmpty;


	PQ.pop();

	isAnyEmpty = checkLineEmpty(lines);

	if (isAnyEmpty == 0)
	{
		departureTime = pTime + lines[0].getFronttTime();
		wTime += (pTime - lines[0].getFrontpTime());
		wait = pTime - lines[0].getFrontpTime();
		lines[0].pop();
		PQ.push(departureTime, 'D',0, wait);
	}
	else
	{
		availiableTellers[0] = true;
	}
	if(wait > max)
	{
		max = wait;
	}
}

//check if any line is empty
bool checkLineEmpty(lineQueue lines[3])
{
	if (lines[0].isEmpty() == 1 || lines[1].isEmpty() == 1 || lines[2].isEmpty() == 1)
	{
		return true;
	}
	else	
	{
		return false;
	}
}

//return the shortest customer line 
int getShortestLine(lineQueue lines[3])
{
	int SL = 0;
	if ((lines[0].getLength() < lines[1].getLength()) && (lines[0].getLength() < lines[2].getLength()))
	{
		SL = 0;
	}
	else if ((lines[1].getLength() < lines[0].getLength()) && (lines[1].getLength() < lines[2].getLength()))
	{
		SL = 1;
	}
	else if ((lines[2].getLength() < lines[0].getLength()) && (lines[2].getLength() < lines[1].getLength()))
	{
		SL = 3;
	}

	return SL;
}