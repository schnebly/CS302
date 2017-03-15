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

void selectionSort(int* arrayPtr, int values, int &swaps, int &compares); 
int partition(int *arrayPtr, const int left, const int right,int &swaps, int &compares );
void quicksort(int* arrayPtr, const int left, const int right, int &swaps, int &compares);
void radixsort(int* arrayPtr, int values,int &swaps, int &compares);
int getMax(int* arrayPtr, int values,int &swaps, int &compares);
void countSort(int* arrayPtr, int values, int exp,int &swaps, int &compares);


int main()
{	int values = 1;
	int compares = 0;
	int swaps = 0;
    clock_t t;

	cout << "Choose random list size of 1K, 10K, or 100K." << endl << "Enter either '1', '10', or '100': ";
	cin >> values;
	values *= 1000; //creates an integer 1000, 10000 or 100000 based off input

	//dynamically declare an array to store info from data.txt by use of pointer
	int* arrayPtr = new int[values];

	
	textfileBuilder(values);

    cout << endl << "*****Runs Each Sort 10 Times and Calculates Average Time, Comparisons, and Swaps*****" << endl << endl << endl;


    t = clock();
    for (int i = 0; i < 10; ++i)
    {
    arrayPtr = arrayBuilder(values, arrayPtr);
    selectionSort(arrayPtr, values, swaps, compares);
    }

	t = ((clock() - t)/10);
	cout << "Selection Sort Average Swaps: " << swaps/10 << endl;
	cout << "Selection Sort Average Comparisons: " << compares/10 << endl;
    cout << "Selction Sort Average Time: " << (float) t/CLOCKS_PER_SEC << endl << endl;
    compares = 0;
    swaps = 0;


    t = clock();
    for (int i = 0; i < 10; ++i)
    {
        arrayPtr = arrayBuilder(values, arrayPtr);
        quicksort(arrayPtr, 0, values - 1, swaps, compares);
    }

    t = ((clock() - t)/10);
	cout << "Quicksort Average Swaps: " << swaps/10 << endl;
	cout << "Quicksort Average Comparisons: " << compares/10 << endl;
    cout << "Quicksort Average Time: " << (float) t/CLOCKS_PER_SEC << endl << endl;
    compares = 0;
    swaps = 0;

    t = clock();
    for (int i = 0; i < 10; ++i)
    {
        arrayPtr = arrayBuilder(values, arrayPtr);
        radixsort(arrayPtr, values, swaps, compares);
    }

	
    t = ((clock() - t)/10);
	cout << "Radixsort Average Swaps: " << swaps/10 << endl;
	cout << "Radixsort Average Comparisons: " << compares/10 << endl;
    cout << "Radixsort Average Time: " << (float) t/CLOCKS_PER_SEC << endl << endl;

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

void selectionSort(int* arrayPtr, int values, int &swaps, int &compares) 
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
				compares++;
			}
		}

			if (pos_min != i)
			{
				swap(*(arrayPtr + i), *(arrayPtr + pos_min));
				swaps++;
			}
		
	}
}

int partition(int* arrayPtr, const int left, const int right, int &swaps, int &compares) 
{
    const int mid = left + (right - left) / 2;
    const int pivot = *(arrayPtr + mid);

    // move the mid point value to the front.
    swap(*(arrayPtr + mid),*(arrayPtr + left));
    swaps++;
    int i = left + 1;
    int j = right;

    while (i <= j) {
        while(i <= j && *(arrayPtr + i) <= pivot) 
        {
        	compares++;
            i++;
        }

        while(i <= j && *(arrayPtr + j) > pivot) 
        {
        	compares++;
            j--;
        }

        if (i < j) {
            swap(*(arrayPtr + i), *(arrayPtr + j));
            swaps++;
            compares++;
        }
    }
    	swap(*(arrayPtr + i - 1),*(arrayPtr + left));
    	swaps++;
    return i - 1;
}

void quicksort(int* arrayPtr, const int left, const int right, int &swaps, int &compares)
{

    if (left >= right) {
    	compares++;
        return;
    }


    int part = partition(arrayPtr, left, right, swaps, compares);

    quicksort(arrayPtr, left, part - 1, swaps, compares);
    quicksort(arrayPtr, part + 1, right, swaps, compares);
}

// A utility function to get maximum value in array
int getMax(int* arrayPtr, int values, int &swaps, int &compares)
{
    int mx = *arrayPtr;
    for (int i = 1; i < values; i++)
    {
        if (*(arrayPtr + i) > mx)
        {
            mx = *(arrayPtr + i);
        }
    }
    return mx;
}
 
// A function to do counting sort of array according to
// the digit represented by exp.
void countSort(int* arrayPtr, int values, int exp, int &swaps, int &compares)
{
    int output[values]; // output array
    int i, count[10] = {0};
 
    // Store count of occurrences in count[]
    for (i = 0; i < values; i++)
        count[ (*(arrayPtr + i)/exp)%10 ]++;
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = values - 1; i >= 0; i--)
    {
        output[count[ (*(arrayPtr + i)/exp)%10 ] - 1] = *(arrayPtr + i);
        count[ (*(arrayPtr + i)/exp)%10 ]--;
    }
 
    // Copy the output array to array, so that array now
    // contains sorted numbers according to current digit
    for (i = 0; i < values; i++)
        *(arrayPtr + i) = output[i];
}
 
// The main function to that sorts array of size values using 
// Radix Sort
void radixsort(int* arrayPtr, int values, int &swaps, int &compares)
{
    // Find the maximum number to know number of digits
    int m = getMax(arrayPtr, values, swaps, compares);
 
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arrayPtr, values, exp, swaps, compares);
}