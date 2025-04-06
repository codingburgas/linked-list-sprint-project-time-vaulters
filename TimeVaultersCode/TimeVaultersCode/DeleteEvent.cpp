#include "DeleteEvent.h"
#include "Output.h"

void deleteEvent() {
    while (true) {
        std::string dirPath = "../Assets/HistoricEvents";

        EventNode* head = nullptr;
        EventNode* tail = nullptr;

        // Read all .txt files in the directory
        for (std::filesystem::directory_entry entry : std::filesystem::directory_iterator(dirPath)) {
            EventNode* newNode = new EventNode(entry.path().filename().string());
            if (!head) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        // Display the list of events
        std::cout << "List of events:\n";
        EventNode* current = head;
        int index = 1;
        while (current) {
            std::cout << index++ << ". " << current->fileName << "\n";
            current = current->next;
        }

        std::cout << "Enter the number of the event to delete: ";
        int selectedIndex;
        std::cin >> selectedIndex;
        selectedIndex--;

        // Find the event file to delete
        std::string fileToDelete;
        current = head;
        for (int i = 0; i < selectedIndex && current; ++i) {
            current = current->next;
        }
        if (current) {
            fileToDelete = current->fileName;
        }

        std::cout << "\n";
        // Delete the event file
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
