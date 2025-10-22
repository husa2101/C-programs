#include <iostream>
#include "int_buffer.h"
#include "int_sorted.h"


std::ostream & operator << (std::ostream& out, int_buffer bff);
void f(int_buffer buf);
std::ostream & operator << (std::ostream & out, const int_sorted& sort);
int random();


int main() {

int_buffer buff(10);
    f(buff);



    int list[8]{1,4,7,9,6,45,23,0};
    int_buffer parameterConstructor(list, 8);
    //std::cout << parameterConstructor;


    int_buffer copyConstructor(parameterConstructor);
    //std::cout << copyConstructor;

    /*The buff6 object will inherit the size and buffer pointer from the buffer object after the move operation.
     However, since the move constructor
    doesn't explicitly set a default size, the default size of buff6 would depend on the size of the buffer object before the move. */
    int_buffer moveConstructor(std::move(copyConstructor));   // flytta ägerskap av obj objektet till moveContractor med hjälp av nya objektens pekare
   // std::cout << moveConstructor;

   int_buffer tilldelningsConstructor(10);
  // tilldelningsConstructor = moveConstructor;
   //td::cout << tilldelningsConstructor;

    // Create two int_buffer objects, buffer1 and buffer2
    int_buffer buffer0(10);// Assume int_buffer has a constructor that takes size
  //int_buffer buffer2(10);

    // Perform move assignment from buffer2 to buffer1
    buffer0 = std::move(tilldelningsConstructor);
    //std::cout << buffer0;

    int_buffer container(6);
// Tilldela värden till elementen med operator[]
    for (size_t i = 0; i < 6; ++i) { // Ändrade till < 6 för att matcha storleken på containern
        container[i] = i * 10;
    }

// Använd operator[] för att få tillgång till elementen och skriv ut dem
    std::cout << container[5] << " array value " << std::endl; // Använder operator syntaxen




std::cout << "-------------  int_sorted ---------------------" << std::endl;
    int list1[8]{56,14,7,9,6,45,23,11};
for(auto it : list1){
    std::cout << it << " ";
}
    std::cout << " " << std::endl;


int_sorted sort(list1, 8);


std::cout << sort;


    bool sortet = sort.isSort();
    if(sortet){
        std::cout<< "true it is sortet \n\n";
    }else{
        std::cout << "false it is not sortet \n\n";
    }


    int num = random();
    std::cout<<  " random int : "<< num << std::endl;
    sort.insert(num);
    std::cout << sort << " ";


    return 0;
}









std::ostream & operator << (std::ostream & out, int_buffer bff){
    for(int *i = bff.begin(); i != bff.end(); i++ ){
        out << "Adress: " << i << "\t\t"<<"Value: " << *i << std::endl;
    }
    return out;
}

std::ostream & operator << (std::ostream & out, const int_sorted& sort){
    for(auto i = sort.begin(); i != sort.end(); i++ ){
        out << "Address: " << i << "Value: "<< *i << std::endl;
    }
    return out;
}


// void f() witch print out amount of the buffer indexes
void f(int_buffer buf) {

    int count = 0;
    for (int *i = buf.begin(); i != buf.end(); i++) {
        count += 1;
        *i = count;
    }

    for (const int *i = buf.begin(); i != buf.end(); i++) {
        std::cout << *i << " ";
    }

    std::cout<< "\n";

}

int random(){
    std::random_device ed;
    std::mt19937 gen(ed());
    std::uniform_int_distribution<int>destribution(0, 50);
    int random= destribution(gen);

    return random;
}