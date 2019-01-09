// Name: Artem Kulihina
// Seneca Student ID: 128516168
// Seneca email: akulihin@myseneca.ca
// Date of completion: 28.09.2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef LIST_H
#define LIST_H

template<typename T, int N>
class List {
    T array[N];
    int currentSize; 

    public:
        List() : currentSize{0} {}
    
        size_t size() const {
            return currentSize;
        }

        const T& operator[](int index) const {
            return array[index];
        }

        void operator+=(const T& element ) {
            if (currentSize < N) {
                array[currentSize] = element ;
                currentSize++;
            }
        }
};

#endif //LIST_H