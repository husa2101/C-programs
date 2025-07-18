#include "person.h"
#include<iostream>
#include<algorithm>
#include<vector>


//void print(const char& s) {  // Accept std::string
 //   std::cout << s;
//}



int main() {



    //td::string name = "adam salehi";
    //std::for_each(name.cbegin(), name.cend(), print);
        Person person1;
    std::ifstream input;
    bool control = true;
    int num;
    std::string userInput,  name;
    std::vector<Person> findPersons;
    size_t numberOfP;

    input.open("names.txt");

    if(!input.is_open())
        std::cerr << "unable to open the file";

    std::vector<Person> persons = read_input(input);
    input.close();



    while(control){
        if(num >= 2){
            control = false;
        }

        std::cout << "click 1 to search a user, click 0 to exit the program " << std::endl;
        std::cin >> num;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "std::cin fail restart the program " << std::endl;
            continue;
        }


        switch (num) {
            case 1:
                std::cin.ignore();
                std::cout << "type the name you are looking for\n";
                std::getline(std::cin, userInput);
                name = strTolower(userInput);
                findPersons  = search(persons, name);
                numberOfP = findPersons.size();
                std::cout << "the number of the people found is: " << numberOfP << "\n\n\n";
                std::for_each(findPersons.begin(), findPersons.end(), print);
                break;

            case 0:
                std::cin.ignore();
                std::cout << "good bye" << std::endl;
                control = false;
                return 0;

            default:
                std::cout << "invalid input try igen" << std::endl;
                break;

        }
    }

    return 0;
}
