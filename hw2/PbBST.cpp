/**
* Title : Binary Search Trees
* Author : Selim Firat Yilmaz
* ID: 21502736
* Section : 1
* Assignment : 2
* Description : Pointer based BST class implementation
*/

#include "PbBST.h"
#include <math.h>
#include "PbBinaryNode.h"

// constructor
PbBST::PbBST() {
	root = nullptr;
}

PbBST::~PbBST() {
	destroyTree(root);
}

// Uses postorder traversal for the destroy operation
// (Visits first the left and right children and then the node)
void PbBST::destroyTree(PbBinaryNode *& treePtr) {

	if (treePtr != nullptr) {
		destroyTree(treePtr->leftChild);
		destroyTree(treePtr->rightChild);
		delete treePtr;
		treePtr = nullptr;
	}
}


// insert to bst
void PbBST::insert(int val){
		recInsert(root, val);
}

// helper method to insert
void PbBST::recInsert(PbBinaryNode*& node, int val) {
	if (node == nullptr) {
		node = new PbBinaryNode(val);
		c++;
	}
	else if (val < node->val)
		recInsert(node->leftChild, val);
	else
		recInsert(node->rightChild, val);
}

// helper method to compute the height of bst
int PbBST::recHeight(PbBinaryNode * root) {
	if (root == nullptr)
		return 0;
		
	int leftHeight = recHeight(root->leftChild);
	int rightHeight = recHeight(root->rightChild);

	return 1 + fmax(leftHeight, rightHeight);
}

// to compute the height of bst
int PbBST::getHeight() {
	return recHeight(root);
}
	
// helper method to check whether bst is valid
bool PbBST::recValidBST(PbBinaryNode* r) {

	if (r == nullptr)
		return true;

	if (r->leftChild != nullptr && r->val < r->leftChild->val)
		return false;

	if (r->rightChild != nullptr && r->val > r->rightChild->val)
		return false;

	return recValidBST(r->leftChild) && recValidBST(r->rightChild);
}

bool PbBST::isValidBST() {
	return recValidBST(root);
}

// Implemented using Morris In order traversal
int PbBST::medianOfBST()
{
	if (root == nullptr)
		return -1;

	int cur = 0; // cursor of current node

	PbBinaryNode* current = root;
	PbBinaryNode* pre;
	PbBinaryNode* prev;

	//  Do in order traversal and find (roughly) n/2th node.
	while (current != nullptr)
	{
		if (current->leftChild == nullptr)
		{
			cur++;

			// check whether cur node is median
			if (c % 2 == 1 && cur == (c + 1) / 2)
				return prev->val;
			else if (c % 2 == 0 && cur == (c / 2) + 1)
				return (prev->val + current->val) / 2; // take average of middles

			prev = current;
			current = current->rightChild;
		}
		else
		{
			pre = current->leftChild;
			while (pre->rightChild != nullptr && pre->rightChild != current)
				pre = pre->rightChild;

			// Set current as the right child of its predecessor
			if (pre->rightChild == nullptr)
			{
				pre->rightChild = current;
				current = current->leftChild;
			}

			// Revert them
			else
			{
				pre->rightChild = nullptr;
				prev = pre;
				cur++;

				// check whether cur node is median
				if (c % 2 == 1 && cur == (c + 1) / 2)
					return current->val;

				else if (c % 2 == 0 && cur == (c / 2) + 1)
					return (prev->val + current->val) / 2;

				prev = current;
				current = current->rightChild;
			}
		}
	}
}