//James Schnebly
//CS302
//PA06

//Binary Search Tree
//.h file

#include <iostream>
#include <fstream>

using namespace std;

class Node
{
public:
	
	int data;										//data var
	Node* leftChildPtr;								//pointer to left child node
	Node* rightChildPtr;							//pointer to right child node

	Node();											//Default constructor
	Node(int num, Node* leftPtr, Node* rightPtr);	//parameterized constructor
	Node(int num);									//parameterized constructor
	~Node();										//destructor									//get var

	bool isLeaf();									//asks if the node is a leaf node

};

class BST
{
public:

	BST();
	BST(Node* rootItem);
	BST(BST& copyTree);
	~BST();

	bool isEmpty();

	int getHeight();
	int getNumOfNodes();

	int getRootData();
	void setRootData(int set);

	bool addNode(int entry);
	bool removeNode(int target);

	void clear();

private:
	
	Node* root;
	
};