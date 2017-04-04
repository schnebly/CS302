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
	lineQueue line = lineQueue();
	line.enqueue("Customer 1");
	line.enqueue("Customer 2");
	cout << line.getFront() << endl;
	line.dequeue();
	cout << line.getFront() << endl;
	line.clear();

	eventQueue events = eventQueue();
	events.push(1,'A',1,5);
	cout << "Customer number: " << events.getFrontNum() << " arrives at " << events.getFrontpTime() << endl;

	events.push(3,'A',2,5);
	cout << "Customer number: " << events.getFrontNum() << " arrives at " << events.getFrontpTime() << endl;

	events.push(5,'A',3,5);
	cout << "Customer number: " << events.getFrontNum() << " arrives at " << events.getFrontpTime() << endl;

	events.push(7,'A',4,5);
	cout << "Customer number: " << events.getFrontNum() << " arrives at " << events.getFrontpTime() << endl;

	events.pop();

	cout << "Customer number: " << events.getFrontNum() << " arrives at " << events.getFrontpTime() << endl; 


	return 0;
}