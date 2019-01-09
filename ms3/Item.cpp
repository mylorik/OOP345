// Name: Artem Kulihina
// Seneca Student ID: 128516168
// Seneca email: akulihin@myseneca.ca
// Date of completion: 18.11.2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include "Item.h"
#include "Utilities.h"
#include <iomanip>
#include <iostream>

unsigned int Item::m_widthField;

Item::Item(std::string str)
{
	Utilities utilities;
	bool more = true;
	size_t next_pos = 0u;


	m_name = utilities.extractToken(str, next_pos, more);
	m_serialNumber = std::stoi(utilities.extractToken(str, next_pos, more));
	m_quantity = std::stoi(utilities.extractToken(str, next_pos, more));
	m_widthField = utilities.getFieldWidth();
	m_description = utilities.extractToken(str, next_pos, more);
}

const std::string& Item::getName() const
{
	return m_name;
}

const unsigned int Item::getSerialNumber()
{
	return m_serialNumber++;
}

const unsigned int Item::getQuantity() const
{
	return m_quantity;
}

void Item::updateQuantity()
{
	if (m_quantity > 0)
	{
		m_quantity--;
	}
}

void Item::display(std::ostream& os, bool full) const
{
	os << std::setw(m_widthField) << std::left << getName() << " ["
		<< std::setw(6) << std::right << std::setfill('0') << m_serialNumber << std::setfill(' ') << "]";

	if (full)
		os << " Quantity: " << std::setw(m_widthField) << std::left << getQuantity() << " Description: " <<
			m_description;

	os << std::endl;
}
