
// Content of the header file


#include "int_buffer.h"
#include <iostream>
#include <algorithm>

// parameter constructor
int_buffer::int_buffer(size_t size): bufferSize(size), valuePtr(new int[size]) {}


// a constructor that take a copy of already existed array / resize constructor
int_buffer::int_buffer(const int *source, size_t size): int_buffer(size) { // delegating the task to other constructor
    std::copy(source, source+size, valuePtr);   // make a copy from that space to our self / from the source
}


// copy constructor djup copy
int_buffer::int_buffer(const int_buffer &rhs): int_buffer(rhs.valuePtr, rhs.bufferSize){ // delegating the task -> source and size -> to other constructor that has one parameter
    //valuePtr = new int[(rhs.bufferSize)];
    //bufferSize = rhs.bufferSize;
    std::copy(rhs.begin(), rhs.end(), begin());
}


// move constructor
int_buffer::int_buffer(int_buffer &&rhs) noexcept {
    if(this != &rhs) // avoid self assigment
    valuePtr = rhs.valuePtr;
    bufferSize = rhs.bufferSize;   // take over the resources
    rhs.valuePtr =  nullptr; // leave in  a state in which it is safe to run a destructor
    }


// assigment operator
int_buffer &int_buffer::operator=(const int_buffer &rhs) {
    int_buffer copy = int_buffer(rhs);
    std::swap(*this, copy); // the interesting about this technique is that it automatically handles self assignment and is
    // automatically exception safe. by copying the right-hand operand before changing the left-hand operand it handles self assignment
    //in the same way we did our original assignment operator


    /*if(this != &rhs){ // We check for self-assignment to avoid unnecessary work.
        free(valuePtr); //We deallocate any existing resources (if any) using delete[] to prevent memory leaks.

   this->bufferSize = rhs.bufferSize;
   this->valuePtr = new int[bufferSize]; // We allocate new memory and copy data from rhs
   std::copy(rhs.valuePtr, rhs.valuePtr + bufferSize, valuePtr); // The function returns the current instance to support chaining assignments.
    */
    return *this;
}


// move assigment operator

// to support move operation, the new standard introduced a new kind of reference a rvalue reference. is a reference that must be bound
// to a rvalue reference is obtained by using && rather than &.
// we are free to move resources from a rvalue references to another object.
// recall that lvalue och rvalue are properties of an expression. some expression yield or require lvalues : other require rvalues.
// generally speaking lvalue refers to an objects identity whereas a rvalue refers to value of an object.
// revalue is another name for objects
int_buffer &int_buffer::operator=(int_buffer &&rhs) noexcept {
    //std::swap(*this, rhs);
    if(this!=&rhs){
        this->valuePtr = rhs.valuePtr;
        this->bufferSize = rhs.bufferSize;
        rhs.valuePtr = nullptr; // leave rhs in a state in which it is safe to run the destructor
    }
    return *this;
}


// return a value of a specific value
int &int_buffer::operator[](size_t index) {
    if(index < bufferSize || index > bufferSize){
        return valuePtr[index];
    }else{
        throw std::out_of_range("out of range");
    }
}


// return a value of a specific value
const int &int_buffer::operator[](size_t index) const {
    if(index < bufferSize || index > bufferSize){
        return valuePtr[index];
    }else{
        std::throw_with_nested("out of range");
    }
}


int *int_buffer::begin() {
    return valuePtr;
}


int *int_buffer::end() {
    return valuePtr + bufferSize;
}


const int *int_buffer::begin() const {
    return valuePtr;
}


const int *int_buffer::end() const {
    return valuePtr + bufferSize;
}


int_buffer::~int_buffer() {

        delete[] valuePtr;
}


size_t int_buffer::size() const {
    return bufferSize;
}


// void f() witch print out amount of the buffer indexes
void f(int_buffer buf) {

    int count = 0;

    for (auto it: buf)  {
        count += 1;
        it = count;

        std::cout << it << " ";
    }
/*
    for (int *i = buf.begin(); i != buf.end(); i++) {
        count += 1;
        *i = count;
    }

    for (const int *i = buf.begin(); i != buf.end(); i++) {
        std::cout << *i << " ";
    }
    */
std::cout<< "\n";

}

void int_buffer::insert(  int value) {

        *valuePtr = value;
}







