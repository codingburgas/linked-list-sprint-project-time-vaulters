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
		HistoricEvent* events = new HistoricEvent[size];
		for (int i = 0; i < size; i++) {
			std::cout << "Enter the name of the event: ";
			std::cin >> events[i].name;
			std::cout << "Enter the year of the event: ";
			std::cin >> events[i].year;
			std::cout << "Enter the description of the event: ";
			std::cin >> events[i].description;
		}
		BubbleSort(events, size);
		for (int i = 0; i < size; i++) {
			std::cout << "Event " << i + 1 << ": " << events[i].name << " year " << events[i].year << " - " << events[i].description << std::endl;
		}
		delete[] events;
		std::cout << "Do you want to sort more events? (y/n): \n";
		char choice;
		std::cin >> choice;
		if (choice != 'y') {
			break;
		}
	}
}
