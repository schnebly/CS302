#include <iostream>
#include <string>

using namespace std;

class eventQueue;

struct eventNode{
		
		eventNode(int,char,int,int);//
	
		int priorityTime;
		char ADtype;
		int customerNumber;
		int transactionTime;

		eventNode* next;

		
};

class eventQueue{
		public:
				eventQueue();//
  				~eventQueue();//

				bool push(int pTime, char AD, int num, int trans);//
				bool pop();//
				
				bool isEmpty() const;//
				bool clear();//
				int getFrontTransTime();//
				char getFrontADtype();//
				int getFrontNum();
				int getFrontpTime();

				
		private:
				eventNode* front;
				eventNode* rear;
};