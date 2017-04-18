//James Schnebly
//CS302
//PA06

//Binary Search Tree
//main driver

#include <iostream>
#include <fstream>

#include "BinarySearchTree.cpp"

using namespace std;

void createInputFile();



int main()
{
	createInputFile();
	cout << "Input file has been generated with 100 values between 1-200..." << endl;

	BST tree;
	
	ifstream fin;
	int entry;

	fin.open("input.txt");

	for (int i = 0; i < 100; i++)
	{
		fin >> entry;
		tree.addNode(entry);
		cout << "#" << i << endl;
	}

	fin.close();

	cout << "Height of tree: " << tree.getHeight() << endl
		<< "Root of tree: " << tree.getRootData() << endl;
	return 0;
}

void createInputFile()
{
	ofstream fout;

	fout.clear();

	fout.open("input.txt");

	srand (time(NULL));


	for (int i = 0; i < 100; ++i)
	{
		fout << rand() % 200 + 1 << endl;
	}

	fout.close();
}