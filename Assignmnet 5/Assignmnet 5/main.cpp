#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <chrono>


#include "functions.h"
using namespace std;

int main()
{
	BST bst;

	vector<int> dataSizes = { 100, 1000, 10000,100000 };

	for (int size : dataSizes) {
		//Create random Data for instertion
		vector<int> data = bst.generateRandomData(size);
		// Testing insertion
		bst.testBSTInsertion(data, "BST Insertion");
		// Test attempting to insert a duplicate node
		bst.testDuplicateInsertion( data);
		//Test removal a node from an empty BST
		 bst.testRemoveFromEmptyTree(data);
		//Test removal a node with no children
		 bst.testRemoveLeafNode(data);
		//Test removal a node with one child
		 bst.testRemoveNodeWithOneChild(data);
		//Test removal a node with two child
		 bst.testRemoveNodeWithTwoChildren(data);
	}
	return 0;
}