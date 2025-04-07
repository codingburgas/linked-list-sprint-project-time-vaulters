#include "EditEvents.h"
#include "../TimeVaultersLibrary/EventUtils.h"
#include "Output.h"

void editEvents() {
    while (true) {
        system("cls");
        std::string dirPath = "../Assets/HistoricEvents";

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
        if (current) {
            fileName = current->fileName;
        } else {
            std::cout << "Invalid selection.\n";
            return;
        }

        std::string filePath = dirPath + "/" + fileName;

        std::ifstream inputFile(filePath);
        std::vector<std::string> lines;
        std::string line;
        if (inputFile.is_open()) {
            while (std::getline(inputFile, line)) {
                lines.push_back(line);
            }
            inputFile.close();
        } else {
            std::cout << "Unable to open file.\n";
            return;
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
                lines[5].clear();
                while (true) {
                    std::getline(std::cin, newLine);
                    if (newLine.empty()) break;
                    lines[5] += newLine;
                }
                break;
            }
            default:
                std::cout << "Invalid choice.\n";
                return;
        }

        std::ofstream outputFile(filePath);
        if (outputFile.is_open()) {
            for (const auto& l : lines) {
                outputFile << l << "\n";
            }
            outputFile.close();
            std::cout << "Event updated successfully.\n";
        } else {
            std::cout << "Unable to open file for writing.\n";
        }

        // Clean up the linked list
        while (head) {
            EventNode* temp = head;
            head = head->next;
            delete temp;
        }

        std::cout << "Do you want to edit more events? (y/n): ";
        char continueChoice;
        std::cin >> continueChoice;
        if (continueChoice != 'y') {
            mainMenu();
        }
        std::cin.ignore();
    }
}