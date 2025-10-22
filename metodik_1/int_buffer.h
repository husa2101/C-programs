//
// Created by shahr on 2024-02-11.
//

#ifndef UNTITLED_METODIK_LAB1_INT_BUFFER_H
#define UNTITLED_METODIK_LAB1_INT_BUFFER_H

/*
class int_buffer {
private:
    int bufferSize;
    int* valuePtr;
public :


    void swap(int_buffer& rhs);
    explicit int_buffer ( size_t size ) ; // size_t is defined in cstdlib
    int_buffer ( const int * source , size_t size ) ; // resize constructor
    int_buffer ( const int_buffer & rhs ) ; // copy construct
    int_buffer ( int_buffer && rhs ); // move construct
    int_buffer & operator =( const int_buffer & rhs ) ; // copy assign
    int_buffer & operator =( int_buffer && rhs ); //move assign
    int & operator []( size_t index ) ;
    const int & operator []( size_t index ) const ;
    size_t size () const ;
    int * begin () ;
    int * end () ;
    const int * begin () const ; // the difference between const and non const is that the const version ensure you that it will not change the state of a function.
    // it also means that if you have a const object with a type of the function then you have to use a const version of the function
    const int * end () const ;
    ~ int_buffer () ;




    //int_buffer() = default;
};
*/



#include <cstdlib>
class int_buffer {
private:

    int *buffer;
    size_t bufferSize;


public :
    explicit int_buffer ( size_t size ) ; // size_t is defined in cstdlib
    int_buffer ( const int * source , size_t size ) ;
    int_buffer ( const int_buffer & rhs ) ; // copy construct
    int_buffer ( int_buffer && rhs ) ; // move construct
    int_buffer & operator =( const int_buffer &rhs ) ; // copy assign
    int_buffer & operator =( int_buffer && rhs ) ;// move assign
    int & operator []( size_t index ) ;
    const int & operator []( size_t index ) const ;
    size_t size () const ;
    int * begin () ;
    int * end () ;
    const int * begin () const ;
    const int * end () const ;
    ~ int_buffer () ;
    void swap(int_buffer &rhs);
};


#endif //UNTITLED_METODIK_LAB1_INT_BUFFER_H
