// Workshop 1 - Linkage, Storage Duration, Namespaces,
// and OS Interface
// w1.cpp
// Author: Dr. Elliott Coleshill
// Date: 2018-08-22

// Name:  Artem Kulihina
// Seneca Student ID: 128516168
// Seneca email: akulihin@myseneca.ca
// Date of completion: 13.09.2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include <fstream>
#include "process.h"

using namespace std;

// TODO: Declare (without defining) the global variable
// you have defined in CString.cpp
using namespace w1;
#include "CString.h" // I know that it should be beside all others "include" 


int main(int argc, char* argv[])
{
    cout << "Command Line: ";
    for (int i = 0; i < argc; i++)
    {
        cout << argv[i] << ' ';
    }
    if (argc < 2)
    {
        cout << "\nInsufficient number of arguments\n";
        return 1;
    }

	// TODO: Add code here that will print out max characters
    // stored by your CString object

	cout << "\nMaximum number of characters stored: " << max_size_stored <<"\n";

    for (int i = 1; i < argc; i++)
    {
	    process(argv[i], cout);
    }

    return 0;
}