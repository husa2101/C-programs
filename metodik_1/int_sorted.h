//
// Created by shahr on 2024-02-16.
//

#ifndef UNTITLED_METODIK_LAB1_INT_SORTED_H
#define UNTITLED_METODIK_LAB1_INT_SORTED_H
#include<ctime>
#include<random>
#include "int_buffer.h"
#include <algorithm>



class int_sorted {
private:

    int_buffer buffer;

public :

    int_sorted(const int *source, size_t size);

    size_t size() const;

    void insert(int value);

    const int *begin() const;

    const int *end() const;

    int_sorted merge ( const int_sorted &merge_with ) const ;
    bool isSort() ;
    int_sorted() = default;

    int_sorted sort(const int* begin, const int* end);
};


#endif //UNTITLED_METODIK_LAB1_INT_SORTED_H
