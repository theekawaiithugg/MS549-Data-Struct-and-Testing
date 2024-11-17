#include <iostream>
#include <cstring>
#include <array>
#include <chrono> 

using namespace std;



string reverseString(string wordl) {
    // this is a pointer that is a char type labeled start that is assigned the 1st array point of the string
    char* start = &wordl[0]; // Pointer to the beginning of the string
    //wordl.size allows for any number of spaces in the wordl string array
    char* end = &wordl[0] + wordl.size() - 1; // Pointer to the end of the string

    while (start < end) {
        // Swap characters at start and end
        char replace = *start;
        *start = *end;
        *end = replace;
        // Move pointers towards each other
        start++;
        end--;
    }
    return wordl;
}

int sumArray(int Clist[], int Counts) {
    int sum = 0;

    if (Counts <= 0) {

        //sum = Clist[0];
        return 0;
    } else { for (int i = 0; i < Counts; i++) {
            sum += Clist[i];

        }
        return sum;
    }
}

int RsumArrayR(int Clist[], int Counts) {
    int sum = 0;

    if (Counts <= 0) {
        return sum = 0;
    }
    else
    {
        for (int i = 0; i < Counts; i++) 
        {
            return sum = Clist[Counts-1] + RsumArrayR(Clist, Counts - 1);
        }
    }
}