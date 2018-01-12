/**
* Title : Binary Search Trees
* Author : Selim Firat Yilmaz
* ID: 21502736
* Section : 1
* Assignment : 2
* Description : Analysis file contains heightAnalysis and performanceAnalysis methods
*/
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "AbBST.h"
#include "PbBST.h"

using namespace std;

// height experiment is to be called for different sizes
void heightExperiment(int size) {

	cout << size << setw(30);

	PbBST pbTree1 = PbBST();
	for (int i = 0; i < size; i++)
	{
		pbTree1.insert(rand());
	}

	cout << pbTree1.getHeight() << setw(20);


	PbBST pbTree2 = PbBST();
	for (int i = 0; i < size; i++)
	{
		pbTree2.insert(i + 1);
	}

	cout << pbTree2.getHeight() << endl;

}

// do height analysis
void heightAnalysis() {

	cout << "Part f - Analysis of BST height" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "Array Size" << setw(20) << "Random Numbers" << setw(20) << "Ascending Numbers" << endl;
	cout << "----------------------------------------------------------" << endl;


	heightExperiment(2000);
	heightExperiment(4000);
	heightExperiment(6000);
	heightExperiment(8000);
	heightExperiment(10000);
	heightExperiment(12000);
	heightExperiment(14000);
	heightExperiment(16000);
	heightExperiment(18000);
	heightExperiment(20000);
}

// insertion experiment is to be called for different sizes
void insertionExperiment(int size) {

	cout << size << setw(30);
	clock_t t;
	float passedMs = 0;

	t = clock();
	AbBST abTree = AbBST();
	for (int i = 0; i < size; i++)
	{
		abTree.insert(rand() % size);
	}

	t = clock() - t;
	passedMs = 1000 * ((float)t) / CLOCKS_PER_SEC;

	cout << passedMs << " ms" << setw(20);

	t = clock();
	PbBST pbTree = PbBST();
	for (int i = 0; i < size; i++)
	{
		pbTree.insert(rand() % size);
	}

	t = clock() - t;
	passedMs = 1000 * ((float)t) / CLOCKS_PER_SEC;

	cout << passedMs << " ms" << endl;

}

// do performance analysis
void performanceAnalysis() {

	cout << "Part e - Performance analysis of BST implementations" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "Array Size" << setw(20) << "Array Based" << setw(20) << "Pointer Based" << endl;
	cout << "----------------------------------------------------------" << endl;


	insertionExperiment(2000);
	insertionExperiment(4000);
	insertionExperiment(6000);
	insertionExperiment(8000);
	insertionExperiment(10000);
	insertionExperiment(12000);
	insertionExperiment(14000);
	insertionExperiment(16000);
	insertionExperiment(18000);
	insertionExperiment(20000);
}