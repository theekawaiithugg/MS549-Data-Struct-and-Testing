#include <iostream>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <vector>

#include <random>


using namespace std;
#pragma once

void insert(int newNum);
void popFront();
void popBack();
void insertBack(int newNum);

void testSort(void (*sortFunc)(std::vector<int>&), std::vector<int> data, const std::string& algoName);
void testLinkedListInsertion(const vector<int>& data, const string& operationName);
void testPopFront(const string& operationName);
void testPopBack(const string& operationName);
void testinsertback(const vector<int>& data, const string& operationName);
void printList(const string& operationName);


vector<int> generateRandomData(int size);