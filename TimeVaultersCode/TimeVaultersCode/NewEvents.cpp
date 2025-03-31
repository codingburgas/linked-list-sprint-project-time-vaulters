#include "NewEvents.h"
#include "BubbleSort.h"
#include "Output.h"
#include <fstream>
#include <algorithm>
#include <filesystem> // For creating directories

void InputEvents() {
    // Define the relative directory path
    std::filesystem::path dirPath = std::filesystem::current_path().parent_path() / "Assets" / "HistoricEvents";

    // Ensure the HistoricEvents folder exists
    std::filesystem::create_directories(dirPath);

    while (true) {
        std::cout << "Enter the number of events you want to add: ";
        int size;
        std::cin >> size;

        HistoricEvent* head = nullptr;
        HistoricEvent* tail = nullptr;

        std::cin.ignore(); // Ignores the newline character left in the input buffer after reading size

        for (int i = 0; i < size; i++) {
            HistoricEvent* newEvent = new HistoricEvent();
            std::cout << "\n Enter the name of the event: ";
            std::getline(std::cin, newEvent->name);
            std::cout << "Enter the year of the event: ";
            std::cin >> newEvent->year;
            std::cin.ignore(); // Ignores the newline character left in the input buffer after reading year
            std::cout << "Enter the description of the event: ";
            std::getline(std::cin, newEvent->description);
            newEvent->prev = tail;
            newEvent->next = nullptr;

            if (tail) {
                tail->next = newEvent;
            }
            else {
                head = newEvent;
            }
            tail = newEvent;
        }

        BubbleSort(head);

        HistoricEvent* current = head;
        int index = 1;
        while (current) {
            std::cout << "Event " << index++ << ": " << current->name << "| year " << current->year << " - " << current->description << std::endl << std::endl;

            // Create a file with the event name as the title in the HistoricEvents folder
            std::filesystem::path filePath = dirPath / (current->name + ".txt");
            // Replace spaces with underscores to avoid issues with file names
            std::string fileName = filePath.string();
            std::replace(fileName.begin(), fileName.end(), ' ', '_');
            std::ofstream outFile(fileName);
            if (outFile) {
                outFile << "Name Of Event: " << current->name << "\n";
                outFile << "The Year It Takes Place: " << current->year << "\n";
                outFile << "Description: \n" << current->description << "\n";
                outFile.close();
            }
            else {
                std::cout << "Error creating file " << fileName << std::endl << std::endl;
            }
            HistoricEvent* temp = current;
            current = current->next;
            delete temp;
        }

        std::cout << "Do you want to sort more events? (y/n): ";
        char choice;
        std::cin >> choice;
        if (choice != 'y') {
            mainMenu();
        }
        std::cin.ignore(); // Ignores the newline character left in the input buffer after reading choice
    }
}