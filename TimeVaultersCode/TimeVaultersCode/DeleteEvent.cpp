#include "DeleteEvent.h"
#include "Output.h"
#include "../TimeVaultersLibrary/EventUtils.h"

void deleteEvent() {
    while (true) {

        std::string dirPath = "../Assets/HistoricEvents";

        // Read event files and create a linked list of EventNode
        EventNode* head = readEventFiles(dirPath);
        displayEventList(head);

        std::cout << "Enter the number of the event to delete: ";
        int selectedIndex;
        std::cin >> selectedIndex;
        selectedIndex--;

        std::string fileToDelete;
        EventNode* current = head;
        for (int i = 0; i < selectedIndex && current; ++i) {
            current = current->next;
        }
        if (current) {
            fileToDelete = current->fileName;
        }

        std::cout << "\n";

        // Delete the event file if it exists
        if (!fileToDelete.empty()) {
            std::filesystem::remove(dirPath + "/" + fileToDelete);
            std::cout << "Event " << fileToDelete << " deleted successfully.\n";
        }
        else {
            std::cout << "Event not found.\n";
        }

        // Clean up the linked list
        while (head) {
            EventNode* temp = head;
            head = head->next;
            delete temp;
        }

        std::cout << "Do you want to delete more events? (y/n): ";
        char choice;
        std::cin >> choice;
        system("cls");
        if (choice != 'y') {
            mainMenu(); // Return to the main menu if the user does not want to delete more events
        }
    }
}