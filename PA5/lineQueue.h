#include <iostream>
#include <string>

using namespace std;

class lineQueue;

struct lineNode{
		lineNode(int, int,int, lineNode*);

		int customerNum;
		int tTime;
		int arrivalTime;
		lineNode* next;

		
};

class lineQueue{
		public:
				lineQueue();
  				~lineQueue();

				bool push(int, int, int);
				bool pop();
				int getFronttTime();
				int getFrontNum();
				int getFrontpTime();
				bool isEmpty() const;
				bool clear();

				
		private:
				lineNode* front;
				lineNode* rear;
};