// Name:  Artem Kulihina
// Seneca Student ID: 128516168
// Seneca email: akulihin@myseneca.ca
// Date of completion: 05.10.2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include <fstream>
#include <string>
#include "Message.h"

using namespace w4;

Message::Message(std::ifstream& in, char c)
{
	auto check = 0;
	std::string msg;
	getline(in, msg, c);

	check = msg.find_first_of(' ');
	if (check != -1)
	{
		user_m_.assign(msg.substr(0, check));
		msg.erase(0, check + 1);

		if (msg.find('@') == 0)
		{
			check = msg.find_first_of(' ');
			reply_m_.assign(msg.substr(1, check - 1));
			msg.erase(0, check + 1);
		}

		tweet_m_.assign(msg);
	}
}

bool Message::empty() const
{
	return (user_m_.empty() && tweet_m_.empty() && reply_m_.empty());
}

void Message::display(std::ostream& os) const
{
	if (!empty())
	{
		os << "Message" << std::endl << " User  : " << user_m_ << std::endl;

		if (!reply_m_.empty())
			os << " Reply : " << reply_m_ << std::endl;

		os << " Tweet : " << tweet_m_ << std::endl;
	}
}
