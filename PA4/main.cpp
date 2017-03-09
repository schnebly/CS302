//James Schnebly
//Project 4
//Sorting Algos


//****COMPILE WITH C++11****

#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <random>
#include <chrono>
#include <utility>

using namespace std;

//prototypes
int randNumGenerator();
void textfileBuilder(int values);
int* arrayBuilder(int values, int* arrayPtr);
void selectionSort(int* arrayPtr, int values); 
int partition(int *arrayPtr, const int left, const int right);
void quicksort(int* arrayPtr, const int left, const int right);


int main()
{	int values = 1;

	cout << "Choose random list size of 1K, 10K, or 100K." << endl << "Enter either '1', '10', or '100': ";
	cin >> values;
	values *= 1000; //creates an integer 1000, 10000 or 100000 based off input

	//dynamically declare an array to store info from data.txt by use of pointer
	int* arrayPtr = new int[values];

	//build data.txt and fill array based on input file
	textfileBuilder(values);
	arrayPtr = arrayBuilder(values, arrayPtr);

						//*****TESTING PURPOSES ONLY*****
						//print the first 5 randomly generated numbers in the array

						//Testing functions:randNumGenerator, textfileBuilder, and arrayBuilder
	// for (int i = 0; i < 5; ++i)
	// {
	// 	cout << *(arrayPtr + i) << endl;
	// }
						//***** END OF TESTING*****

						//*****TESTING PURPOSES ONLY*****
						//test selection sort
						//print sorted list in terminal

	// selectionSort(arrayPtr, values);
	// for (int i = 0; i < values; ++i)
	// {
	// 	cout << *(arrayPtr + i) << endl;
	// }
						//***** END OF TESTING*****

						//*****TESTING PURPOSES ONLY*****
						//test quicksort
						//print sorted list in terminal
	quicksort(arrayPtr, 0, values - 1);

	for ( int i = 0; i < values; ++i)
	{
		cout << *(arrayPtr + i) << endl;
	}
						//***** END OF TESTING*****
	return 0;
}

int randNumGenerator()
{
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();

	mt19937 mt_rand(seed);	

	uniform_int_distribution<int> set(0,1000000);

	return set(mt_rand);
}

void textfileBuilder(int values)
{
	ofstream fout;

	fout.clear();
	fout.open("data.txt");

	for (int i = 0; i < values; i++)
	{
		fout << randNumGenerator() << endl;
	}

	fout.close();
}

int* arrayBuilder(int values, int* arrayPtr)
{
	ifstream fin;

	fin.clear();
	fin.open("data.txt");

	for (int i = 0; i < values; ++i)
	{
		fin >> *(arrayPtr + i);
	}

	fin.close();

	return arrayPtr;
}

void selectionSort(int* arrayPtr, int values) 
{
	int pos_min, temp;

	for (int i = 0; i < values -1; i++)
	{
		pos_min = i;
		for (int j =i+1; j < values; j++)
		{
			if (*(arrayPtr + j) < *(arrayPtr + pos_min))
			{
				pos_min = j;
			}
		}

			if (pos_min != i)
			{
				swap(*(arrayPtr + i), *(arrayPtr + pos_min));
			}
		
	}
}

int partition(int* arrayPtr, const int left, const int right) 
{
    const int mid = left + (right - left) / 2;
    const int pivot = *(arrayPtr + mid);

    // move the mid point value to the front.
    swap(*(arrayPtr + mid),*(arrayPtr + left));
    int i = left + 1;
    int j = right;

    while (i <= j) {
        while(i <= j && *(arrayPtr + i) <= pivot) 
        {
            i++;
        }

        while(i <= j && *(arrayPtr + j) > pivot) 
        {
            j--;
        }

        if (i < j) {
            swap(*(arrayPtr + i), *(arrayPtr + j));
        }
    }
    	swap(*(arrayPtr + i - 1),*(arrayPtr + left));
    return i - 1;
}

void quicksort(int* arrayPtr, const int left, const int right)
{

    if (left >= right) {
        return;
    }


    int part = partition(arrayPtr, left, right);

    quicksort(arrayPtr, left, part - 1);
    quicksort(arrayPtr, part + 1, right);
}
