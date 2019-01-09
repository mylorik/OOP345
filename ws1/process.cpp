// Name:  Artem Kulihina
// Seneca Student ID: 128516168
// Seneca email: akulihin@myseneca.ca
// Date of completion: 13.09.2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "process.h"
#include "CString.h"
#include <iostream>

namespace w1
{
	void process(char* c, std::ostream& os)
	{
		const CString CString_obj(c);
		os << CString_obj << std::endl;
	}
}
