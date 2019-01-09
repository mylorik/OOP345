// Name: Artem Kulihina
// Seneca Student ID: 128516168
// Seneca email: akulihin@myseneca.ca
// Date of completion: 2018-10-12
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Grades.h"
#include <fstream>
#include <string>

namespace sict
{
	Grades::Grades(const char* file)
	{
		std::fstream fs;
		std::string n_line;
		unsigned int line_count = 0;

		fs.open(file);

		if (fs.fail())
		{
			student_number = nullptr;
			student_number_grade = nullptr;
			number_of_lines = 0;

			throw "Booo! Can't open the file";
		}
		while (getline(fs, n_line))
		{
			line_count++;
		}

		fs.close();

		this->number_of_lines = line_count;
		this->student_number = new std::string[number_of_lines];
		this->student_number_grade = new double[number_of_lines];

		fs.open(file);

		line_count = 0;

		while (getline(fs, n_line))
		{
			if (n_line.find(' ') == std::string::npos)
			{
				throw "Boole... npos";
			}

			const auto index = n_line.find(' ');
			this->student_number[line_count] = n_line.substr(0, index);

			n_line = n_line.substr(index + 1, n_line.length());
			this->student_number_grade[line_count] = stod(n_line);

			line_count++;
		}
	}
}
