// Name: Artem Kulihina
// Seneca Student ID: 128516168
// Seneca email: akulihin@myseneca.ca
// Date of completion: 18.11.2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include "Utilities.h"
#include <complex.h>

char Utilities::m_delimiter;

void Utilities::setFieldWidth(size_t widthField)
{
	m_widthField = widthField;
}

size_t Utilities::getFieldWidth() const
{
	return m_widthField;
}


const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
{
	const auto new_pos = str.find(getDelimiter(), next_pos);
	auto token = str.substr(next_pos, new_pos - next_pos);

	more = new_pos != std::string::npos;

	if (new_pos == next_pos)
	{
		std::string err = "ERROR - two delimiters with no token between them";
		throw err;
	}

	if (token.length() > getFieldWidth())
	{
		this->setFieldWidth(token.length());
	}

	next_pos = new_pos + 1u;

	return token;
}

void Utilities::setDelimiter(const char delimiter)
{
	m_delimiter = delimiter;
}

const char Utilities::getDelimiter() const
{
	return m_delimiter;
}
