//
// Created by shahr on 2024-02-11.
//

#include <stdexcept>
#include "int_buffer.h"
#include "algorithm"

 int_buffer::int_buffer( size_t size ):buffer(new int[size]), bufferSize(size) {

}


//Konstruktorn används för att skapa en ny int_buffer-instans och fylla den med värden från en befintlig array av heltal
int_buffer::int_buffer(const int *source, size_t size): int_buffer(size) {

    std::copy(source, source+size , buffer);  // kopiera innehållet av den gammla objektet till den nya antingen me denna eller for loop

}


// Den funktionen int_buffer::int_buffer(const int_buffer &rhs) är en kopieringskonstruktor för klassen .
// Denna konstruktor används för att skapa en ny instans av int_buffer genom att kopiera innehållet från en befintlig instans rhs.
int_buffer::int_buffer(const int_buffer &rhs):int_buffer(rhs.buffer, rhs.bufferSize) {


   //bufferSize = rhs.bufferSize;
   //buffer = new int[bufferSize];

    //for (int i = 0; i < bufferSize; ++i) {
      //  buffer[i] = rhs[i];
    //}
    //this->bufferSize = bufferSize;
}

// kopiering flyttkonstruktor för klassen int_buffer i C++. Denna konstruktor används för att skapa en ny instans av int_buffer genom att
// "stjäla" resurserna från en annan instans rhs.  flyttar bara pekaren från en insats till den nya
int_buffer::int_buffer(int_buffer &&rhs) {
    bufferSize = rhs.bufferSize;
    buffer =rhs.buffer;
    rhs.bufferSize= 0;
    rhs.buffer = nullptr;  //Förhindra att destruktorn frigör samma minne flera gånger eller dubble avslutning
}


// kopiering Tilldelningsoperator för att kopiera innehållet från en annan int_buffer
int_buffer &int_buffer::operator=(const int_buffer &rhs) {


        int_buffer temp = int_buffer(rhs);
        swap(temp);


   return *this;
}

// Move assignment operator som tilldelar ägarskapet av ett objekt till ett annat objekt istället för att tilldela värdet.
// Detta innebär att den nya objektet endast pekar på den gamla objektets tillgångar, men inte kopierar dem.
int_buffer& int_buffer::operator=(int_buffer&& rhs){
    swap(rhs);
    return *this;
}

int &int_buffer::operator[](size_t index) {

    if(index <= bufferSize){
        return buffer[index];
    }else{
        throw std::out_of_range("out of range");
    }
}

const int &int_buffer::operator[](size_t index) const {

    if (index < bufferSize){
        return buffer[index];
    }else{
        throw std::out_of_range("out of range");
    }
}

int *int_buffer::begin() {
    return buffer;
}

int *int_buffer::end() {
    return buffer + bufferSize;
}

const int *int_buffer::begin() const {
    return buffer;
}

const int *int_buffer::end() const {
    return buffer + bufferSize;
}

// Destruktor för att frigöra minnet när objektet går ut ur omfånget
int_buffer::~int_buffer() {
    delete[] buffer;  // Frigör minnet som allokerats för buffern
    //std::cout << "dectructor invoks" << std::endl;
}

void int_buffer::swap(int_buffer &rhs) {
    std::swap(buffer, rhs.buffer); // Byt pekare till buffertar med rhs
    std::swap(bufferSize, rhs.bufferSize);     // Byt storlekar med rhs
}

size_t int_buffer::size() const {
    return bufferSize;
}
