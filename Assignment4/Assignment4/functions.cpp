#include <iostream>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <vector>
#include <random>

#include "functions.h"


using namespace std;
// Node structure for Doubly Linked List
//This will allow us to go front and to go backwards not in a loop
struct node {
	int num;
	node* prev; //THE NUMBER BEFORE US
	node* next; // THE NUMBER AFTER US
};
node* head = NULL; // Global pointer for the linked list head
node* current = NULL;


// These first two functions are specifically for implelmenting a stack of a doubley linked list.
void insert(int newNum)
{    // Insert a node at the appropriate place

	struct node* newnode = new node;

	if (head == NULL)
	{
		head = newnode;
		newnode->num = newNum;
		newnode->next = NULL;
		newnode->prev = NULL;
	}
	else
	{
		newnode->num = newNum;
		newnode->next = head;
		head->prev = newnode;
		head = newnode;
		newnode->prev = NULL;
	}
}
// navigating to the end of the list
void popBack()
{
	if (head == nullptr) {
		cout << "No data in linked list" << endl;
		return;
	}
	if (head->next == nullptr) {
		delete head; // If only one node, delete it and reset head
		head = nullptr;
		return;
	}
	node* tail = head;
	while (tail->next != nullptr) {
		tail = tail->next;
	}
	tail->prev->next = nullptr;
	delete tail; // Free memory of the removed node
}

//THE NEXT TWO FUNCTIONS ARE FOR A QUEUE OF A DOUBLEY LINKED LIST
//
void insertBack(int newNum) {
	node* newNode = new node;
	newNode->num = newNum;  // Initialize the num field or else I get the garbage value number -842150451
	newNode->next = nullptr;

	if (head == nullptr) {
		newNode->prev = nullptr;
		head = newNode;
	}
	else {
		node* tail = head;
		while (tail->next != nullptr) {
			tail = tail->next;
		}
		tail->next = newNode;
		newNode->prev = tail;
	}
}
void popFront()
{ //first check if we have anything to remove
	if (head == nullptr) {
		cout << "No data in linked list" << endl;
		return;
	}
	node* temp = head;
	head = head->next;
	if (head != nullptr) {
		head->prev = nullptr;
	}
	delete temp; // Free memory of the removed node
}





// FUNCTIONS FOR TESTING 

// Function to test doubly linked list insertion performance
void testLinkedListInsertion(const vector<int>& data, const string& operationName) {
	auto start = chrono::high_resolution_clock::now();
	for (int num : data) {
		insert(num);
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = end - start;

	cout << operationName << ": Inserted " << data.size() << " elements in " << elapsed.count() << " seconds.\n";
}
void testPopFront(const string& operationName) {
	if (head == nullptr) {
		cout << operationName << ": No data to pop, linked list is empty." << endl;
		return;
	}

	auto start = chrono::high_resolution_clock::now();

	while (head != nullptr) {
		popFront();
	}

	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = end - start;

	cout << operationName << ": Removed all elements in " << elapsed.count() << " seconds.\n";
}
void testPopBack(const string& operationName) {
	if (head == nullptr) {
		cout << operationName << ": No data to pop, linked list is empty." << endl;
		return;
	}

	auto start = chrono::high_resolution_clock::now();

	while (head != nullptr) {
		popBack();
	}

	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = end - start;

	cout << operationName << ": Removed all elements in " << elapsed.count() << " seconds.\n";
}

void testinsertback(const vector<int>& data, const string& operationName) {
	auto start = chrono::high_resolution_clock::now();
	for (int num : data) {
		insertBack(num);
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = end - start;

	cout << operationName << ": Inserted " << data.size() << " elements in " << elapsed.count() << " seconds.\n";
}
// FUNCTIONS FOR TESTING 
// Performance Testing
void testSort(void (*sortFunc)(std::vector<int>&), std::vector<int> data, const std::string& algoName) {
	auto start = std::chrono::high_resolution_clock::now();
	sortFunc(data);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	cout << algoName << ": " << data.size() << " elements sorted in " << elapsed.count() << " seconds." << endl;
}

// Generate Random Data
vector<int> generateRandomData(int size) {
	vector<int> data(size);
	mt19937 gen(std::random_device{}());
	uniform_int_distribution<int> dist(1, 100000);
	for (auto& val : data) val = dist(gen);
	return data;
}

void printList(const string& operationName) {
	if (head == nullptr) {
		cout << operationName << ": The list is empty." << endl;
		return;
	}

	cout << operationName << ": ";
	node* current = head;
	while (current != nullptr) {
		cout << current->num << " ";
		current = current->next;
	}
	cout << endl;
}