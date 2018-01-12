/**
* Title : Heaps and AVL Trees
* Author : Selim Fırat Yılmaz
* ID: 21502736
* Section : 1
* Assignment : 3
* Description : AVL Tree implementation
*/
#include "AVLTree.h"



AVLTree::AVLTree()
{
	root = nullptr;
}

AVLTree::~AVLTree()
{
	deleteFromLeafs(root);
}

void AVLTree::deleteFromLeafs(Node* root) {
	if (root == nullptr)
		return;

	deleteFromLeafs(root->left);
	deleteFromLeafs(root->right);
	delete root;
}

AVLTree::Node* AVLTree::createNode(int val) {
	Node* node = new Node;
	node->left = nullptr;
	node->right = nullptr;
	node->val = val;
	node->height = 1;

	return node;
}

// inserts an element into the tree
void AVLTree::insert(int val) {
	root = insertRec(root, val);
}

AVLTree::Node* AVLTree::insertRec(Node* cur, int val) {
	if (cur == nullptr) {
		cur = createNode(val);
	}
	else if (val < cur->val) {
		cur->left = insertRec(cur->left, val);
		balance(cur);
	}
	else
	{
		cur->right = insertRec(cur->right, val);
		balance(cur);
	}


	return cur;
}

void AVLTree::balance(Node*& node) {
	node->height = height(node);
	int bf = balanceFactor(node);

	if (bf > 1)
	{
		int lbf = balanceFactor(node->left);

		if (lbf > 0)
		{
			node = rightRotate(node);
		}
		else {
			node = leftRightRotate(node);
		}
	}
	else if (bf < -1) {
		int rbf = balanceFactor(node->right);

		if (rbf > 0)
		{
			node = rightLeftRotate(node);
		}
		else {
			node = leftRotate(node);
		}
	}
}

// returns the height of the tree
int AVLTree::getHeight() {
	return height(root);
}

AVLTree::Node* AVLTree::leftRotate(Node* parent) {
	Node* tmp = parent->right;

	parent->right = tmp->left;
	tmp->left = parent;

	parent->height = height(parent);
	tmp->height = height(tmp);

	return tmp;
}

AVLTree::Node* AVLTree::rightRotate(Node* parent) {
	Node* tmp = parent->left;

	parent->left = tmp->right;
	tmp->right = parent;

	parent->height = height(parent);
	tmp->height = height(tmp);

	return tmp;
}

AVLTree::Node* AVLTree::leftRightRotate(Node* node) {

	Node* tmp = node->left;
	node->left = leftRotate(tmp);
	return rightRotate(node);
}

AVLTree::Node* AVLTree::rightLeftRotate(Node* node) {
	Node* tmp = node->right;

	node->right = rightRotate(tmp);

	return leftRotate(node);
}

int AVLTree::max(int a, int b) {
	return a > b ? a : b;
}

int AVLTree::height(Node* node) {
	if (node == nullptr)
		return 0;

	int lh = node->left != nullptr ? node->left->height : 0;
	int rh = node->right != nullptr ? node->right->height : 0;

	return 1 + max(lh, rh);
}

int AVLTree::balanceFactor(Node* node) {
	if (node == nullptr)
		return 0;

	int lh = node->left != nullptr ? node->left->height : 0;
	int rh = node->right != nullptr ? node->right->height : 0;

	return lh - rh;
	// return height(node->left) - height(node->right);
}