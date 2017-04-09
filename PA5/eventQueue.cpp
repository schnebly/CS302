//James Schnebly
//eventQueue.cpp

#include <iostream>
#include <fstream>

#include "eventQueue.h"

#define MAX_EVENTS 100

using namespace std;

eventNode::eventNode(int p, char AD, int trans, int wTime)
{
	priorityTime = p;
	ADtype = AD;
	waitTime = wTime;
	
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

int eventQueue::getFrontwaitTime()
{
	return front->waitTime;
}

bool eventQueue::isEmpty() const
{
	if (rear == NULL)
	{
		return true;
	}
	return false;
}

bool eventQueue::push(int pTime, char AD, int trans, int wTime)
{
	eventNode* temp = new eventNode(pTime, AD, trans, wTime);
	

	if (this->isEmpty() == 1)
	{
		

		front = temp;
		rear = front;

		temp = NULL;

		delete temp;
		return true;
	}


	else if (temp->priorityTime < front->priorityTime)
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
		
		if ((ptrL->next) != NULL)
		{
			while(ptrL->next != NULL && (ptrL->next->priorityTime < temp->priorityTime))
			{
				
				ptrL = ptrL->next;
			}
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



int eventQueue::getFrontpTime()
{
	return front->priorityTime;
}

void eventQueue::printNodes()
{
	eventNode* temp = front;	
	if (this->isEmpty() == 0)
	{
		cout << "-----Event Queue ( Priority Times + Transaction Times )------" << endl;
	
		while(temp->next != NULL )									
		{														
	 		cout << temp->priorityTime << "		"<< temp->transactionTime << endl;	
	 		temp = temp->next;						
		}

		cout << temp->priorityTime << "		"<< temp->transactionTime << endl;
	}
	return;
}

void eventQueue::loadEventQueue()
{
	ifstream fin;
	int tempPTime;
	int tempTrans;
	int i = 0;

	fin.clear();

	fin.open("input.txt");

	for (i = 0; i < MAX_EVENTS; i++)
	{
		fin >> tempPTime;
		fin >> tempTrans;
		this->push(tempPTime, 'A', tempTrans, 0);
	}

	fin.close();
}														
