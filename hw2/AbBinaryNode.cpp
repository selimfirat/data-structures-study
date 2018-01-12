/**
* Title : Binary Search Trees
* Author : Selim Firat Yilmaz
* ID: 21502736
* Section : 1
* Assignment : 2
* Description : Array based BST Node class methods
*/

#include "AbBinaryNode.h"

AbBinaryNode::AbBinaryNode() {
	this->val = -1;
	this->leftChildIndex = -1;
	this->rightChildIndex = -1;
}

AbBinaryNode::AbBinaryNode(int val) {
	this->val = val;
	this->leftChildIndex = -1;
	this->rightChildIndex = -1;
}