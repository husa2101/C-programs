#include <iostream>
#include "gussAnNumber.h"

int main() {

    gussAnNumber g;

    int num;
    bool flag = true;

    while (flag) {

        std::cout << "guss a number\n";

        if (!(std::cin >> num)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << std::endl << "intvalid input! Please enter a number.\n";
            continue;
        }
            if(num < 1) {
                flag = false;
                std::cout << "Googbye\n";
            }
            else if(num == g.getSecretNumber()) {
                std::cout << "you guss is right\n";
               std::cout << "click enter to guess a number again\n";
                std::cin.ignore(1000, '\n');
                std::cin.get();
                g.reset();

            }
            else if(num < g.getSecretNumber()) {
                std::cout << "you guss is to low\n";
            }
            else {
                std::cout << "you guss is to high \n";
            }
    }


    return 0;
}
