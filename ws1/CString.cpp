// Name:  Artem Kulihina
// Seneca Student ID: 128516168
// Seneca email: akulihin@myseneca.ca
// Date of completion: 13.09.2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "CString.h"
#include <cstring>
#include <iostream>
using namespace std;

namespace w1
{
	CString::CString(char* c)
	{
		if (c != nullptr)
		{
			strncpy(stored_string_, c, max_size_stored);
			stored_string_[max_size_stored] = '\0';
		}
		else
		{
			stored_string_[0] = '\0';
		}
	}

	void CString::display(std::ostream& os) const
	{
		os << stored_string_;
	}

	std::ostream& operator<<(std::ostream& os, const CString& CSt)
	{
		static auto i = 0;
		cout << i++ << ": ";
		CSt.display(os);
		return os;
	}
}
