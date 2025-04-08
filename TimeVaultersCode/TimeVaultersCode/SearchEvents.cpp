#include "SearchEvents.h"
#include "../TimeVaultersLibrary/EventUtils.h"
#include "../TimeVaultersLibrary/InvalidInput.h"
#include "Output.h"

void vaultSearch()
{
    while (true) {

        system("cls");
        std::string dirPath = "../Assets/HistoricEvents";
        EventNode* head = readEventFiles(dirPath);

        displayEventList(head);

        std::cout << "Enter the number of the event file to search: ";

        int selectedIndex;
        std::cin >> selectedIndex;
        selectedIndex--;

        std::string fileName;
        EventNode* current = head;

        for (int i = 0; i < selectedIndex && current; ++i){
            current = current->next;
        }

        if (current) {
            fileName = current->fileName;
        }
        else
        {
			invalidInput(); 
            mainMenu();
        }
        system("cls");

        std::string filePath = dirPath + "/" + fileName;
        std::ifstream inputFile(filePath);
        std::vector<std::string> lines;
        std::string line;

        if (inputFile.is_open())
        {
            while (std::getline(inputFile, line)){
                lines.push_back(line);
            }
            inputFile.close();
        }
        else
        {
            std::cout << "Unable to open file.\n";
        }

        for (int i = 0; i < lines.size(); ++i){
            std::cout << lines[i] << std::endl;
        }

        while (head){
            EventNode* temp = head;
            head = head->next;
            delete temp;
        }

        std::cout << "\nDo you want to view more events? (y/n): ";

        char choice;
        std::cin >> choice;

        if (choice != 'y'){
            mainMenu();
        }
    }
}