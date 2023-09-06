//
// Created by hussein on 2023-08-23.
//

#include "int_sorted.h"

#include <utility>


// paramatisade constructor
int_sorted::int_sorted(const int *source, size_t size) : buffer(source,size) {
    if(size > 1){
        *this = sort(source, source+size);
    }
}
int_sorted::int_sorted(int_buffer buffer): buffer(std::move(buffer)){

}
size_t int_sorted::size() const {
    return buffer.size();
}

int* int_sorted::insert(int value) {
    //auto it = std::lower_bound(buffer.begin(), buffer.end(), value);
    //*this = int_sorted(&value, 1);
    buffer.insert(value);
    return  std::find(buffer.begin(), buffer.end(), value);
}


const int *int_sorted::begin() const {
    return buffer.begin();
}


const int *int_sorted::end() const {
    return buffer.end();
}

bool int_sorted::isSort() const {
    auto it = begin();
    int a = *it++;
    while (it != end()){
        int b = *it++;
        if (a > b) {
            return false;
        }
        a = b;

    }
    return true;
}




int int_sorted::randomIntGenerator(int n) {
    std::uniform_int_distribution u (0,n);
    std::random_device e;
    //std::default_random_engine e;
    //e.seed(time(0));
    int i = u(e);
    return i;
}




int_sorted int_sorted::sort(const int* begin, const int* end) {
    if (begin == end)
        return int_sorted(nullptr, 0);

    if (begin == end - 1)
        return int_sorted(begin, 1);

    ptrdiff_t half = (end - begin) / 2; //pointer diff type
    const int* mid = begin + half;
    return sort(begin, mid).merge(sort(mid, end));

}




int_sorted int_sorted::merge(const int_sorted &merge_with) const {

    size_t cont_Size = merge_with.size() + buffer.size();  // make the size of the container that will contain bode rhs and lhs buffer
    int_buffer IntBuffer(cont_Size);       // make an empty container with that size


    auto sort_it = IntBuffer.begin(); // where to start the insertion to the container
    auto lhs_it = buffer.begin();   // the start location within the new buffer
    auto rhs_it = merge_with.begin();    // start location within the existed buffer


    while(lhs_it != buffer.end() && rhs_it != merge_with.end()){    // while they are not empty

        if(*lhs_it < *rhs_it){
            // if the value inside the first position inside the lhs is less then rhs
            *sort_it = *lhs_it++;                       // then add it to the container and gåo to the next
            sort_it++;// point to the next index in the container as start location

        }else{

            *sort_it = *rhs_it++;
            sort_it++;

        }
    }

    while(lhs_it != buffer.end()){

        *sort_it = *lhs_it++;
        sort_it++;

    }
    while (rhs_it != merge_with.end()){

        *sort_it = *rhs_it++;
        sort_it++;
    }

    return int_sorted(IntBuffer);
}




