/**
 * Labb 05, dt047g HT2023
 * @author Hussein Salehi
 * @date 2024-03-26
 * @brief The STL vector container, function objects
 */

#include <iostream>
#include "email.h"


template<typename T>
void display(const std::vector<T>& emails) {
    for (const auto& it: emails) {
        std::cout << "emails: " << it << "\n";
    }
}

int main() {


   Email e("hussein", "2024,03,14", "labTest1");
   Email em("aman", "2022,06,14", "labTest2");
   Email ema("rena", "2014,03,03", "labTest3");
   Email emai("erik", "2025,03,30", "labTest5");
   Email email("wiliam", "2012,02,23", "labTest4");

   MailBox email1;
   email1.addEmail(e);
   email1.addEmail(em);
   email1.addEmail(ema);
   email1.addEmail(emai);
   email1.addEmail(email);

   email1.sortWho();
   std::cout<< "\n\n";
    std::cout <<"sorting based on the lexicographical order\n";
   display(email1.getEmail());

   email1.sortDate();
   std::cout<< "\n\n";
    std::cout <<"sorting based on the chronological order\n";
   display(email1.getEmail());

   email1.sortSubject();
   std::cout<< "\n\n";
    std::cout <<"sorting based on the lexicographical order\n";
   display(email1.getEmail());



}

