// Name:  Artem Kulihina
// Seneca Student ID: 128516168
// Seneca email: akulihin@myseneca.ca
// Date of completion: 13.09.2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#pragma once
#include <iostream>

namespace w1
{
	const int max_size_stored = 3;

	class CString
	{
		char stored_string_[max_size_stored + 1]{};
	public:
		CString(char*);
		void display(std::ostream&) const;
	};

	std::ostream& operator<<(std::ostream&, const CString&);
}
