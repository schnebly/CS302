//James Schnebly
//CS302
//PA06

//Binary Search Tree
//main driver

#include <iostream>

#include "BinarySearchTree.cpp"

using namespace std;

int main()
{
	Node* root = new Node(10);
	Node* traverse = NULL;

	cout << "Is new node a leaf? " << (*root).isLeaf() << endl;

	cout << "Creating child nodes... " << endl;

	root->leftChildPtr = new Node(5, NULL, NULL);
	root->rightChildPtr = new Node(15);

	cout << "Binary tree w/ height 2:" << endl
		<< "	"<< root->data << endl
		<< root->leftChildPtr->data 
		<< "		" << root->rightChildPtr->data << endl;

	return 0;
}