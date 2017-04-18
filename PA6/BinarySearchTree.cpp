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
	
}

bool BST::isEmpty()
{
	if (root == NULL)
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
	Node* current;

	//add the root if the BST is empty
	if (root == NULL)
	{
		root = new Node(entry);
		cout << entry << " was added as the root Node" << endl;
		return true;

	}

	current = root;
	//traverse the subTrees for correct position
	while(current->leftChildPtr != NULL && current->rightChildPtr != NULL)
	{
		if (entry > current->data)
		{
				current = current->rightChildPtr;
		}
		else if (entry <= current->data)
		{
				current = current->leftChildPtr;
		}
	}

	if (entry > current->data)
	{
		current->rightChildPtr = new Node(entry);
		cout << entry << " was added as right child node of " << current->data << endl;
		return true;
	}
	else if (entry <= current->data)
	{
		current->leftChildPtr = new Node(entry);
		cout << entry << " was added as left child node of " << current->data << endl;
		return true;
	}

	return false;
		
}
bool BST::removeNode(int target)
{
	Node* current = root;
	//Traverse BST until target == cuurent->data
	//remove node and adjust tree to account for one less node
}

void BST::clear()
{
	Node* current = root;
	//make recursive, should be easier

	//recursively delete nodes from the bottom up
	//OR
	//code node destructor to delete childNodes
	//and just delete root and therefore recusively call node destructor
	//essentially clearing the tree
}
