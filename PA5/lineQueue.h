#include <iostream>
#include <string>

using namespace std;

class lineQueue;

class lineNode{
	private:
		lineNode(string, lineNode*);

		string name;
		lineNode* next;

		friend class lineQueue;
};

class lineQueue{
		public:
				lineQueue();
  				~lineQueue();

				bool enqueue(string);
				bool dequeue();
				string getFront();
				bool isEmpty() const;
				bool clear();

				
		private:
				lineNode* front;
				lineNode* rear;
};