#include "EventUtils.h"

// Function to read event files from a directory and return a linked list of EventNodes
EventNode* readEventFiles(const std::string& dirPath) {
    EventNode* head = nullptr;
    EventNode* tail = nullptr;

    for (const std::filesystem::directory_entry& entry : std::filesystem::directory_iterator(dirPath)) {
        EventNode* newNode = new EventNode(entry.path().filename().string());  // Create a new node with the filename

        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

void displayEventList(EventNode* head) {
    std::cout << "List of events:\n";
    EventNode* current = head;
    int index = 1;
    while (current) {
        // Display the event's index and filename
        std::cout << index++ << ". " << current->fileName << "\n";
        current = current->next;
    }
}