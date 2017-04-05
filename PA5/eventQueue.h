#include <iostream>
#include <string>

using namespace std;

class eventQueue;

struct eventNode{
		
		eventNode(int,char,int);
	
		int priorityTime;
		char ADtype;
		int transactionTime;

		eventNode* next;

		
};

class eventQueue{
		public:
				eventQueue();
  				~eventQueue();

				bool push(int pTime, char AD, int trans);
				bool pop();
				
				bool isEmpty() const;
				bool clear();
				int getFrontTransTime();
				char getFrontADtype();
				int getFrontpTime();
				void printNodes();

				void loadEventQueue();

				
		private:
				eventNode* front;
				eventNode* rear;
};