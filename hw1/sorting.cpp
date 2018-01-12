/**
* Title : Algorithm Efficiency and Sorting
* Author : Selim Fırat Yılmaz
* ID: 21502736
* Section : 1
* Assignment : 1
* Description : This file contains sorting methods for assigment 1.
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "sorting.h"

using namespace std;


// Swaps given elements from an array
void swap(int & a, int & b)
{
	int temp = a;
	a = b;
	b = temp;
}

// Insertion sort implementation
void insertionSort(int *arr, int size, int &compCount, int &moveCount) {
	for (int i = 1; i < size; i++) {
		int x = arr[i];
		moveCount++;
		for (int j = i - 1; j >= 0; j--) {
			moveCount++;
			compCount++;
			if (arr[j] > x) {
				arr[j + 1] = arr[j];
			}
			else {
				arr[j + 1] = x;
				break;
			}

		}
	}
}

// Merger method for mergesort
void merge(int *arr, int first, int mid, int last, int &compCount, int &moveCount) {
	int f1 = first;
	int f2 = mid + 1;
	int l1 = mid;
	int l2 = last;

	int tmpArr[99999];
	int i = f1;

	// merge arrays
	for (; f1 <= l1 && f2 <= l2; i++) {
		moveCount++;
		compCount++;
		if (arr[f1] < arr[f2]) {
			tmpArr[i] = arr[f1];
			f1++;
		}
		else {
			tmpArr[i] = arr[f2];
			f2++;
		}
	}

	// add remaining items to tmpArr
	for (; f1 <= l1; i++, f1++) {
		tmpArr[i] = arr[f1];
		moveCount++;
	}

	// add remaining items to tmpArr
	for (; f2 <= l2; i++, f2++) {
		tmpArr[i] = arr[f2];
		moveCount++;
	}

	// copy tmp array to original array
	for (int j = first; j <= last; j++) {
		arr[j] = tmpArr[j];
		moveCount++;
	}
}

// Merge sort helper method for recursion
void mergeSortRec(int *arr, int first, int last, int &compCount, int &moveCount) {
	if (first < last) {
		int  mid = (first + last) / 2;
		
		mergeSortRec(arr, first, mid, compCount, moveCount);
		mergeSortRec(arr, mid + 1, last, compCount, moveCount);

		merge(arr, first, mid, last, compCount, moveCount);
	}
}

// Merge sort implementation
void mergeSort(int *arr, int size, int &compCount, int &moveCount) {
	mergeSortRec(arr, 0, size - 1, compCount, moveCount);
}


// Partitioning method for quicksort
void partition(int *arr, int first, int last, int &pivotIndex, int &compCount, int &moveCount) {

	pivotIndex = first;
	
	int pivot = arr[pivotIndex];
	
	int lastS = first;
	int fu = first + 1;
	
	for ( ;  fu <= last; ++fu)
	{
		compCount++;
		if (arr[fu] < pivot)
		{
			lastS++;
			swap(arr[fu], arr[lastS]);
			moveCount += 3;
		}
	}

	swap(arr[first], arr[lastS]);
	pivotIndex = lastS;
	moveCount += 3;
}

// Quicksort helper method for recursion
void quickSortRec(int * arr, int first, int last, int &compCount, int &moveCount) {
	
	int pivotIndex;

	if (first < last) {

		partition(arr, first, last, pivotIndex, compCount, moveCount);

		quickSortRec(arr, first, pivotIndex - 1, compCount, moveCount);
		quickSortRec(arr, pivotIndex + 1, last, compCount, moveCount);

	}
}

// Quicksort implementation
void quickSort(int *arr, int size, int &compCount, int &moveCount) {
		quickSortRec(arr, 0, size - 1, compCount, moveCount);
}

/*
	type 0: random
	type 1: ascending
	type 2: descending
	Filling array method in random, ascending or descending fashion.
*/
void fillArray(int *a, int num_tests, int type) {
	
	for (int i = 0; i < num_tests; i++)
	{
		switch (type)
		{
			case 0:
				a[i] = rand();
				break;
			case 1:
				a[i] = i;
				break;
			case 2:
				a[i] = num_tests - i;
			default:
				break;
		}
	}


}

// Tester method that returns whether an array is sorted
bool isSorted(int *arr, int size) {

	bool x = false;

	for (int i = 1; i < size; i++)
		if (arr[i - 1] > arr[i])
			return false;

	return true;
}


/*
	type 0: random
	type 1: ascending
	type 2: descending
	Experimenting method to be called for different types(random, ascending, or descending) of different number of tests.
*/
void doExperiment(int num_tests, int type) {
	int *a1 = new int[num_tests];
	int *a2 = new int[num_tests];
	int *a3 = new int[num_tests];

	clock_t t;
	float passedSeconds = 0;
	int compCount = 0;
	int moveCount = 0;

	fillArray(a1, num_tests, type);
	fillArray(a2, num_tests, type);
	fillArray(a3, num_tests, type);

	cout << setw(40) << "Elapsed Seconds" <<  setw(20) << "compCount"  << setw(20) << "moveCount" << endl;
	cout << "Array Size : " << num_tests << endl;

	t = clock();
	insertionSort(a1, num_tests, compCount, moveCount);
	t = clock() - t;
	passedSeconds = ((float)t) / CLOCKS_PER_SEC;
	cout << "Insertion Sort" << setw(26) << passedSeconds << setw(20) << compCount << setw(20) << moveCount << endl;

	compCount = 0;
	moveCount = 0;

	t = clock();
	mergeSort(a2, num_tests, compCount, moveCount);
	t = clock() - t;
	passedSeconds = ((float)t) / CLOCKS_PER_SEC;
	cout << "Merge Sort" << setw(30) << passedSeconds << setw(20) << compCount << setw(20) << moveCount << endl;

	compCount = 0;
	moveCount = 0;

	t = clock();
	quickSort(a3, num_tests, compCount, moveCount);
	t = clock() - t;
	passedSeconds = ((float)t) / CLOCKS_PER_SEC;
	cout << "Quick Sort" << setw(30) << passedSeconds << setw(20) << compCount << setw(20) << moveCount << endl;

	cout << "----------------------------------------------------------" << endl;

	// cout << isSorted(a1, num_tests) << " " << isSorted(a2, num_tests) << " " << isSorted(a3, num_tests) << endl;

	delete[] a1;
	delete[] a2;
	delete[] a3;
}

/*
	type 0: random
	type 1: ascending
	type 2: descending
	A method that experiments each required size for a given type(ascending, descending, or random)
*/
void doFullExperiment(int type) {

	doExperiment(1000, type);
	doExperiment(5000, type);
	doExperiment(10000, type);
	doExperiment(15000, type);
	doExperiment(20000, type);

}

// Performance analysis implementation
void performanceAnalysis() {

	cout << "Part b1 - Performance analysis of random integers array" << endl;
	cout << "----------------------------------------------------------" << endl;
	doFullExperiment(0);
	cout << endl;

	cout << "Part b2 - Performance analysis of ascending integers array" << endl;
	cout << "----------------------------------------------------------" << endl;
	doFullExperiment(1);
	cout << endl;

	cout << "Part b3 - Performance analysis of descending integers array" << endl;
	cout << "----------------------------------------------------------" << endl;
	doFullExperiment(2);
	cout << endl;

}