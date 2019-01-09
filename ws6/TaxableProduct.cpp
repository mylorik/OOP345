// Name:  Artem Kulihina
// Seneca Student ID: 128516168
// Seneca email: akulihin@myseneca.ca
// Date of completion: 02.11.2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iomanip>
#include "TaxableProduct.h"

namespace w6
{
	const static std::array<double, 2> tax_rates = {HST, PST};

	TaxableProduct::TaxableProduct(const std::string& product_number, const double product_cost, const char tax_code) : Product(
		product_number, product_cost)
	{
		switch (tax_code)
		{
		case'H':
			tax_type_ = "HST";
			// I could say just "tax_rate_ = HST" as I have "HST" declared in my .h file, but we asked to use class array, in this case completely useless
			// we do not have a class for prices or taxes itself 
			tax_rate_ = std::get<0>(tax_rates);
			break;
		case'P':
			tax_type_ = "PST";
			tax_rate_ = std::get<1>(tax_rates);
			break;
		default:
			tax_type_ = "invalid";
			tax_rate_ = 0;
		}
	}

	double TaxableProduct::getPrice() const
	{
		return Product::getPrice() * tax_rate_;
	}

	void TaxableProduct::display(std::ostream& os) const
	{
		Product::display(os);
		os << std::setw(4) << tax_type_;
	}
}