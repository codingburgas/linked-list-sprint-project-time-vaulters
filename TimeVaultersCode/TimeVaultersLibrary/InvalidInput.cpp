#include "InvalidInput.h"
#include <iostream>
#include <sstream>

void invalidInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    system("cls");

    std::cout << "[!] Please enter a valid option." << std::endl;
    std::cout << "Press Enter to continue...";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    system("cls");
}

bool isValidIntInput(int& result) {
    std::string input;
    std::getline(std::cin, input);

    std::stringstream ss(input);
    ss >> result;

    return !(ss.fail() || !ss.eof());
}