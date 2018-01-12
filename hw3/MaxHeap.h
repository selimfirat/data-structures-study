/**
* Title : Heaps and AVL Trees
* Author : Selim Fırat Yılmaz
* ID: 21502736
* Section : 1
* Assignment : 3
* Description : Max heap implementation header
*/
#pragma once

#include<iostream>

using namespace std;

class MaxHeap
{
public:
	MaxHeap();
	~MaxHeap();
	void insert(int val); // inserts an element into heap
	int getMax(); // retrieves maximum element
	int removeMax(); // retrieves and removes the maximum element
	int getSize(); // returns the number of elements in heap

private:
	int *items;
	const int maxSize = 9999;
	int curSize;
	void maxHeapify(int index);
	int parent(int i);
	int left(int i);
	int right(int i);
	void swap(int *x, int *y);
};

