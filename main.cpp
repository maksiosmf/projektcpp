#include "include/PhoneDirectory.h"
#include <iostream>
#include <cstdlib>

using namespace PhoneBook;

void printUsage() {
    std::cout << "Usage: ./projektcpp [add|remove|display|find|sort] [name] [phone]" << std::endl;
}

int main(int argc, char* argv[]) {
    Directory phoneDirectory;

    if (argc < 2) {
        printUsage();
        return 1;
    }

    std::string command = argv[1];

    if (command == "add" && argc == 4) {
        std::string name = argv[2];
        std::string phone = argv[3];
        phoneDirectory.addEntry(name, phone);
    } else if (command == "remove" && argc == 3) {
        std::string name = argv[2];
        phoneDirectory.removeEntry(name);
    } else if (command == "display") {
        phoneDirectory.displayEntries();
    } else if (command == "find" && argc == 3) {
        std::string name = argv[2];
        Entry* entry = phoneDirectory.findEntry(name);
        if (entry) {
            std::cout << "Found: Name: " << entry->first << ", Phone: " << entry->second << std::endl;
        } else {
            std::cout << "Entry not found." << std::endl;
        }
    } else if (command == "sort") {
        phoneDirectory.sortEntries();
    } else {
        printUsage();
        return 1;
    }

    return 0;
}