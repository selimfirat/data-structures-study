/**
* Title : Heaps and AVL Trees
* Author : Selim Fırat Yılmaz
* ID: 21502736
* Section : 1
* Assignment : 3
* Description : Quick Median implementation
*/
#include "QuickMedian.h"



QuickMedian::QuickMedian()
{
	curSize = 0;
}


QuickMedian::~QuickMedian()
{
}


void QuickMedian::insert(int item) {
	if (curSize == 0 || item <= maxHeap.getMax())
		maxHeap.insert(item);
	else
		minHeap.insert(item);

	if (minHeap.getSize() > maxHeap.getSize()) {
		maxHeap.insert(minHeap.removeMin());
	} else if (maxHeap.getSize() > (minHeap.getSize() + 1))
		minHeap.insert(maxHeap.removeMax());


	curSize++;
}

double QuickMedian::getMedian() {
	if (curSize == 0) {
		cout << "No items in the Quick Median DS" << endl;
		return -1;
	}

	if (curSize % 2 == 0)
		return (minHeap.getMin() + maxHeap.getMax()) / 2.0;
	else
		return maxHeap.getMax();
}