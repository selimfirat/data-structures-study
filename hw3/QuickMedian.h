/**
* Title : Heaps and AVL Trees
* Author : Selim Fırat Yılmaz
* ID: 21502736
* Section : 1
* Assignment : 3
* Description : Quick Median solution implementation header
*/
#pragma once

#include <iostream>
#include "MaxHeap.h"
#include "MinHeap.h"

using namespace std;
class QuickMedian
{
public:
	QuickMedian();
	~QuickMedian();
	void insert(int val); // inserts an element into QuickMedian
	double getMedian(); // returns the median of elements

private:
	MinHeap minHeap;
	MaxHeap maxHeap;
	int curSize;
};

