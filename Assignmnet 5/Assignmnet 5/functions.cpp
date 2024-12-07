#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <chrono>

#include "functions.h"


using namespace std;


BST::BST() //default constructor
{
	root = NULL;
}
bool BST::add(int i)
{
	treeNode* n = new treeNode();
	n->item = i;
	if (root == NULL)
	{
		root = n;
		return true;
	}
	else
	{
		treeNode* p = root;
		while (p != NULL)
		{
			if (i == p->item) //duplicate
				return false;
			else if (i < p->item) //if value to be inserted is less than current nodes value
			{
				if (p->Lchild == NULL) //go to left subtree
				{
					p->Lchild = n;
					return true;
				}
				else
					p = p->Lchild;
			}
			else
			{
				if (p->Rchild == NULL) //go to right subtree
				{
					p->Rchild = n;
					return true;
				}
				else
					p = p->Rchild;
			}
		}
	}
	return false;
}

bool BST::remove(treeNode* n, treeNode* parent)
{
	if (n->Lchild == NULL && n->Rchild == NULL) //deleting leaf node
	{
		if (parent != NULL) //not deleting root
		{
			if (parent->Lchild == n)
				parent->Lchild = NULL;
			else
				parent->Rchild = NULL;
		}
		else //deleteing root which is the only node in tree
			root = NULL;

		delete n;
	}
	else if (n->Lchild != NULL && n->Rchild == NULL) //node to be deleted has only left child
	{
		if (parent != NULL)
		{
			if (parent->Lchild == n)
			{
				parent->Lchild = n->Lchild;
			}
			else
			{
				parent->Rchild = n->Lchild;
			}
		}
		else //deleting root with left child
			root = n->Lchild; //update root

		delete n;
	}

	else if (n->Rchild != NULL && n->Lchild == NULL) //node to be deltedd has only right child
	{
		if (parent != NULL) //not deleting root
		{
			if (parent->Lchild == n)
			{
				parent->Lchild = n->Rchild;
			}
			else
			{
				parent->Rchild = n->Rchild;
			}
		}
		else //deleting root with right child
			root = n->Rchild; //update root

		delete n;
	}
	else //node to be deleted has both the children
	{
		//find the rightmost node in left subtree i.e predecessor of n
		treeNode* q = n->Lchild, * qparent = n;
		while (q->Rchild != NULL)
		{
			qparent = q;
			q = q->Rchild;
		}
		n->item = q->item;
		return remove(q, qparent);
	}


	return true;
}

bool BST::remove(int i)
{

	treeNode* p = root, * parent = NULL;
	while (p != NULL)
	{
		if (p->item == i)
			return remove(p, parent);

		parent = p;
		if (i < p->item)
		{
			p = p->Lchild;
		}
		else
		{
			p = p->Rchild;
		}
	}
	return false;
}
void BST::inorder(treeNode* n)
{
	if (n == NULL)
		return;

	inorder(n->Lchild);
	cout << n->item << " ";
	inorder(n->Rchild);

}

treeNode* BST::getRoot()
{
	return root;
}

int BST::max()
{
	if (root == NULL)
		return 0;
	else
	{
		treeNode* p = root;
		while (p->Rchild != NULL)
			p = p->Rchild;
		return p->item;
	}
}

//FUNCTIONS FOR TESTING
// Generate Random Data
vector<int> BST::generateRandomData(int size) {
	vector<int> data(size);
	mt19937 gen(std::random_device{}());
	uniform_int_distribution<int> dist(1, 100000);
	for (auto& val : data) val = dist(gen);
	return data;
}
void BST::testBSTInsertion(const vector<int>& data, const string& operationName) {
	auto start = chrono::high_resolution_clock::now();
	for (int num : data) {
		add(num); // Use add as a member function
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = end - start;

	cout << operationName << ": Inserted " << data.size() << " elements in " << elapsed.count() << " seconds.\n";
}
void BST::testDuplicateInsertion( const std::vector<int>& data) {
	auto start = chrono::high_resolution_clock::now();
	if (!data.empty()) {
		
		int duplicate = data[0]; // Use the first element as the duplicate
		std::cout << "Testing duplicate insertion...\n";
		if (add(duplicate)) {
			std::cout << duplicate << " added successfully.\n";
		}
		if (add(duplicate)) {
			std::cout << "Duplicate insertion failed as expected.\n";
		}
	}
	else {
		std::cout << "Data is empty, skipping duplicate insertion test.\n";
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double>  elapsed = end - start;

	cout <<  "Tested duplicate insertion " << data.size() << " elements in " << elapsed.count() << " seconds.\n";
}

void BST::testRemoveFromEmptyTree(const std::vector<int>& data) {
	std::cout << "Testing remove on an empty tree...\n";
	auto start = chrono::high_resolution_clock::now();

	BST emptyTree; // Create an empty BST
	bool result = emptyTree.remove(42); // Attempt to remove a node

	// Output the result
	cout << "Remove operation on empty tree: " << (result ? "Success" : "Failed as expected") << "\n";
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double>  elapsed = end - start;
	cout << "Test removing a node from an empty BST " << data.size() << " elements in " << elapsed.count() << " seconds.\n";

}

void BST :: testRemoveLeafNode(const std::vector<int>& data) {
	cout << "Testing removal of a node with no children (leaf node)...\n";
	auto start = chrono::high_resolution_clock::now();

	add(42); // Add a single node
	bool result = remove(42); // Remove the node

	// Output the result
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double>  elapsed = end - start;
	cout << "Remove operation for leaf node: " << (result ? "Success" : "Failed") << "\n";
	cout << "Test removing a node with no children (leaf node) " << data.size() << " elements in " << elapsed.count() << " seconds.\n";

	//UNCOMMENT THIS IF YOU WANT TO VIEW THE TREE
	// Verify the tree is empty after removal
	//cout << "Tree after removal: ";
	//inorder(getRoot());

	cout << "\n";
}

void BST:: testRemoveNodeWithOneChild(const std::vector<int>& data) {
	auto start = chrono::high_resolution_clock::now();
	std::cout << "Testing removal of a node with one child...\n";

	add(50); // Root node
	add(30); // Node with one child
	add(20); // Child of the node to be removed

	bool result = remove(30); // Remove the node with one child
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double>  elapsed = end - start;
	// Output the result
	cout << "Remove operation for node with one child: " << (result ? "Success" : "Failed") << "\n";
	cout << "Test removing a node with one child " << data.size() << " elements in " << elapsed.count() << " seconds.\n";

	//UNCOMMENT THIS IF YOU WANT TO VIEW THE TREE
	// Verify the tree structure after removal
	//cout << "Tree after removal: ";
	//inorder(getRoot());
	cout << "\n";
}

void BST :: testRemoveNodeWithTwoChildren(const std::vector<int>& data) {
	auto start = chrono::high_resolution_clock::now();
	cout << "Testing removal of a node with two children...\n";

	add(50); // Root node
	add(30); // Left child
	add(70); // Right child
	add(20); // Left subtree
	add(40); // Right subtree

	bool result = remove(30); // Remove the node with two children
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double>  elapsed = end - start;

	// Output the result
	cout << "Remove operation for node with two children: " << (result ? "Success" : "Failed") << "\n";
	cout << "Test removing a node from with two children " << data.size() << " elements in " << elapsed.count() << " seconds.\n";

	//UNCOMMENT THIS IF YOU WANT TO VIEW THE TREE
	// Verify the tree structure after removal
	//cout << "Tree after removal: ";
	//inorder(getRoot());
	cout << "\n";
}