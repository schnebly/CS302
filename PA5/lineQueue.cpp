//James Schnebly

//PA05
//lineQueue.cpp implementation

#include <iostream>

#include "lineQueue.h"

using namespace std;

lineNode::lineNode(int data,int iTime, int ipTime ,lineNode* inext)
{
	

	customerNum = data;

	tTime = iTime;

	next = inext;

	arrivalTime = ipTime;
}

lineQueue::lineQueue()
{
	

	front = NULL;
	rear = NULL;
}

lineQueue::~lineQueue()
{
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

int lineQueue::getFrontNum()
{
	return front->customerNum;
}

int lineQueue::getFronttTime()
{
	return front->tTime;
}

int lineQueue::getFrontpTime()
{
	return front->arrivalTime;
}

bool lineQueue::push(int data, int trans, int prior)
{
	if (rear == NULL)
	{
		rear = new lineNode(data,trans,prior, NULL);
		front = rear;
		return true;
	}
	else
		rear->next = new lineNode(data,trans, prior, NULL);
		rear = rear->next;
		return true;
}

bool lineQueue::pop()
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
