#include "DeleteEvent.h"
#include "Output.h"
#include "../TimeVaultersLibrary/EventUtils.h"

void deleteEvent() {
    while (true) {
        std::string dirPath = "../Assets/HistoricEvents";

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
        if (!fileToDelete.empty()) {
            std::filesystem::remove(dirPath + "/" + fileToDelete);
            std::cout << "Event " << fileToDelete << " deleted successfully.\n";
        }
        else {
            std::cout << "Event not found.\n";
        }

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
            mainMenu();
        }
    }
}