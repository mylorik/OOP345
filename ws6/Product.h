// Name:  Artem Kulihina
// Seneca Student ID: 128516168
// Seneca email: akulihin@myseneca.ca
// Date of completion: 02.11.2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W6_PRODUCT_H
#define W6_PRODUCT_H
#include "iProduct.h"
#include <iostream>
#include <string>

namespace w6
{
	class Product : public iProduct
	{
		double product_cost_;
		std::string product_number_;
	public:
		Product(const std::string&, double);
		double getPrice() const override;
		void display(std::ostream& os) const override;
	};
}

#endif //W6_PRODUCT_H