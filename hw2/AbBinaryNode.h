/**
* Title : Binary Search Trees
* Author : Selim Firat Yilmaz
* ID: 21502736
* Section : 1
* Assignment : 2
* Description : Array based BST Node header
*/
#pragma once

class AbBinaryNode {
	private:
		int val;
		int leftChildIndex;
		int rightChildIndex;
		AbBinaryNode();
		AbBinaryNode(int val);

	friend class AbBST;
};