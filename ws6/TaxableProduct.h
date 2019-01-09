// Name:  Artem Kulihina
// Seneca Student ID: 128516168
// Seneca email: akulihin@myseneca.ca
// Date of completion: 02.11.2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#ifndef W6_TAXABLEPRODUCT_H
#define W6_TAXABLEPRODUCT_H
#include "Product.h"
#include <array>

namespace w6
{
	const double HST = 1.13; 
	const double PST = 1.08;

	class TaxableProduct : public Product
	{
		std::string tax_type_;
		double tax_rate_;

	public:
		TaxableProduct(const std::string&, double, char);
		double getPrice() const override;
		void display(std::ostream&) const override;
	};
}

#endif //W6_TAXABLEPRODUCT_H