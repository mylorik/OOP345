// Name: Artem Kulihina
// Seneca Student ID: 128516168
// Seneca email: akulihin@myseneca.ca
// Date of completion: 2018-10-12
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SICT_LETTER_H
#define SICT_LETTER_H

namespace sict
{
	enum Letter { AA, A, BB, B, CC, C, DD, D, F };

	template <typename T>
	const char* grade_converter(const T& letter)
	{
		switch (letter)
		{
		case AA:
			return "A+";
		case A:
			return "A";
		case BB:
			return "B+";		
		case B:
			return "B";		
		case CC:
			return "C+";		
		case C:
			return "C";	
		case DD:
			return "D+";	
		case D:
			return "D";	
		default:
			return "F";		
		}
	}
}

#endif // SICT_LETTER_H
