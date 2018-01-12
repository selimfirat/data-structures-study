/**
* Title : Binary Search Trees
* Author : Selim Firat Yilmaz
* ID: 21502736
* Section : 1
* Assignment : 2
* Description : Pointer based BST node header
*/
#pragma once

class PbBinaryNode {
	private:
		int val;
		PbBinaryNode* leftChild;
		PbBinaryNode* rightChild;
		PbBinaryNode();
		PbBinaryNode(int val);

	friend class PbBST;
};