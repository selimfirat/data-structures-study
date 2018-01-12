/**
* Title : Heaps and AVL Trees
* Author : Selim Fırat Yılmaz
* ID: 21502736
* Section : 1
* Assignment : 3
* Description : main.cpp file contains main method.
*/

#include <iostream>

#include "MaxHeap.h"
#include "MinHeap.h"
#include "QuickMedian.h"
#include "analysis.h"

using namespace std;

int main()
{
	int toAdd[] = { 40, 50, 45, 30, 60, 55, 20, 35, 10, 25 };

	MaxHeap maxHeap = MaxHeap();

	for (int i = 0; i < 10; i++)
		maxHeap.insert(toAdd[i]);
	cout << "--------Max Heap--------" << endl;
	cout << "Maximum Element: " << maxHeap.getMax() << endl;

	cout << "Size: " << maxHeap.getSize() << endl;
	for (int i = 0; i < 10; i++)
		cout << maxHeap.removeMax() << endl;

	MinHeap minHeap = MinHeap();

	for (int i = 0; i < 10; i++)
		minHeap.insert(toAdd[i]);
	cout << "--------Min Heap--------" << endl;

	cout << "Minimum Element: " << minHeap.getMin() << endl;

	cout << "Size: " << minHeap.getSize() << endl;
	for (int i = 0; i < 10; i++)
		cout << minHeap.removeMin() << endl;

	int toAddQM[] = { 10, 40, 30, 50, 70, 60, 20, 90, 100, 110, 0, 25, 123, 11, 200 };
	QuickMedian qm = QuickMedian();

	for (int i = 0; i < 15; i++)
		qm.insert(toAddQM[i]);

	cout << "--------Quick Median--------" << endl;

	cout << "Median: " << qm.getMedian() << endl;

	heightAnalysis();

    return 0;
}