/**
 * @brief Entry point of the Contact Book program.
 *
 * This function loads existing user data from a file into memory,
 * then displays a menu to allow the user to:
 * - Register new users
 * - Search for existing users
 * - Delete users
 * - Print all saved users
 * - Exit the program
 *
 * All data is stored in a vector during runtime and persisted in a file named "output.txt".
 * the "output.txt" works as a database, everytime the program rebuts all user information will be read into the
 * vector to process
 * @return Returns 0 if the program exits successfully, or 1 if a file error occurs.
 */

#include "person.h"

int main()
{

    PersonInfo person;
    std::string userInput;
    std::string userInput_delete;

    std::vector<PersonInfo> container;
    int input;
    std::ofstream output;
    std::ifstream in_stream;

    output.open("output.txt", std::ios::app);
    if (!output.is_open())
    {
        std::cerr << "unable to open the file";
        return 1;
    }

    in_stream.open("output.txt");
    if (!in_stream.is_open())
    {
        std::cout << "unable to open the file" << std::endl;
        return 1;
    }

    // Read data from the file into the vector
    while (true)
    {
        if (!std::getline(in_stream, person.fullname))
            break;
        if (!std::getline(in_stream, person.securityNumber))
            break;
        if (!std::getline(in_stream, person.ePost))
            break;
        if (!std::getline(in_stream, person.phoneNumber))
            break;
        if(!std::getline(in_stream, person.address))
            break;

        container.push_back(person);
    }
    in_stream.close();

    bool running = true;
    while (running)
    {
        if (input == 5)
            running = false;

        std::cout << "|" << "---- Welcome to the ContactBok --------" << "|\n\n";
        std::cout << "please enter ( 1 ) for registration of new user " << std::endl;
        std::cout << "please enter ( 2 ) for find a user " << std::endl;
        std::cout << "please enter ( 3 ) find and delete a user " << std::endl;
        std::cout << "please enter ( 4 ) to print all registered users " << std::endl;
        std::cout << "please enter ( 5 ) to exit the program " << std::endl;
        std::cout << "your choose:   ";

        std::cin >> input;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "invalid input please try again " << std::endl;
            continue;
        }

        switch (input)
        {
        case 1:
            std::cin.ignore();
            UserRegistretion(person, output, container);
            break;

        case 2:
            std::cin.ignore();
            std::cout << " please enter the name or phone number of the person you looking for \n";
            std::getline(std::cin, userInput);
            search_User(userInput, container);
            break;

        case 3:
            std::cin.ignore();
            std::cout << " enter a User name or Phone number to find and delete" << std::endl;
            std::getline(std::cin, userInput_delete);
            delete_user(userInput_delete, container);
            break;
        case 4:
            print(container);
            break;

        case 5:
            std::cout << "Exiting the program. Goodbye!" << std::endl;
            output.close(); // Close the file before exiting
            return 0;       // Exit the program

        default:
            std::cout << "Invalid choice. Please choose again." << std::endl;
            break;
        }
    }

    return 0;
}
