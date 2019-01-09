// Workshop 5 - Lambda Expression
// 345_w5.cpp
// Chris Szalwinski & Dr. Elliott Coleshill
// 2018-08-22

// Name: Artem Kulihina
// Seneca Student ID: 128516168
// Seneca email: akulihin@myseneca.ca
// Date of completion: 2018-10-12
//
// I confirm that the content of this file is created by me, 
// with the exception of the parts provided to me by my professor.


#include <iostream>
#include "Grades.h"
#include "Letter.h"
using namespace sict;

int main(int argc, char* argv[])
{
	std::cout << "Command Line: ";
	for (int i = 0; i < argc; i++)
		std::cout << argv[i] << ' ';
	std::cout << std::endl;

	if (argc == 1)
	{
		std::cerr << "\n*** Insufficient number of arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 1;
	}
	if (argc != 2)
	{
		std::cerr << "\n*** Too many arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 2;
	}

	//TODO: Update the main functions as per the specifications here
	const auto letter = [](const double grade)
	{
		if (grade >= 90) { return AA; }
		if (grade >= 80) { return A;  }
		if (grade >= 75) { return BB; }
		if (grade >= 70) { return B;  }
		if (grade >= 65) { return CC; }
		if (grade >= 60) { return C;  }
		if (grade >= 55) { return DD; }
		if (grade >= 50) { return D;  }
		return F;
	};

	try
	{
		Grades grades(argv[1]);
		grades.displayGrades(std::cout, letter);
	}
	catch (const char* msg)
	{
		std::cerr << "oh my shark! This is an error: " << msg << std::endl;
	}

	return 0;
}
