#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <chrono>
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

using namespace std;

// This is for the structure of the Binary Search Treea
struct treeNode
{
	int item;
	treeNode* Lchild; // Left Child
	treeNode* Rchild; // Right Child
};
class BST
{
	treeNode* root;

public:
	BST();
	bool add(int i);
	bool remove(int i);
	treeNode* getRoot();
	int max();
	void inorder(treeNode* p);
	vector<int> generateRandomData(int size); // Declare here
	void testBSTInsertion(const vector<int>& data, const string& operationName);
	void testDuplicateInsertion(const std::vector<int>& data);
	void testRemoveFromEmptyTree(const std::vector<int>& data);
	void testRemoveLeafNode(const std::vector<int>& data);           // Test removal of a leaf node
	void testRemoveNodeWithOneChild(const std::vector<int>& data);   // Test removal of a node with one child
	void testRemoveNodeWithTwoChildren(const std::vector<int>& data); // Test removal of a node with two children

private:
	void inorder(treeNode** n);
	bool remove(treeNode* n, treeNode* parent);
};

#endif // FUNCTIONS_H