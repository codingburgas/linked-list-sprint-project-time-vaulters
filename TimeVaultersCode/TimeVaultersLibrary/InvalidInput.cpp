#include "InvalidInput.h"
#include <iostream>
#include <sstream>

void invalidInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the rest of the current input

    system("cls");

    std::cout << "[!] Please enter a valid option." << std::endl;
    std::cout << "Press Enter to continue...";

    // Wait for the user to press Enter before continuing
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    system("cls");
}

// Function to validate if the input is a valid integer and store it in 'result'
bool isValidIntInput(int& result) {
    std::string input;
    std::getline(std::cin, input);

    std::stringstream ss(input);
    ss >> result;

    // Return true if the parsing was successful (no failure and no extra characters)
    return !(ss.fail() || !ss.eof());
}