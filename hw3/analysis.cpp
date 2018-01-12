/**
* Title : Heaps and AVL Trees
* Author : Selim Fırat Yılmaz
* ID: 21502736
* Section : 1
* Assignment : 3
* Description : Analysis file contains height analysis related methods.
*/
#include "analysis.h"


// height experiment is to be called for different sizes
void heightExperiment(int size) {

	cout << size << setw(30);

	AVLTree avlTree1;
	for (int i = 0; i < size; i++)
	{
		avlTree1.insert(rand() % size);
	}

	cout << avlTree1.getHeight() << setw(20);


	AVLTree avlTree2;
	for (int i = 0; i < size; i++)
	{
		avlTree2.insert(i + 1);
	}

	cout << avlTree2.getHeight() << setw(20);

	AVLTree avlTree3;
	for (int i = size - 1; i >= 0; i--)
	{
		avlTree3.insert(i + 1);
	}

	cout << avlTree3.getHeight() << endl;

}

// do height analysis
void heightAnalysis() {

	cout << "Part e - Height analysis of AVL trees" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "Array Size" << setw(20) << "Random" << setw(20) << "Ascending" << setw(20) << "Descending" << endl;
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