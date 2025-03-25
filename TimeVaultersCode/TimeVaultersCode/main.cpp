#include <iostream>
#include "BubbleSort.h"
#include "HistoricEvent.h"
#include "Output.h"

int main()
{
	int choice;

	mainMenu();

	std::cin >> choice;


    while (true) {
        std::cout << "Enter the number of events you want to sort: ";
        int size;
        std::cin >> size;

        HistoricEvent* head = nullptr;
        HistoricEvent* tail = nullptr;

        std::cin.ignore(); // Ignores the newline character left in the input buffer after reading size

        for (int i = 0; i < size; i++) {
            HistoricEvent* newEvent = new HistoricEvent();
            std::cout << "Enter the name of the event: ";
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
            std::cout << "Event " << index++ << ": " << current->name << "| year " << current->year << " - " << current->description << std::endl;
            HistoricEvent* temp = current;
            current = current->next;
            delete temp;
        }

        std::cout << "Do you want to sort more events? (y/n): ";
        char choice;
        std::cin >> choice;
        if (choice != 'y') {
            break;
        }
        std::cin.ignore(); // Ignores the newline character left in the input buffer after reading choice
    }
}
