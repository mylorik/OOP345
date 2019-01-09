// Name: Artem Kulihina
// Seneca Student ID: 128516168
// Seneca email: akulihin@myseneca.ca
// Date of completion: 18.11.2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item
{
	std::string m_name;
	std::string m_description;
	unsigned int m_serialNumber;
	unsigned int m_quantity;
	unsigned int static m_widthField;

public:
	Item(std::string);
	const std::string &getName() const;
	const unsigned int getSerialNumber();
	const unsigned int getQuantity() const; // I think member function should be const in this case
	void updateQuantity();
	void display(std::ostream &os, bool full) const;
};

#endif // ITEM_H
