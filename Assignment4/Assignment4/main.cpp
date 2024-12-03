#include <iostream>
#include <ctime>
#include <chrono>
#include <vector>
#include <algorithm>
#include <random>

#include "functions.h"


using namespace std;

int main() 
{
	vector<int> dataSizes = { 100, 1000, 10000};

	for (int size : dataSizes) {
		vector<int> data = generateRandomData(size);
		// Test Doubly Linked List Insertion
		testLinkedListInsertion(data, "Doubly Linked List Insertion");
		printList("Stack Contents After Insertion");
		//Test Pop Back
		testPopBack("PopBack Test");
		printList("Stack Contents After PopFront");
		//Test Queue insertion
		testinsertback(data, "Queue Insertion");
		printList("Queue Contents After Insertion");
		// Test Pop Front
		testPopFront("PopFront Test"); 
		printList("Queue Contents After PopBack");
		
	}
	return 0;
}