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
	lineQueue line;
	line.enqueue("Customer 1");
	line.enqueue("Customer 2");
	cout << line.getFront() << endl;
	line.dequeue();
	cout << line.getFront() << endl;
	line.clear();

	eventQueue events;
	events.push(1,'A',1,5);
	cout << "Customer number: " << events.getFrontNum() << " is on front with priority time: "<< events.getFrontpTime() << endl;

	events.push(3,'A',2,5);
	cout << "Customer number: " << events.getFrontNum() << " is on front with priority time: "<< events.getFrontpTime() << endl;

	events.push(5,'A',3,5);
	cout << "Customer number: " << events.getFrontNum() << " is on front with priority time: "<< events.getFrontpTime() << endl;

	events.push(7,'A',4,5);
	cout << "Customer number: " << events.getFrontNum() << " is on front with priority time: "<< events.getFrontpTime() << endl;


	events.printNodes();

	events.pop();

	cout << "After 1 pop" << endl;

	events.printNodes();

	events.pop();

	cout << "After 3 pop" << endl;

	events.printNodes();

	events.pop();

	cout << "After 5 pop" << endl;

	events.printNodes();

	events.pop();

	cout << "After 7 pop" << endl;

	cout << "isEmpty() returns: "<< events.isEmpty() << endl;

	events.printNodes();





	cout << "eventQueue is empty" << endl;
	return 0;

}