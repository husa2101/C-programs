//
// Created by shahr on 2024-11-25.
//

#include "person.h"


void print(std::vector<PersonInfo> container){
    for (auto it = container.begin(); it != container.end(); it++) {
        std::cout << "User found:\n";
        std::cout << ", Name: " << it->fullname << "\n"
                    << ", e-mail: " << it->ePost << "\n"
                  << ", Phone Number: " << it->phoneNumber << "\n"
                  << ", Security Number: " << it->securityNumber <<"\n"
                  << ", Address: " << it->address << "\n\n";
    }
}

std::string str_tolower(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return std::tolower(c); } // correct
    );
    return s;
}

void UserRegistretion (PersonInfo person, std::ofstream & output, std::vector<PersonInfo>& container){
    std::string name, copy_name
    , COPY_EPOST, COPY_ADDRESS,
    e_post1, address_1;
    while(true){
        std::cout << "please enter fullname:  ";
        std::getline(std::cin, name);
        copy_name = str_tolower(name);

        person.fullname = copy_name;

        stringType type = input_analys(person.fullname);
        if (type == isAlphabetic)
            break;

        else std::cout << "Invalid input. Only alphabetic characters allowed. Try again.\n";
    }


    std::cout << "please enter your security number:  ";
    std::getline(std::cin, person.securityNumber);


    std::cout << "please enter the phone number:";
    std::getline(std::cin, person.phoneNumber);

    std::cout << "please enter your e-post:  ";
    std::getline(std::cin, COPY_EPOST);
    e_post1 = str_tolower(COPY_EPOST);
    person.ePost = e_post1;

    std::cout << "please enter your address :  ";
    std::getline(std::cin, COPY_ADDRESS);
    address_1 = str_tolower(COPY_ADDRESS);
    person.address = address_1;


    //std::cout<< std::endl;

    output << person.fullname <<"\n"
            << person.securityNumber <<"\n"
            << person.ePost << "\n"
            << person.phoneNumber <<
            "\n" << person.address << std::endl;

    container.push_back(person);
    for(auto it: container){
        if (person.fullname == it.fullname){
            std::cout << it.fullname << std::setw(3) <<"User is registered." << std::endl;
        }else{
        std::cout << " User registeration failed." << std::endl;
        }
    }

}

bool search_input_analys(std::string input, PersonInfo person){
    if (person.fullname.find(input) != std::string::npos){
        return true;
    }else if (person.phoneNumber.find(input) != std::string::npos){
        return true;
    }else if(person.address.find(input) != std::string::npos){
        return true;
    }else if(person.securityNumber.find(input) != std::string::npos){
        return true;
    }else if(person.ePost.find(input) != std::string::npos){
        return true;
    }else{
        return false;
    }


}
void search_User(std::string &userInput,  std::vector<PersonInfo> &container)
{
    bool B_search;
    std::string name = str_tolower(userInput);

    bool found = 0;

        for (auto it : container)
        {
           B_search = search_input_analys(name, it);

            if (B_search == true && !container.empty())
            {
                std::cout << "User found:\n";
                std::cout << "Name: " << it.fullname
                          << ", Phone Number: " << it.phoneNumber
                          << ", Security Number: " << it.securityNumber
                          << ", Address: " << it.address << "\n";
                found = true;
            }else{
                break;
            }
        }


    if(!found)
        std::cout << "No User found matching the input" << std::endl;
}





void delete_user(const std::string& username, std::vector<PersonInfo> & container){
    bool found = true;

    for (auto it = container.begin(); it != container.end(); ) {
        if (it->fullname == username){
            found = true;
            std::cout << " User: " << it->fullname << " has been found and will be deleted " << std::endl;
            container.erase(it);
            break;
        }else{
            it++;
            found = false;
        }
    }

    if(!found){
        std::cout << " This user not exist " << std::endl;
    }
}



stringType evaluate(const char &ch){
    if(std::isdigit(static_cast<unsigned char>(ch))) return isNumeric;
    if (isalpha(static_cast<unsigned char>(ch))) return isAlphabetic;
    return other;
}

stringType input_analys(std::string input){
    int isalpha = 0, isint = 0, others = 0;

    int pos = input.find(' ');
    std::string Fname = input.substr(0, pos);
    std::string Lname = input.substr(pos + 1, input.size());

    for (auto ch: Fname) {
        switch (evaluate(ch)) {
            case isAlphabetic:
                isalpha++;
                break;
            case isNumeric:
                isint++;
                break;
            case other:
                others++;
                break;
        }
    }
    for (auto ch1: Lname) {
        switch (evaluate(ch1)) {
            case isAlphabetic:
                isalpha++;
                break;
            case isNumeric:
                isint++;
                break;
            case other:
                others++;
                break;
        }
    }

    if (isint == 0 && others == 0 && isalpha > 0)
        return isAlphabetic;
    else
        return other;
}