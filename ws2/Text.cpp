// Name: Artem Kulihina
// Seneca Student ID: 128516168
// Seneca email: akulihin@myseneca.ca
// Date of completion: 21.09.2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include <fstream>
#include "Text.h"
#include <string>

namespace w2
{
	Text::Text()
	{
		m_string_ = nullptr;
		m_size_ = 0;
	}

	Text::Text(const std::string& filepath)
	{
		std::ifstream file(filepath);

		if (!file.is_open())
		{
			m_string_ = nullptr;
			m_size_ = 0;
			return;
		}

		auto size = 0;
		std::string check;

		while (!file.fail())
		{
			getline(file, check);
			size++;
		}

		file.clear();
		file.seekg(0, std::ios::beg);

		m_size_ = size;
		m_string_ = new std::string[size];

		for (auto i = 0; i < size + 1; i++)
			getline(file, m_string_[i]);

		file.close();
	}

	//a copy constructor
	Text::Text(const Text& obj)
	{
		*this = obj;
	}

	//a copy assignment operator
	Text& Text::operator=(const Text& obj)
	{
		if (this == &obj)
			return *this;

		delete[] m_string_;

		m_size_ = obj.m_size_;
		m_string_ = new std::string[m_size_];

		for (auto i = 0; i < m_size_; i++)
			m_string_[i] = obj.m_string_[i];

		return *this;
	}

	// a move constructor
	Text::Text(Text&& obj) noexcept
	{
		*this = std::move(obj);
	}

	//a move assignment operator
	Text& Text::operator=(Text&& obj) noexcept
	{
		if (this == &obj)
			return *this;

		delete[] m_string_;

		m_size_ = obj.m_size_;
		m_string_ = obj.m_string_;
		obj.m_string_ = nullptr;

		return *this;
	}

	Text::~Text()
	{
		delete[] m_string_;
		m_string_ = nullptr;
	}

	size_t Text::size() const
	{
		return m_size_;
	}
}
