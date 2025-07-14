//
// Created by shahr on 2024-11-25.
//

#ifndef CONTACTBOK_PERSON_H
#define CONTACTBOK_PERSON_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

/**
 * @brief Stores personal information of a user.
 */
struct PersonInfo
{
    std::string fullname, address, ePost;
    std::string securityNumber, phoneNumber;
};
/**
 * brief used to determined type of the user input
 */
enum stringType{
    isAlphabetic,
    isNumeric,
    other
};

/**
 * @brief Prints all users in the contact book.
 * @param container A vector of PersonInfo containing all user entries to be printed.
 */
void print(std::vector<PersonInfo> container);

/**
 * @brief Registers a new user and saves their info to file and container.
 * @param person A PersonInfo object to store the user's information.
 * @param output Output file stream where the user info is saved.
 * @param container A reference to the vector where the new user will be added.
 */
void UserRegistretion(PersonInfo person, std::ofstream &output, std::vector<PersonInfo> &container);

/**
 * @brief Searches for a user by name or phone number.
 * @param userInput A string containing the search query (name or phone number).
 * @param container A reference to the vector of user data to search in.
 */
void search_User(std::string &userInput, std::vector<PersonInfo> &container);

/**
 * @brief Deletes a user from the contact book based on their name.
 * @param username The name of the user to be deleted.
 * @param container A reference to the vector containing all user entries.
 */
void delete_user(const std::string &username, std::vector<PersonInfo> &container);

/**
 * @brief Analyzes user input to determine if it is numeric or alphabetic.
 * @param input The user input string to analyze.
 * @return Returns a struct string_type indicating the type or value of the input.
 */
stringType input_analys(std::string input);
stringType evaluate(const char &ch);

/**
 * brief function that convert a user input tolower case
 * @param string
 * @return string
 */
std::string str_tolower(std::string s);

/**
 * @brief analys user input as substr in alla data from a person,  such as fullname
 * address, email, security number and phone number
 * @param person, substr
 * @return a boolean
 */
bool search_input_analys(std::string s, PersonInfo person);

#endif // CONTACTBOK_PERSON_H
