#include <iostream>
#include <vector>
#include <chrono> 
#include <random>
#include <algorithm>


#include "Header.h"
using namespace std;

// Bubble Sort
// Bubble Sort Algorithm: Repeatedly swaps adjacent elements when they are in the wrong order
// We sort the array in ascending order
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) { // Loop through the array 
        for (int j = 0; j < n - i - 1; ++j) { // Compare adjacent elements
            if (arr[j] > arr[j + 1]) { 
                swap(arr[j], arr[j + 1]);//This swaps them into the correct order
            }
        }
    }
}


// Pop Front Sort: Sorts a vector by repeatedly removing the smallest element
void popfrontsort(vector<int>& arr) {
    vector<int> sorted; // hodling vector 
    while (!arr.empty()) { // ! is the logical not symbol
        auto minIt = min_element(arr.begin(), arr.end());// Find the smallest element 
        sorted.push_back(*minIt);// Append smallest to holding vector
        arr.erase(minIt); // remove the appended element
    }
    // return sorted array with  -> return sorted; 
    arr = sorted; // it does not need to be here for the sorting but it does need to exist to allow the testSort function to read how many elements it oges through
    return;
}
// Function to test  buil in sort
void testStdSort(const vector<int>& data) {
    vector<int> dataCopy = data; // Make a copy of the data to keep the original unchanged
    auto start = std::chrono::high_resolution_clock::now();
    sort(dataCopy.begin(), dataCopy.end()); 
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << "Built in Sort: " << data.size() << " elements sorted in " << elapsed.count() << " seconds." << endl;
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