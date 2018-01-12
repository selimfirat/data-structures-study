/**
* Title : Heaps and AVL Trees
* Author : Selim Fırat Yılmaz
* ID: 21502736
* Section : 1
* Assignment : 3
* Description : AVL Tree implementation
*/
#pragma once

#include<iostream>

using namespace std;

class AVLTree
{
public:
	AVLTree();
	~AVLTree();
	void insert(int val); // inserts an element into the tree
	int getHeight(); // returns the height of the tree


private:
	struct Node
	{
		int val;
		struct Node *left;
		struct Node *right;
		struct Node *parent;
		int height;
	};
	Node* root;
	Node* createNode(int val);
	void deleteFromLeafs(Node* root);
	Node* leftRotate(Node* node);
	Node* rightRotate(Node* node);
	Node* leftRightRotate(Node* node);
	Node* rightLeftRotate(Node* node);
	int max(int a, int b);
	int height(Node* node);
	int balanceFactor(Node* node);
	void balance(Node*& cur);
	Node* insertRec(Node* cur, int val);
};

