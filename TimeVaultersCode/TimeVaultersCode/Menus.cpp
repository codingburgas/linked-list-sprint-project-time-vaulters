#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Output.h"
#include "DeleteEvent.h"
#include "NewEvents.h"
#include "EditEvents.h"
#include "SearchEvents.h"
#include "../TimeVaultersLibrary/InvalidInput.h"

void optionsMenu()
{
    // Open and read the OptionsMenu.txt file
    std::ifstream inputFile("../Assets/Menus/OptionsMenu.txt");

    char ch;
    int choice;

    while (inputFile.get(ch)) {
        std::cout << ch;
    }

    std::cin >> choice;

    // Check if the input is valid
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

void contactUsMenu()
{
    // Open and read the ContactUs.txt file
    std::ifstream inputFile("../Assets/Menus/ContactUsMenu.txt");

    char ch;
    int choice;

    while (inputFile.get(ch)) {
        std::cout << ch;
    }

    std::cin >> choice;

    if (std::cin.fail())
    {
        invalidInput();
        contactUsMenu();
    }
    else if (choice == 1)
    {
        system("cls");
        mainMenu();
    }
    else
    {
        invalidInput();
        contactUsMenu();
    }
}

void mainMenu()
{
    system("cls");
    std::ifstream inputFile("../Assets/Menus/MainMenu.txt");

    char ch;
    int choice;

    // Print the content of the main menu
    while (inputFile.get(ch)) {
        std::cout << ch;
    }

    std::cin >> choice;

    // Check if the input is valid
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
            contactUsMenu();
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