/**
* Title : Binary Search Trees
* Author : Selim Firat Yilmaz
* ID: 21502736
* Section : 1
* Assignment : 2
* Description : Pointer based binary node class methods
*/
#include "PbBinaryNode.h"

PbBinaryNode::PbBinaryNode() {
	this->val = -1;
	this->leftChild = nullptr;
	this->rightChild = nullptr;
}

PbBinaryNode::PbBinaryNode(int val) {
	this->val = val;
	this->leftChild = nullptr;
	this->rightChild = nullptr;
}