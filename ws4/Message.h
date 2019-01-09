// Name:  Artem Kulihina
// Seneca Student ID: 128516168
// Seneca email: akulihin@myseneca.ca
// Date of completion: 05.10.2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W4_MESSAGE_H
#define W4_MESSAGE_H

#include <iostream>
#include <fstream>
#include <string>

namespace w4
{
	class Message
	{
		std::string user_m_;
		std::string reply_m_;
		std::string tweet_m_;

	public:
		Message(std::ifstream& in, char c);
		bool empty() const;
		void display(std::ostream&) const;
	};
}

#endif // end W4_MESSAGE_H
