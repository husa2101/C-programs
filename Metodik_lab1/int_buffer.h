
#ifndef INT_BUFFER_H
#define INT_BUFFER_H

#include <iostream>
#include <vector>
#include<stdlib.h>


class int_buffer {
private:
    int bufferSize{};
    int* valuePtr{};
public :


    explicit int_buffer ( size_t size ) ; // size_t is defined in cstdlib
    int_buffer ( const int * source , size_t size ) ;
    int_buffer ( const int_buffer & rhs ) ; // copy construct
    int_buffer ( int_buffer && rhs )  noexcept ; // move construct
    int_buffer & operator =( const int_buffer & rhs ) ; // copy assign
    int_buffer & operator =( int_buffer && rhs )  noexcept ; //move assign
    int & operator []( size_t index ) ;
    const int & operator []( size_t index ) const ;
    size_t size () const ;
    int * begin () ;
    int * end () ;
    const int * begin () const ; // the difference between const and non const is that the const version ensure you that it will not change the state of a function.
    // it also means that if you have a const object with a type of the function then you have to use a const version of the function
    const int * end () const ;
    ~ int_buffer () ;
    friend void f(int_buffer buff);
    void insert( int);



};


#endif // INT_BUFFER_H