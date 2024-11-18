#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <cstdlib>

#include "Header.h"

using namespace std;

int main() 
{
	vector<int> dataSizes = { 100, 1000, 10000, 100000 };

	for (int size : dataSizes) {
		vector<int> data = generateRandomData(size);// Generate data FOR SPECIFIC SIZE


		testSort(bubbleSort, data, "Bubble Sort");
		testSort(popfrontsort, data, "Pop Front Sort");
		testStdSort(data);


    }

	return 0;

}