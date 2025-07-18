//
// Created by shahr on 2025-01-15.
//

#include "person.h";

std::vector<Person> search(std::vector<Person> & Vperson, std::string name){
    std::string fullname;
    std::string firstname,lastname;
    std::vector<Person> person;
    for (auto it = Vperson.begin(); it != Vperson.end(); ++it) {
        fullname = it->name;
        std::stringstream iss(fullname);
        iss >> firstname >> lastname;
        if(name == firstname || name == lastname){
            person.push_back(*it);
        }

    }

    return person;

}

// function read the input from a txt file
std::vector<Person> read_input(std::ifstream & input){
    std::vector<Person>vec_Person;

    std::string line, street, city;
    int zip1, zip2;
    std::string address_part_two;
    int concat_zip;
    Person person;



    while(std::getline(input, line)){



        person.name =  strTolower(line);

        std::getline(input, line);

        person.id =  strTolower(line);

        std::getline(input, line);

        // save the splited string in a vector
        std::vector<std::string>address_in_two_part = split(line, ',');

        // first part of the string
        street = address_in_two_part.at(0);

        // second part of the string
        address_part_two = address_in_two_part.at(1);

        // the second part of the string contain tre part, using string stream to extract att tre part
        std::stringstream iss(address_part_two);

        iss >> zip1 >> zip2 >> city;


        std::stringstream isss;
        // write a these two part into the string stream instance
        isss << zip1 << zip2;
        int result;
        isss >> result;

        person.location.street = street;


        person.location.zip = result;
        city = strTolower(city);
        person.location.city = city;

        /*std::cout << person.name << "\n" <<
        person.id << "\n" <<
        person.location.street <<" "<< result  <<" "<< person.location.city << "\n\n";*/

        vec_Person.push_back(person);

        //std::for_each(vec_Person.begin(), vec_Person.end(), print);


    }
    return vec_Person;
};


void print(const Person &person){
    std::cout << person.name << "\n" << person.id << "\n" << person.location.street << "  "<< person.location.zip << "  "<<
              person.location.city << "\n\n\n";
}

// this funtion split the string in to the two part using a delimiter character
std::vector<std::string> split(std::string& s, char delemeter){
    std::stringstream str(s);
    std::string strg;
    std::vector<std::string> stringtoken;

    // use separator (delimiter) to read parts of the line
    while(std::getline(str,strg, delemeter )){
        stringtoken.push_back(strg);

    }

    return stringtoken;
}



// this function change the txt file and user input to tolower before it is processed
std::string strTolower (std::string s){
    std::transform(s.begin(), s.end(), s.begin(),[](unsigned char c){
        return std::tolower(c);
    });
    return s;
}


