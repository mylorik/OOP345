// Name: Artem Kulihina
// Seneca Student ID: 128516168
// Seneca email: akulihin@myseneca.ca
// Date of completion: 16.11.2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace w8
{

List<Product> mergeRaw(const List<Description> &desc, const List<Price> &price)
{
    List<Product> priceList;
    // TODO: Add your code here to build a list of products
    //         using raw pointers
    
    for (size_t i = 0; i < desc.size(); ++i)
        for (size_t j = 0; j < price.size(); ++j)
        {
            if (desc[i].code == price[j].code)
            {
                auto *raw_ptr = new Product(desc[i].desc, price[j].price);
                raw_ptr->validate();
                priceList += raw_ptr;
                delete raw_ptr;
                raw_ptr = nullptr;
                break;
            }
        }

    return priceList;
}

List<Product> mergeSmart(const List<Description> &desc, const List<Price> &price)
{
    List<Product> priceList;
    // TODO: Add your code here to build a list of products
    //         using smart pointers

    for (size_t i = 0; i < desc.size(); ++i)
        for (size_t j = 0; j < price.size(); ++j)
        {
            if (desc[i].code == price[j].code)
            {
                std::unique_ptr<Product> sma_ptr(new Product(desc[i].desc, price[j].price));
                sma_ptr->validate();
                priceList += sma_ptr;
                break;
            }
        }

    return priceList;
}
} // namespace w8