/**
* Title : Heaps and AVL Trees
* Author : Selim Fırat Yılmaz
* ID: 21502736
* Section : 1
* Assignment : 3
* Description : Max heap implementation
*/
#include "MaxHeap.h"



MaxHeap::MaxHeap()
{
	curSize = 0;
	items = new int[maxSize];
}


MaxHeap::~MaxHeap()
{
	delete[] items;
	items = nullptr;
}

int MaxHeap::getMax() {
	if (curSize == 0) {
		cout << "No items found in the heap!" << endl;
		return -1;
	}

	return items[0];
}

int MaxHeap::getSize() {
	return curSize;
}

int  MaxHeap::removeMax() {
	int res = items[0];
	items[0] = items[curSize - 1];
	curSize--;

	maxHeapify(0);
	return res;
}

void MaxHeap::insert(int item) {
	if (curSize == maxSize) {
		cout << "No space left in the heap!";
		return;
	}

	items[curSize] = item;
	int i = curSize;
	int p = parent(i);
	while (i > 0 && items[p] < items[i])
	{
		swap(&items[i], &items[p]);
		i = p;
		p = parent(i);
	}

	curSize++;
}

void MaxHeap::maxHeapify(int i) {
	
	int original = i;
	int l = left(i);
	int r = right(i);

	if (l < curSize && items[l] > items[i])
		i = l;

	if (r < curSize && items[r] > items[i])
		i = r;

	if (i != original) {
		swap(&items[original], &items[i]);
		maxHeapify(i);
	}

}

void MaxHeap::swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int MaxHeap::parent(int i) {
	if (i <= 0) {
		// cout << "No parent found!";
		return -1;
	}

	return (i - 1) / 2;
}

int MaxHeap::left(int i) {
	return 2 * i + 1;
}

int MaxHeap::right(int i) {
	return 2 * i + 2;
}