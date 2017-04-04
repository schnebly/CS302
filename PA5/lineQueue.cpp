//James Schnebly

//PA05
//lineQueue.cpp implementation

#include <iostream>

#include "lineQueue.h"

using namespace std;

lineNode::lineNode(string data, lineNode* inext)
{
	cout << "Node Default Constructor" << endl;

	name = data;

	next = inext;
}

lineQueue::lineQueue()
{
	cout << "lineQueue Default Constructor" << endl;

	front = NULL;
	rear = NULL;
}

lineQueue::~lineQueue()
{
	cout << "lineQueue Destructor" << endl;
	//calls clear function to delete the queue and clear dynamic memory
	clear();
}

bool lineQueue::clear()
{
	if (isEmpty() == 1)
	{
		return false;
	}

	rear = front;

	while(rear != NULL)
	{
		front = front->next;
		rear->next = NULL;
		delete rear;
		rear = front;

	}

	return true;
}

bool lineQueue::isEmpty() const
{
	if (rear == NULL)
	{
		return true;
	}
	return false;
}

string lineQueue::getFront()
{
	return front->name;
}

bool lineQueue::enqueue(string data)
{
	if (rear == NULL)
	{
		rear = new lineNode(data, NULL);
		front = rear;
		return true;
	}
	else
		rear->next = new lineNode(data, NULL);
		rear = rear->next;
		return true;
}

bool lineQueue::dequeue()
{
	if (rear == NULL)
	{
		return false;
	}

	lineNode* temp;

	temp = front;

	front = temp->next;

	temp->next = NULL;
	delete temp;
	temp = NULL;

	if (front == NULL)
	{
		rear = NULL;
	}

	return true;
}
