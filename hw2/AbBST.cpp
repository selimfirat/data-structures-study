/**
* Title : Binary Search Trees
* Author : Selim Firat Yilmaz
* ID: 21502736
* Section : 1
* Assignment : 2
* Description : Array Based BST class methods
*/

#include "AbBinaryNode.h"
#include <math.h> // for fmax
#include "AbBST.h"

// constructor
AbBST::AbBST() {
	a = new AbBinaryNode[s];
}

AbBST::~AbBST() {
	delete[] a;
	a = nullptr;
}

// insert to bst
void AbBST::insert(int val) {

	if (c >= s) {
		AbBinaryNode* aTmp = a;

		s *= 2;
		a = new AbBinaryNode[s];

		for (int i = 0; i < s / 2; i++)
		{
			a[i] = aTmp[i];
		}

		delete[] aTmp;
		aTmp = nullptr;
	}

	a[c] = AbBinaryNode(val);

	int cur = 0;


	while (cur < c) {
		if (val < a[cur].val){
			if (a[cur].leftChildIndex == -1) {
				a[cur].leftChildIndex = c;
				return;
			}
			else {
				cur = a[cur].leftChildIndex;
			}
		}
		else if (a[cur].rightChildIndex == -1) {
			a[cur].rightChildIndex = c;
			return;
		}
		else {
			cur = a[cur].rightChildIndex;
		}
		cur++;
	}

	c++;
}

// helper method to get height recursively
int AbBST::recHeight(int rootIndex) {
	if (rootIndex >= c)
		return 0;


	int leftHeight = recHeight(a[rootIndex].leftChildIndex);
	int rightHeight = recHeight(a[rootIndex].rightChildIndex);

	return 1 + fmax(leftHeight, rightHeight);
}

// get height of bst
int AbBST::getHeight() {

	return recHeight(0);
}