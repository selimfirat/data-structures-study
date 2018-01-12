/**
* Title : Binary Search Trees
* Author : Selim Firat Yilmaz
* ID: 21502736
* Section : 1
* Assignment : 2
* Description : Pointer based BST header
*/
#pragma once

#include "PbBinaryNode.h"

class PbBST {

	private:
		bool recValidBST(PbBinaryNode* r);
		int recHeight(PbBinaryNode * root);
		void recInsert(PbBinaryNode *& node, int val);
		PbBinaryNode* root;
		int c = 0;
		void destroyTree(PbBinaryNode *& treePtr);

	public:
		PbBST();
		~PbBST();
		void insert(int val);
		int getHeight();
		bool isValidBST();
		int medianOfBST();

};