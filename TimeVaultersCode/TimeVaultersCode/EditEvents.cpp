#include "EditEvents.h"
#include "../TimeVaultersLibrary/EventUtils.h"
#include "Output.h"
#include "../TimeVaultersLibrary/InvalidInput.h"

void editEvents() {
    while (true) {

        system("cls");

        std::string dirPath = "../Assets/HistoricEvents";

        // Read the event files and store the list of events
        EventNode* head = readEventFiles(dirPath);
        displayEventList(head);

        std::cout << "Enter the number of the event file to edit: ";
        int selectedIndex;
        std::cin >> selectedIndex;
        selectedIndex--;

        std::string fileName;
        EventNode* current = head;

        for (int i = 0; i < selectedIndex && current; ++i) {
            current = current->next;
        }

        // If the event is found, get the file name; otherwise, handle invalid input
        if (current) {
            fileName = current->fileName;
        }
        else {
            invalidInput();
            mainMenu();
        }

        // Construct the file path for the selected event
        std::string filePath = dirPath + "/" + fileName;

        // Open the event file for reading
        std::ifstream inputFile(filePath);
        std::vector<std::string> lines;
        std::string line;

        // Read all lines from the file into a vector
        if (inputFile.is_open()) {
            while (std::getline(inputFile, line)) {
                lines.push_back(line);
            }
            inputFile.close();
        }
        else {
            invalidInput();
            mainMenu();
        }

        std::cout << "What do you want to edit?\n";
        std::cout << "1. Name\n";
        std::cout << "2. Year\n";
        std::cout << "3. Description\n";
        int editChoice;
        std::cin >> editChoice;

        std::cin.ignore(); // Ignore the newline character left in the input buffer

        switch (editChoice) {
        case 1: {
            std::string newName;
            std::cout << "Enter new name: ";
            std::getline(std::cin, newName);
            lines[1] = newName;
            break;
        }
        case 2: {
            std::string newYear;
            std::cout << "Enter new year: ";
            std::getline(std::cin, newYear);
            lines[3] = newYear;
            break;
        }
        case 3: {
            std::string newDescription, newLine;
            std::cout << "Enter new description (end with an empty line):\n";
            lines[5].clear();  // Clear the existing description
            while (true) {
                std::getline(std::cin, newLine);
                if (newLine.empty()) break;  // Stop when an empty line is entered
                lines[5] += newLine;  // Append new lines to the description
            }
            break;
        }
        default:
            invalidInput();
            mainMenu();
        }

        std::ofstream outputFile(filePath);
        if (outputFile.is_open()) {
            // Write the updated content back to the file
            for (const auto& l : lines) {
                outputFile << l << "\n";
            }
            outputFile.close();
            std::cout << "Event updated successfully.\n";
        }
        else {
            std::cout << "Unable to open file for writing.\n";
        }

        while (head) {
            EventNode* temp = head;
            head = head->next;
            delete temp;
        }

        std::cout << "Do you want to edit more events? (y/n): ";
        char continueChoice;
        std::cin >> continueChoice;
        if (continueChoice != 'y') {
            // Return to the main menu if the user does not want to continue
            mainMenu();
        }
        std::cin.ignore();
    }
}