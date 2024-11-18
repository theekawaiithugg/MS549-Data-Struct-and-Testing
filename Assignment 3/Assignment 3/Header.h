#pragma once

using namespace std;

void bubbleSort(vector<int>& arr);

void partition(vector<int>& arr, int low, int high);

void quickSort(vector<int>& arr, int low, int high);

void popfrontsort(vector<int>& arr);

void testStdSort(const vector<int>& data);

void testSort(void (*sortFunc)(std::vector<int>&), std::vector<int> data, const std::string& algoName);

vector<int> generateRandomData(int size);
