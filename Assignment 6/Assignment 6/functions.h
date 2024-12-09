#pragma once
#include <iostream>
#include <cstdlib>
#include <list>
#include <algorithm> // For std::find
#include <optional>
#include <unordered_map>

#include <vector>
#include <chrono>
#include <string>

using namespace std;

class HashTable
{
	int numkeys;
	list<int>* hashT;
	unordered_map<int, int> hashTable; // For built-in operations (Phase 3)


public:
	HashTable(int numkeys);
	void insertData(int data);
	int hashKey(int data);
	void displayHashTable();
	bool findValue(int data);
	int* deleteData(int data);
	vector<int> generateRandomData(int size);
	int* retrieve(int data);

	void testInsertion(const vector<int>&data, const string & operationName);
	void testRetrieve(const vector<int>&data, int want, const string & operationName);
	void testdeleteData(const vector<int>& data, int want, const string& operationName);
	
	void BinsertData(int key);
	int* Bretrieve(int key);
	int* BdeleteData(int key);

	void BtestInsertion(const vector<int>& data, const string& operationName);
	void BtestRetrieve(const vector<int>& data, int want, const string& operationName);
	void BtestdeleteData(const vector<int>& data, int want, const string& operationName);



	};

