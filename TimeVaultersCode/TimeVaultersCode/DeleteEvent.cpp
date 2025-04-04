#include "DeleteEvent.h"
#include "Output.h"

void deleteEvent() {
    

    while (true) {

        std::string dirPath = "../Assets/HistoricEvents";

        std::vector<std::string> eventFiles;

        // Read all .txt files in the directory
        for (std::filesystem::directory_entry entry : std::filesystem::directory_iterator(dirPath)) {
            eventFiles.push_back(entry.path().filename().string());
        }

        // Display the list of events
        std::cout << "List of events:\n";
        for (int i = 0; i < eventFiles.size(); ++i) {
            std::cout << i + 1 << ". " << eventFiles[i] << "\n";
        }

        std::cout << "Enter the number or name of the event to delete: ";
        std::string input;
        std::cin >> input;

        int index = 0;
        // Find the event file to delete
        std::string fileToDelete;
        if (index >= 0 && index < eventFiles.size()) {
            fileToDelete = eventFiles[index];
        }
        else {
            for (std::string file : eventFiles) {
                if (file == input) {
                    fileToDelete = file;
                    break;
                }
            }
        }
        std::cout << "\n";
        // Deletes the event file
        if (!fileToDelete.empty()) {
            std::filesystem::remove(dirPath + "/" + fileToDelete);
            std::cout << "Event " << fileToDelete << " deleted successfully.\n";
        }
        else {
            std::cout << "Event not found.\n";
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
