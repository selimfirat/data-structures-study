/**
* Title : Heaps and AVL Trees
* Author : Selim Fırat Yılmaz
* ID: 21502736
* Section : 1
* Assignment : 3
* Description : Min Heap implementation
*/
#include "MinHeap.h"



MinHeap::MinHeap()
{
	curSize = 0;
	items = new int[maxSize];
}


MinHeap::~MinHeap()
{
	delete[] items;
	items = nullptr;
}

int MinHeap::getMin() {
	if (curSize == 0) {
		cout << "No items found in the heap!" << endl;
		return -1;
	}

	return items[0];
}

int MinHeap::getSize() {
	return curSize;
}

int  MinHeap::removeMin() {
	int res = items[0];
	items[0] = items[curSize - 1];
	curSize--;

	MinHeapify(0);
	return res;
}

void MinHeap::insert(int item) {
	if (curSize == maxSize) {
		cout << "No space left in the heap!";
		return;
	}

	items[curSize] = item;
	int i = curSize;
	int p = parent(i);
	while (i > 0 && items[p] > items[i])
	{
		swap(&items[i], &items[p]);
		i = p;
		p = parent(i);
	}

	curSize++;
}

void MinHeap::MinHeapify(int i) {

	int original = i;
	int l = left(i);
	int r = right(i);

	if (l < curSize && items[l] < items[i])
		i = l;

	if (r < curSize && items[r] < items[i])
		i = r;

	if (i != original) {
		swap(&items[original], &items[i]);
		MinHeapify(i);
	}

}

void MinHeap::swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int MinHeap::parent(int i) {
	if (i <= 0) {
		// cout << "No parent found!";
		return -1;
	}

	return (i - 1) / 2;
}

int MinHeap::left(int i) {
	return 2 * i + 1;
}

int MinHeap::right(int i) {
	return 2 * i + 2;
}