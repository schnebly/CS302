#include <iostream>
#include <string>

using namespace std;

class eventQueue;

struct eventNode{
		
		eventNode(int,char,int,int);
	
		int priorityTime;
		char ADtype;
		int transactionTime;
		int waitTime;

		eventNode* next;

		
};

class eventQueue{
		public:
				eventQueue();
  				~eventQueue();

				bool push(int pTime, char AD, int trans, int wTime);
				bool pop();
				
				bool isEmpty() const;
				bool clear();
				int getFrontTransTime();
				char getFrontADtype();
				int getFrontpTime();
				int getFrontwaitTime();
				void printNodes();

				void loadEventQueue();

				
		private:
				eventNode* front;
				eventNode* rear;
};