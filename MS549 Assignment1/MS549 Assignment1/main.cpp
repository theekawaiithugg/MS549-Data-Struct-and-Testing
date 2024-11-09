#include <iostream>
#include <string>
#include "functions.h"
using namespace std;

int main()
{
	
	bool notDone = true;
	while (notDone)
	{
		int option = menu();

		if (option == 1)
		{
			int num1;
			cout << "Please input a whole number... " << endl;
			cin >> num1;
			isitEvenTest(num1);
		}
		else if (option == 2)
		{
			int numf;
			cout << "Enter a non-negative integer: " << endl;
			cin >> numf;
			calcFac(numf);
		}
		else
		{
			notDone = false;// this will exit out of the loop for any number besides 1 and 2.
		}
	}
	return 0;
}