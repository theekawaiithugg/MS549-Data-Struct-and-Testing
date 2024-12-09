#include <iostream>
#include <vector>
#include "functions.h"
#include <string>
#include <unordered_map>
#include <algorithm> // For std::find
#include <random>
#include <functional> // For std::hash
#include <optional>



using namespace std;

int main()

{
	// Create a HashTable instance with 1000 buckets
	HashTable hashTable(1000);

	// Define data sizes for testing
	vector<int> dataSizes = { 100, 1000, 10000,100000 };
	for (int size : dataSizes) 
	{
		//Create random Data for instertion
		vector<int> data = hashTable.generateRandomData(size);
	
		hashTable.testInsertion(data, "Insertion");
		int randomInRange = rand() % 100; // Random number between 0 and 99
		hashTable.testRetrieve(data, randomInRange, "Retrival");
		hashTable.testdeleteData(data, randomInRange, "Deletion");
	}

	cout << "Now for Testing built in hash table" << endl;

	for (int size : dataSizes)
	{
		//Create random Data for instertion
		vector<int> data = hashTable.generateRandomData(size);

		hashTable.BtestInsertion(data, "Insertion");
		int randomInRange = rand() % 100; // Random number between 0 and 99
		hashTable.BtestRetrieve(data, randomInRange, "Retrival");
		hashTable.BtestdeleteData(data, randomInRange, "Deletion");
	}

	
	return 0;
}