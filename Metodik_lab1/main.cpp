#include "int_buffer.h"
#include "int_sorted.h"
#include<array>

std::ostream & operator << (std::ostream& out, int_buffer bff);
std::ostream & operator << (std::ostream & out, int_sorted sort);


int main() {
    f(int_buffer(10));
    std::cout << "------------------------------" << std::endl;
    int_buffer buffer(10);
    int_buffer buff(buffer); // direct initialization copy constructor
    int_buffer buffer1{buff}; // invoke the copy  constructor " uniform initialization"
    std::cout << buffer1;
    std::cout << "---------------------\n\n";
    //int_buffer buffer2 = buffer1; // invoke copy constructor operator
    int list[6]{12, 4, 9, 0, 45, 7};
    int_buffer buff4(list,6);  // resize the buffer container
    int_buffer buff5 = buff4;    // invoke assignment operator
    std::cout << buff5 << "\n\n" << "move constructor" << "\n";// use ostream overloading operator
    // here buff5 exist in a correct but unrecognized state
    int_buffer buff6 = std::move(buff5);  // convert the object to rvalue && and take over the resource
    std::cout << buff6 << "\n\n";

    int_buffer hussein(buff6.begin(), buff6.size());
    int index = 1;
     int n = hussein.operator[](index);        // using the static member of the clas to output the specific index of the class
   std::cout <<"The required index of " << index <<" is: "<< n;
    std::cout <<"\n-------------------------------" <<"\nsort class\n\n";



    int_sorted sort(list,7);//using resize() to change the size of buffer in int_buffer
    int_sorted buffer9 = sort;
    bool sortet = buffer9.isSort();
    if(sortet){
        std::cout<< "true it is sortet \n\n";
    }else{
        std::cout << "false it is not sortet \n\n";
    }
    //std::cout << buffer9;


    int_sorted sortbuffer(buffer9.begin(), buffer9.size());
    int num = sortbuffer.randomIntGenerator(10);
    std::cout<<  " random int : "<< num << std::endl;
    int *i = sortbuffer.insert(num);
    std::cout << "Insertet number Address : " << i << "  and value: " <<  *i << "\n\n section: 3 \n\n" ;

    std::cout << sortbuffer;



    return 0;
}



std::ostream & operator << (std::ostream & out, int_buffer bff){
    for(int *i = bff.begin(); i != bff.end(); i++ ){
        out << "Adress: " << i << "\t\t"<<"Value: " << *i << std::endl;
    }
    return out;
}

std::ostream & operator << (std::ostream & out, int_sorted sort){
    for(auto i = sort.begin(); i != sort.end(); i++ ){
        out << "Address: " << i << "Value: "<< *i << std::endl;
    }
}