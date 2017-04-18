//James Schnebly
//CS302
//PA06

//Binary Search Tree
//.cpp file (implementation)

#include <iostream>
#include <fstream>

#include "BinarySearchTree.h"

using namespace std;

Node::Node()
{
	cout << "Node default constructor" << endl;
	data = 0;
	leftChildPtr = NULL;
	rightChildPtr = NULL;
}

Node::Node(int num)
{
	cout << "Node parameterized constructor w/ data " << endl;
	data = num;
	leftChildPtr = NULL;
	rightChildPtr = NULL;
}

Node::Node(int num, Node* leftPtr, Node* rightPtr)
{
	cout << "Node parameterized constructor w/ data + pointers" << endl;
	data = num;
	leftChildPtr = leftPtr;
	rightChildPtr = rightPtr;
}

Node::~Node()
{
	cout << "Node destructor" << endl;
	leftChildPtr = NULL;
	rightChildPtr = NULL;
}								

bool Node::isLeaf()
{
	if (this->leftChildPtr == NULL && this->rightChildPtr == NULL)
	{
		return true;
	}
	else
		return false;
}				

BST::BST()
{
	root = NULL;
	root->data = 0;
}
BST::BST(Node* rootItem)
{
	root = new Node(rootItem->data);
	root->leftChildPtr = NULL;
	root->rightChildPtr = NULL;
}
BST::BST(BST& copyTree)
{
	//copy in each node from copyTree
}
BST::~BST()
{
	//call the clear function

	//delete the root ptr
}

bool BST::isEmpty()
{
	if (root == NULL;)
	{
		return true;
	}
	else
		return false;
}

int BST::getHeight()
{
	Node* ptr = root;
	int i = 0;

	while (ptr!= NULL)
	{
		ptr = ptr->leftChildPtr;
		i++;
	}

	ptr = root;
	int j = 0;

	while (ptr!= NULL)
	{
		ptr = ptr->rightChildPtr;
		j++;
	}

	if (i >= j)
	{
		return i;
	}
	else
		return j;

}
int BST::getNumOfNodes()
{
	//make recursive, should be easier
}

int BST::getRootData()
{
	return root->data;
}
void BST::setRootData(int set)
{
	root->data = set;
}

bool BST::addNode(int entry)
{
	
}
bool BST::removeNode(int target)
{
	
}

void BST::clear()
{
	make recursive, should be easier;
}
