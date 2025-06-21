#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

/**
 * brief: it is a simple program that promp the user for a name and analyze the input for a charectar like ',' and then convert the input to the lowercase.
 * the objective is to to get familiar with using the std::substr() and functions like std::tolower and std::npos
 */

std::string input_analys(std::string input)
{
    int pos = input.find(',');
    if (pos == std::string::npos)
    {
        for (auto it : input)
        {
            input = std::tolower(it);
        }
    }
    else
    {
        std::string str1 = input.substr(0, pos);
        std::string str2 = input.substr(pos, input.size());
        input = str1 + " " + str2;
    }

    return input;
}

int main()
{

    std::string input;

    std::cout << " please enter your fullname   :";
    std::getline(std::cin, input);
    std::cout << input_analys(input);

    return 0;
}

/*
the main objectiv of this program is to learn how to use stream operator and std functions such as std::getline() and  containers like std::vector and its member functions.
the program read a file that contain a nams with a persons security numbers and address. this program read all the data and determine if the person is male or female
*/

/*
std::vector<std::string> split(std::string &s, char delimiter)
{
    std::vector<std::string> stringtoken;
    std::string token;
    std::istringstream iss(s);

    while (std::getline(iss, token, delimiter))
    {
        stringtoken.push_back(token);
    }
    return stringtoken;
}

int main()
{

    std::ifstream input;
    std::ofstream output;
    std::string sureName, lastName, personNum, street;
    std::string pAdd1, pAdd2, city;
    input.open("names.txt");
    output.open("name.txt");

    if (input.fail() && output.fail())
    {
        std::cerr << "unable to open the input file";
        return 1;
    }

    while (!input.eof())
    {
        std::getline(input, sureName);
        std::getline(input, personNum);
        std::getline(input, street);
        std::vector<std::string> streetParts = split(street, ',');
        // std::vector<std::string> streetParts1 = split(streetParts[1], ' ');


// in here we determine of the security number belong to a male or female and the add F or M to it
        for (int i = 0; i < personNum.size(); ++i)
        {
        // here we chech the last number of se if the it is a odd or non odd integer
            if (i == 8)
            {

                if (personNum[i] % 2 == 0)
                    sureName += ": F";
                else if (personNum[i] % 2 != 0)
                    sureName += ": M";
            }
        }

        // std::cout << street << "\n";
        output << sureName << "\n"
               << street << "\n";

        // std::cout << streetParts[0] << std::setw(5) << streetParts1[1] << streetParts1[2] << std::setw(5) << streetParts1[4] << "\n";

        // this is a another way to read the rest of the line without thinking about what index the word are in.
        std::istringstream iss(streetParts[1]);
        iss >> pAdd1 >> pAdd2 >> city;

        std::cout << sureName << std::setw(5)
                  << streetParts[0] << std::setw(5) << pAdd1 << pAdd2 << std::setw(5) << city << "\n";
        // return 0;
    }
    input.close();
    output.close();

    return 0;
}
*/

/*
the goal is to get familiar to the rand and srand std functions.
this program generate a 2 random integer and och the user have to calculate the result, and then the program chech if the answer is correct.
*/

/*int main()
{
    int input;

    while (true)
    {
        std::srand(std::time(nullptr));
        double randomValue = 0 + rand() % 10;
        double randValue = 0 + rand() % 10;
        std::cout << "svara på substraktions frågan" << "\n";
        std::cout << "what is ? " << randomValue << "-" << randValue << "\n";
        std::cin >> input;

        if (randomValue - randValue == input)
        {
            std::cout << "you answer is correct." << "\n"
                      << " GRATTIS" << "\n";
        }
        else
        {
            std::cout << "Wrong answer try igen " << "\n";
        }
    }

    return 0;
}*/