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
	
	data = 0;
	leftChildPtr = NULL;
	rightChildPtr = NULL;
}

Node::Node(int num)
{
	
	data = num;
	leftChildPtr = NULL;
	rightChildPtr = NULL;
}

Node::Node(int num, Node* leftPtr, Node* rightPtr)
{

	data = num;
	leftChildPtr = leftPtr;
	rightChildPtr = rightPtr;
}

Node::~Node()
{

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
BST::~BST()
{
	clear(root);
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
	Node* current = root;

	//add the root if the BST is empty
	if (root == NULL)
	{
		root = new Node(entry);
		cout << entry << " was added as the root Node" << endl;
		return true;

	}
	// //traverse the subTrees for correct position
	// while(current->leftChildPtr != NULL && current->rightChildPtr != NULL)
	// {
	// 	if (entry > current->data)
	// 	{
	// 			current = current->rightChildPtr;
	// 	}
	// 	else if (entry <= current->data)
	// 	{
	// 			current = current->leftChildPtr;
	// 	}
	// }

	// if (entry > current->data)
	// {
	// 	current->rightChildPtr = new Node(entry);
	// 	cout << entry << " was added as right child node of " << current->data << endl;
	// 	return true;
	// }
	// else if (entry <= current->data)
	// {
	// 	current->leftChildPtr = new Node(entry);
	// 	cout << entry << " was added as left child node of " << current->data << endl;
	// 	return true;
	// }

	// return false;
		
}
bool BST::removeNode(int target)
{
	Node* current = root;
	//Traverse BST until target == cuurent->data
	//remove node and adjust tree to account for one less node
}

void BST::clear(Node* tree)
{
	//make recursive, should be easier

	if (tree != NULL)
	{
		clear(tree->rightChildPtr);
		clear(tree->leftChildPtr);

		tree = NULL;
	}
}
