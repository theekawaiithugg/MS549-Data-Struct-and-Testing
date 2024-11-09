#include <iostream>
#include <string> //not sure if i need this for the future
#include "functions.h"

using namespace std;

int menu()
{
	int choice;
	cout << " Menue options" << endl;
	cout << "1. Test for even or odd numbers." << endl;
	cout << "2. Calculate a Factorial." << endl;
	cout << "3. Exit." << endl;
	cin >> choice;
	return choice;
}

void isitEvenTest(int num1)
{//testing if the input is an even or odd number
	// i decided to use the module becuase it gives the remaineder of the number after being divded.
	if (num1 % 2 == 0)
	{
		cout << num1 << " is an even number!" << endl;
	}
	else if (num1 % 2 ==! 0)
	{
		cout << num1 << " is an odd number!" << endl;
	}
	else
	{
		cout << "I am not sure what is hapening... something is wrong." << endl;
	}
}

void calcFac(int numf) 
{//calculating a factorial
	if (numf < 0) {
		cout << "Factorial is not defined for negative numbers." << endl;
		return;
	}
	int factorial = 1;
	for (int i = 1; i <= numf; ++i) 
	{
		factorial *= i;
	}
	cout << "Factorial of " << numf << " is " << factorial << endl;
}

void exit();