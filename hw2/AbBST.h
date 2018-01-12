/**
* Title : Binary Search Trees
* Author : Selim Firat Yilmaz
* ID: 21502736
* Section : 1
* Assignment : 2
* Description : Array based BST header
*/
#pragma once
#include "AbBinaryNode.h"
class AbBST {
	private:
		int c = 0;
		int s = 2;
		AbBinaryNode* a;
		int recHeight(int rootIndex);

	public:
		AbBST();
		~AbBST();
		void insert(int val);
		int getHeight();

};