// Name:  Artem Kulihina
// Seneca Student ID: 128516168
// Seneca email: akulihin@myseneca.ca
// Date of completion: 02.11.2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Product.h"
#include <iomanip>

namespace w6
{
	Product::Product(const std::string& product_number, const double product_cost)
	{
		this->product_number_ = product_number;
		this->product_cost_ = product_cost;
	}

	double Product::getPrice() const
	{
		return product_cost_;
	}

	void Product::display(std::ostream& os) const
	{
		os << std::setw(16) << product_number_ << std::setw(16) << product_cost_;
	}
}