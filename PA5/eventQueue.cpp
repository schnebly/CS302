//James Schnebly
//eventQueue.cpp

#include <iostream>
#include <fstream>

#include "eventQueue.h"

using namespace std;

eventNode::eventNode(int p, char AD, int num, int trans)
{
	priorityTime = p;
	ADtype = AD;
	customerNumber = num;
	transactionTime = trans;

	next = NULL;

}

eventQueue::eventQueue()
{
	front = NULL;
	rear = NULL;
}

eventQueue::~eventQueue()
{
	this->clear();
}

bool eventQueue::clear()
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

int eventQueue::getFrontTransTime()
{

	return front->transactionTime;

}

bool eventQueue::isEmpty() const
{
	if (rear == NULL)
	{
		return true;
	}
	return false;
}

bool eventQueue::push(int pTime, char AD, int num, int trans)
{
	eventNode* temp = new eventNode(pTime, AD, num, trans);

	if (this->isEmpty() == 1)
	{

		front = temp;
		rear = front;

		temp = NULL;

		delete temp;
		return true;
	}

	else if (temp->priorityTime > front->priorityTime)
	{
		temp->next = front;
		front = temp;

		temp = NULL;

		delete temp;
		return true;
	}

	else
	{
		eventNode* ptrL = front;

		while(ptrL->next->priorityTime < temp->priorityTime)
		{
			ptrL = ptrL->next;
		}

		temp->next = ptrL->next;

		ptrL->next = temp;

		temp = NULL;

		delete temp;
		return true;
	}

}

bool eventQueue::pop()
{
	if (isEmpty() == 1)
	{
		return false;
	}

	else
	{
		eventNode* temp = front;
		front = front->next;

		delete temp;
		temp = NULL;

		if (front == NULL)
		{
			rear = NULL;
		}
		return true;
	}
}

char eventQueue::getFrontADtype()
{
	return front->ADtype;
}

int eventQueue::getFrontNum()
{
	return front->customerNumber;
}

int eventQueue::getFrontpTime()
{
	return front->priorityTime;
}