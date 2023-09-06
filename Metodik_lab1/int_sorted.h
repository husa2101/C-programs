//
// Created by shahr on 2023-08-23.
//

#ifndef METODIK_LAB1_INT_SORTED_H
#define METODIK_LAB1_INT_SORTED_H
#include<ctime>
#include<random>
#include "int_buffer.h"
#include <algorithm>



 class int_sorted {
    explicit int_sorted(int_buffer  buffer);

    int_buffer buffer;
public :

    int_sorted(const int *source, size_t size);

    [[nodiscard]] size_t size() const;

    int *insert(int value);

    [[nodiscard]] const int *begin() const;

    [[nodiscard]] const int *end() const;

    int_sorted merge ( const int_sorted &merge_with ) const ;
    [[nodiscard]] bool isSort() const;
    static int randomIntGenerator(int n);
    int_sorted() = default;    // here we are saying that default constructor, copy and assigned constructor does not need implementation.
    //int_sorted() = delete;    // here we are saying that the default constructor does not exist in an explicit way.
   // saying to compiler that the definition of this constructor does not exist and give me one by default and also under any
   // circumstances do not implement any constructor.
    int_sorted sort(const int* begin, const int* end);
};



#endif //METODIK_LAB1_INT_SORTED_H
