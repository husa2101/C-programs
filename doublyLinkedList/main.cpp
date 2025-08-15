#include <iostream>
#include"linked_list.h"


int main() {
    linked_list list;
    linked_list list2, list4;

    list.insert(4, 0);
    list.insert(5, 1);
    list.insert(6, 2);
    list.insert(7, 3);
    list.insert(8, 4);
    list.insert(9, 5);
    list.insert(11, 6);
    list.insert(22, 7);

    list2.insert(10, 0);
    list2.insert(20, 1);
    list2.insert(30, 2);
    list2.insert(40, 3);
    list2.insert(50, 4);
    list2.insert(60, 5);

   /* linked_list list3(list2);
    list4 = list;


    list.push_back(99);
    list.push_front(100);
    list.pop_front();
    list.pop_back();

    list2 += list;



    list2.print();
    std::cout << "\n\n" <<std::endl;
    //list3.print();
    //std::cout << "\n\n" <<std::endl;
    //list4.print();
    std::cout << "the front value is:"<<std::setw(3)
    << list.front() << "\n" << "and the back value is: "
    <<std::setw(3)<< list.back()<< "\n"<< std::endl;

    std::cout << "the size of the liist is: "<< list2.size() << "\n"<< std::endl;
    std:: cout << " the pos has a value: " << list.at(3) << std::endl;
   list2.print();

   list2.remove(2);
   std::cout << "\n\n";

   list2.print();
    std::cout << "\n\n";
   bool bol = list4.is_empty();
    if(bol){
        std::cout << "the is not empty" << std::endl;
    }else
        std::cout << "the list is empty" << std::endl;
    */
    linked_list margelist;
     margelist = list2.marge(list, list2);

    margelist.print();


    return 0;
}