#include <iostream>
#include <fstream>
#include <string>
#include "Output.h"

void mainMenu()
{

        std::ifstream inputFile("../Assets/Menus/MainMenu.txt");

        char ch;

        inputFile >> std::noskipws;

        while (inputFile.get(ch)) {

            std::cout << ch;
        };
}