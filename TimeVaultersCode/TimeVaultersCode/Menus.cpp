#include <iostream>
#include <fstream>
#include <string>
#include "Output.h"



void optionsMenu()
{

    std::cout << std::endl << std::endl;

    std::ifstream inputFile("../Assets/Menus/OptionsMenu.txt");

    char ch;
    int choice;

    while (inputFile.get(ch)) {

        std::cout << ch;
    };

    std::cin >> choice;

    switch (choice)
    {
    case 4:
        mainMenu();
        break;
    }
}

void developerPage()
{

    std::cout << std::endl << std::endl;

    std::ifstream inputFile("../Assets/Menus/DeveloperPage.txt");

    char ch;
    int choice;

    while (inputFile.get(ch)) {

        std::cout << ch;
    };
    
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        mainMenu();
        break;
    }
}void mainMenu()
{

    std::cout << std::endl << std::endl;

        std::ifstream inputFile("../Assets/Menus/MainMenu.txt");

        char ch;
        int choice;

        while (inputFile.get(ch)) {

            std::cout << ch;
        };

        std::cin >> choice;

            switch (choice)
            {
            case 1:
                //vaultSearch();
                break;

            case 2:
                optionsMenu();
                break;

            case 3:
                developerPage();
                break;
            }
}