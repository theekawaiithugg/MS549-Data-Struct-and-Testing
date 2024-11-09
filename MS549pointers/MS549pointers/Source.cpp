#include<iostream>
#include<memory>

using namespace std;

int main()
{

	int n1 = 42;
	int* n1ptr = &n1; //this is declaring the pointer as the information

	cout << "n1ptr = " << n1ptr;
	cout << "n1ptr = " << *n1ptr;

	int n2 = 53;
	int* n2ptr;
	n2ptr = n1ptr; // this is using the previous pointer line 15 does not get called at all

	cout << "n2ptr = " << n2ptr;
	cout << "n2ptr* = " << *n2ptr;

	int total = 0;
	total = *n2ptr + *n1ptr; // this should give 84
	cout << "total = " << total;

	int scores[4] = { 97,5,85,79 };
	for (int i = 0; i < 4; i++) 
	{
		cout << "scores at " << i << " is " << *(scores + i) << endl;
	}
}// if given an array of strings it the for loop would no to jump an integers length in bites 
// this is the same for doubles