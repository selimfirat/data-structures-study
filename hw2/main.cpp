/**
* Title : Binary Search Trees
* Author : Selim Firat Yilmaz
* ID: 21502736
* Section : 1
* Assignment : 2
* Description : Main class to test implementation
*/
#include <iostream>
#include "PbBST.h"
#include "analysis.h"
#include "AbBST.h"

using namespace std;

// main method to be called
int main() {

	PbBST pbTree = PbBST();

	pbTree.insert(40);
	pbTree.insert(50);
	pbTree.insert(45);
	pbTree.insert(30);
	pbTree.insert(60);
	pbTree.insert(55);
	pbTree.insert(20);
	pbTree.insert(35);
	pbTree.insert(10);
	pbTree.insert(25);

	cout << "isValid: " << pbTree.isValidBST() << endl;
	cout << "Median: " << pbTree.medianOfBST() << endl;

	performanceAnalysis();
	heightAnalysis();

	int x;
	cin >> x;
}