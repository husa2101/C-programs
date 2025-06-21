/**
* berief: the objectiv of this program is to learn about how to handle streams and struct and read från a text file and how to handle the input.
*/


#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>


struct Adress
{
    std::string street;
    int zip;
    std::string city;
};

struct Person
{
    std::string name;
    std::string id;
    Adress location;
};

void print(const Person &person){
    std::cout << person.name << "\n" 
    << person.id << "\n"
    << person.location.street << " " << person.location.zip<< " "<< person.location.city << "\n\n"; 

}

void read(std::ifstream & file){
    std::vector<Person> vPerson;

    std::string line;
    while(std::getline(file, line)){
        Person person;
        person.name = line;

        std::getline(file, line);
        person.id = line;

        std::getline(file, line);

        std::stringstream str(line);
        str >> person.location.street >> person.location.zip >> person.location.city;

        vPerson.push_back(person);
        

    }

    std::for_each(vPerson.begin(), vPerson.end(), print);
 
}




int main(){

    std::ifstream file;
    file.open("names.txt");

    if(!file.is_open()){
    std::cerr << "unable to open the file" << std::endl;
    return 1;
    }

    read(file);

    
    file.close();

    return 0;
}
