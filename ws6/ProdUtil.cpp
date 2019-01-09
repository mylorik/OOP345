// Name:  Artem Kulihina
// Seneca Student ID: 128516168
// Seneca email: akulihin@myseneca.ca
// Date of completion: 02.11.2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#include <string>
#include <cctype>
#include "ProdUtil.h"
#include "Product.h"
#include "TaxableProduct.h"

namespace w6
{
	std::ostream& operator<<(std::ostream& os, const iProduct& src)
	{
		src.display(os);
		return os << std::endl;
	}

	iProduct* readProduct(std::ifstream& ifs)
	{
		char c = ifs.peek();
		if (c != EOF && c != '\n')
		{
			std::string product_number;
			double product_price;

			ifs >> product_number >> product_price;
			ifs.ignore();
			c = ifs.peek();

			if (std::isalpha(c))
			{
				ifs.ignore(256, '\n');

				if (c == 'H' || c == 'P')
					return new TaxableProduct(product_number, product_price, c);

				std::string error = "Unrecognizable Tax Code!";
				throw error;
			}
			return new Product(product_number, product_price);
		}
		return nullptr;
	}
}
