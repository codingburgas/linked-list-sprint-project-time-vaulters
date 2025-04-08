#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Output.h"
#include "DeleteEvent.h"
#include "NewEvents.h"
#include "EditEvents.h"
#include "SearchEvents.h"

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


void optionsMenu()
{

    std::ifstream inputFile("../Assets/Menus/OptionsMenu.txt");

    char ch;
    int choice;

    while (inputFile.get(ch)) {

        std::cout << ch;
    };

    std::cin >> choice;

    if (std::cin.fail())
    {
        invalidInput();
        optionsMenu();
    }

    else if (choice > 0 && choice < 5)
    {

        switch (choice)
        {
        case 1:
            system("cls");
            InputEvents();
            break;

		case 2:
			system("cls");
			editEvents();
			break;

        case 3:
            system("cls");
            deleteEvent();
            break;


        case 4:
            system("cls");
            mainMenu();
            break;
        }

    }
    else
    {
        invalidInput();
        optionsMenu();
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

    if (std::cin.fail())
    {
        invalidInput();
        optionsMenu();
    }

    else if (choice == 1)
    {
        system("cls");
        mainMenu();
    }

    else
    {
        invalidInput();
        developerPage();
    }
}

void mainMenu()
{
    system("cls");
    std::ifstream inputFile("../Assets/Menus/MainMenu.txt");

    char ch;
    int choice;

    while (inputFile.get(ch)) {

        std::cout << ch;
    };

    std::cin >> choice;

    if (std::cin.fail())
    {
        invalidInput();
        mainMenu();
    }

    else if (choice > 0 && choice < 5)
    {

        switch (choice)
        {
        case 1:
            vaultSearch();
            break;

        case 2:
            system("cls");

            optionsMenu();
            break;

        case 3:
            system("cls");

            developerPage();
            break;
        case 4:
            system("cls");
            exit(0);
            break;
        }
    }

    else
    {
        invalidInput();
        mainMenu();
    }
}