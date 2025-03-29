#include <iostream>
#include <fstream>
#include <string>
#include "Output.h"



void optionsMenu()
{

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
        system("cls");

        mainMenu();
        break;
    }
}

void developerPage()
{

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
        system("cls");

        mainMenu();
        break;
    }
}

void mainMenu()
{

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
                system("cls");

                optionsMenu();
                break;

            case 3:
                system("cls");

                developerPage();
                break;
            }
}