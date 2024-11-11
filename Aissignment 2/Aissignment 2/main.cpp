#include <iostream>
#include <cstring>
#include <string>
#include <cassert>
#include <chrono> 
#include "functions.h"

using namespace std;

int main() {
	//Variables used for testing
	string wordl;
	int arr[] = { 1,2,3,4,5 };

	// This first chunk is for Pointers
	cout << "First I would like to test if we can reverse a string using pointers.." << endl;

	auto startHigh = std::chrono::high_resolution_clock::now(); // Timing for reverseString assertions

	assert(reverseString("Alexis") == "sixelA");
	assert(reverseString("Hello") == "olleH");
	assert(reverseString("Alexis Martinez") == "zenitraM sixelA");


	auto endHigh = std::chrono::high_resolution_clock::now(); //End of Timing
	std::chrono::duration<double> elapsed = endHigh - startHigh;
	//Ouput for user
	cout << "All program tests passed!" << endl;
	cout << "Time taken by reverseString tests: " << elapsed.count() << " seconds" << endl;
	
	//This is just for fun as a user input
	cout << "please give me one more to try!" << endl;
	getline(cin, wordl);
	string reversedWord = reverseString(wordl);
	cout << reversedWord << " ,Thank you!" << endl;
	cout << "Second I would like to test if we can count a sum using recursion.." << endl;
	
	//This second point is for recursion
	auto startHigh2 = std::chrono::high_resolution_clock::now();     // Timing for sumArray assertions
	assert(sumArray(arr,0) == 0); // Sum of an empty range
	assert(sumArray(arr, 1) == 1); // Sum of first element
	assert(sumArray(arr, 2) == 3); // Sum of first two elements (1 + 2)
	assert(sumArray(arr, 5) == 15); // Sum of all elements (1 + 2 + 3 + 4 + 5)
	auto endHigh2 = std::chrono::high_resolution_clock::now();    //End of Timing
	std::chrono::duration<double> elapsed2 = endHigh2 - startHigh2;
	
	//Ouput for user
	cout << "All program tests passed!" << endl;
	cout << "Time taken by sumArray tests: " << elapsed2.count() << " seconds" << endl;

	return 0;

}