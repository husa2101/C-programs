//
// Created by shahr on 2024-02-16.
//

#include "int_sorted.h"
#include <utility>


// paramatisade constructor
int_sorted::int_sorted(const int *source, size_t size) : buffer(source,size) {
    if(size > 1){

        *this = sort(source, source+size); //The result of the sorting operation is assigned back to the current object (*this).

    }
}


size_t int_sorted::size() const {
    return buffer.size();
}


void int_sorted::insert(int value) {

    int_buffer tempCont(buffer.size() + 1); // create a temp container with one more place for the mew element
    auto insert_point = tempCont.begin();
    *insert_point = value;
    insert_point++;
    auto buff_begin = buffer.begin();

    while(buff_begin != buffer.end()){    // while they are not empty

            *insert_point = *buff_begin++;
            insert_point++;
    }

    std::sort(tempCont.begin(), tempCont.end());
    buffer = std::move(tempCont);

}


const int *int_sorted::begin() const {
    return buffer.begin();
}


const int *int_sorted::end() const {
    return buffer.end();
}

bool int_sorted::isSort(){
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



/* this fucntion is a recursive function which is based on devide and concur meaning first the devide the array in half more
 * and more untill there is only one element left in each part which is done by sort() function and then merge the result of
 * the sort() fucntion and sort it along the way */
int_sorted int_sorted::sort(const int* begin, const int* end) {

    // base case check that the container is not empty
    if (begin == end)
        return int_sorted(nullptr, 0);

    // base case check if the conainter only have one element
    if (begin == end - 1)
        return int_sorted(begin, 1);

// std::ptrdiff_t is the signed integer type of the result of subtracting two pointers.
    ptrdiff_t half = (end - begin) / 2;
    const int* mid = begin + half;
    return sort(begin, mid).merge(sort(mid, end));  // merge the left and right side

}


int_sorted int_sorted::merge(const int_sorted &merge_with) const {


    int_buffer IntBuffer(size() + merge_with.size());

    auto sort_it = IntBuffer.begin(); // where to start the insertion to the container
    auto lhs_it = buffer.begin();   // the start location within the new buffer
    auto rhs_it = merge_with.begin();    // start location within the existed buffer

    // Merge the two arrays into the buffer
    while(lhs_it != buffer.end() && rhs_it != merge_with.end()){    // while they are not empty

        if(*lhs_it < *rhs_it){
            // if the value inside the first position inside the lhs is less then rhs
            *sort_it = *lhs_it++;                       // then add it to the container and go to the next
            sort_it++;// point to the next index in the container as start location

        }else{
            // if the value from right hand side into the buffer
            *sort_it = *rhs_it++; // add the value that it point to and go to the next one

            sort_it++; // go to the next position

        }
    }

    /*After the while loop, there might be remaining elements either in the current object's buffer or the buffer of the merge_with object.
     * Two separate while loops are used to add these remaining elements to the IntBuffer.Add remaining elements from left array*/
    while(lhs_it != buffer.end()){

        *sort_it = *lhs_it++;
        sort_it++;

    }

    // Add remaining elements from right array
    while (rhs_it != merge_with.end()){

        *sort_it = *rhs_it++;
        sort_it++;
    }
    /*since the return value is int_sorted and the container that has the sorted element is int_buffer, so we have to change the
     * typ to intsorted inorder to return */

    int_sorted buff(nullptr, 0);
    buff.buffer = std::move(IntBuffer);
    return buff;

}
