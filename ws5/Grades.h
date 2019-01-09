// Name: Artem Kulihina
// Seneca Student ID: 128516168
// Seneca email: akulihin@myseneca.ca
// Date of completion: 2018-10-12
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SICT_GRADES_H
#define SICT_GRADES_H

#include <iostream>
#include <iomanip>
#include "Letter.h"

namespace sict
{
	class Grades
	{
		std::string* student_number;
		double* student_number_grade;
		size_t number_of_lines;

	public:
		explicit Grades(const char*);

		Grades(const Grades&) = delete;
		Grades(Grades&&) = delete;
		Grades& operator=(const Grades&) = delete;
		Grades&& operator=(Grades&&) = delete;

		template <typename F>
		void displayGrades(std::ostream& os, F letter) const
		{
			for (size_t i = 0; i < number_of_lines; i++)
			{
				int round_grade = letter(student_number_grade[i]);
				const auto student_letter_grade = grade_converter(round_grade);

				os << std::setw(10) << std::right << student_number[i] << " "
					<< std::setw(5) << std::right << std::fixed << std::setprecision(2) << student_number_grade[i] <<
					" " << std::setw(4) << std::left << student_letter_grade << std::endl;
			}
		}
	};
}
#endif // SICT_GRADES_H
