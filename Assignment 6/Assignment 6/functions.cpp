#include <iostream>
#include "functions.h"
#include <cstdlib>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm> // For std::find
#include <random>
#include <functional> // For std::hash
#include <optional>


using namespace std;


HashTable::HashTable(int numkeys)
{
	this->numkeys = numkeys;
	hashT = new list<int>[numkeys];
}

int HashTable::hashKey(int data)
{
	return data % this->numkeys;
}
// these are all functions for Phase 1 and Phase 2 using Seperate Chaning as how we handle collisions
void HashTable::insertData(int data)
{
	int dataKey = hashKey(data);
	hashT[dataKey].push_back(data);
}

void HashTable::displayHashTable()
{
	for (int i = 0; i < numkeys; i++)
	{
		cout << i;
		for (auto x : hashT[i])
		{
			cout << "-->  " << x;

		}
		cout << "\n";
	}

}

bool HashTable::findValue(int data)
{
	int dataKey = hashKey(data);
	bool found = false;
	list<int>::iterator i;
	i = hashT[dataKey].begin();
	while (!found && i != hashT[dataKey].end())
	{
		if (*i == data)
		{
			return true;
		}
		else
		{
			i++;
		}
	}
	if (i != hashT[dataKey].end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int* HashTable::retrieve(int data)
{
	int dataKey = hashKey(data);
	auto i = hashT[dataKey].begin(); // Get iterator to the bucket's list
	while (i != hashT[dataKey].end())
	{
		// Assuming each element in the list is a pair of <key, value>
		if (*i == data) // Compare the value
		{
			return &(*i); // Return address of the value
		}
		++i;
	}
	return nullptr; // Return null if key is not found
}


int*  HashTable::deleteData(int data)
{
	int dataKey = hashKey(data);
	auto i = hashT[dataKey].begin();
	while (i != hashT[dataKey].end())
	{
		// Assuming each element in the list is a pair of <key, value>
		if (*i == data) // Compare the value
		{
			return &(*i); // Return address of the value
		}
		++i;
	}
	return nullptr; // Return null if key is not found

}



//FUNCTIONS FOR TESTING
// Generate Random Data
vector<int> HashTable:: generateRandomData(int size) {
	vector<int> data(size);
	mt19937 gen(std::random_device{}());
	uniform_int_distribution<int> dist(1, 100000);
	for (auto& val : data) val = dist(gen);
	return data;
}

void HashTable :: testInsertion(const vector<int>& data, const string& operationName) {
	auto start = chrono::high_resolution_clock::now();
	for (int num : data) {
		insertData(num); // Use add as a member function
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = end - start;

	cout << operationName << ": Inserted " << data.size() << " elements in " << elapsed.count() << " seconds.\n";
}

void HashTable::testRetrieve(const vector<int>& data, int want, const string& operationName) {
	auto start = chrono::high_resolution_clock::now();
	
	int* result = retrieve(want); // Call retrieve to find the value for the key
	
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = end - start;

	cout << operationName << ": Inserted " << data.size() << " elements in " << elapsed.count() << " seconds.\n";
}

void HashTable::testdeleteData(const vector<int>& data, int want, const string& operationName) {
	auto start = chrono::high_resolution_clock::now();

	int* result = deleteData(want); // Call retrieve to find the value for the key

	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = end - start;

	cout << operationName << ": Inserted " << data.size() << " elements in " << elapsed.count() << " seconds.\n";
}

//These are all functions for phase 1 and 2

//FUNCTIONS FOR BUILT IN ITEMS
void HashTable::BinsertData(int key) {
	hashTable[key] = key; // Insert into the unordered_map
}
// Retrieve the value associated with a key
int* HashTable:: Bretrieve(int key) {
	auto i = hashTable.find(key); // Use find to locate the key
	if (i != hashTable.end()) {
		return &(i->second); // Return address of the value
	}
	return nullptr; // Key not found
}

// Delete a key-value pair
int* HashTable:: BdeleteData(int key) {
	auto erased = hashTable.erase(key); // Erase from unordered_map
	return erased > 0 ? &key : nullptr; // Return non-null if deleted
}
void HashTable::BtestInsertion(const vector<int>& data, const string& operationName) {
	auto start = chrono::high_resolution_clock::now();
	for (int num : data) {
		BinsertData(num); // Use add as a member function
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = end - start;

	cout << operationName << ": Inserted " << data.size() << " elements in " << elapsed.count() << " seconds.\n";
}

void HashTable::BtestRetrieve(const vector<int>& data, int want, const string& operationName) {
	auto start = chrono::high_resolution_clock::now();

	int* result = Bretrieve(want); // Call retrieve to find the value for the key

	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = end - start;

	cout << operationName << ": Inserted " << data.size() << " elements in " << elapsed.count() << " seconds.\n";
}

void HashTable::BtestdeleteData(const vector<int>& data, int want, const string& operationName) {
	auto start = chrono::high_resolution_clock::now();

	int* result = BdeleteData(want); // Call retrieve to find the value for the key

	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = end - start;

	cout << operationName << ": Inserted " << data.size() << " elements in " << elapsed.count() << " seconds.\n";
}