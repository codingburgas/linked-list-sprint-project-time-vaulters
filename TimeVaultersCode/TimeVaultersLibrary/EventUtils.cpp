#include "EventUtils.h"

EventNode* readEventFiles(const std::string& dirPath) {
    EventNode* head = nullptr;
    EventNode* tail = nullptr;

    for (const std::filesystem::directory_entry& entry : std::filesystem::directory_iterator(dirPath)) {
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

    return head;
}

void displayEventList(EventNode* head) {
    std::cout << "List of events:\n";
    EventNode* current = head;
    int index = 1;
    while (current) {
        std::cout << index++ << ". " << current->fileName << "\n";
        current = current->next;
    }
}