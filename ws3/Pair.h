// Name: Artem Kulihina
// Seneca Student ID: 128516168
// Seneca email: akulihin@myseneca.ca
// Date of completion: 28.09.2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#ifndef PAIR_H
#define PAIR_H
#include <string>

template<typename A, typename B>
class Pair {
    A key;
    B value;

    public:
        Pair() : key{0}, value{0} {}
        Pair(const A& a, const B& b) : key{a}, value{b} {}

        const A& getKey() const {
            return key;
        }

        const B& getValue() const {
            return value;
        }
};

#endif //PAIR_H