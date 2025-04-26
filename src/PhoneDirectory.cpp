#include "../include/PhoneDirectory.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

namespace PhoneBook {

    typedef std::string PhoneNumber;
    typedef std::string Name;
    typedef std::pair<Name, PhoneNumber> Entry;

    Directory::Directory() {
        loadFromFile();
    }

    Directory::~Directory() {
        saveToFile();
    }

    void Directory::addEntry(const Name& name, const PhoneNumber& number) {
        entries.push_back(std::make_pair(name, number));
        std::cout << "Added entry: Name: " << name << ", Phone: " << number << std::endl;
        saveToFile();
    }

    void Directory::removeEntry(const Name& name) {
        entries.erase(std::remove_if(entries.begin(), entries.end(),
                                     [&name](const Entry& entry) { return entry.first == name; }), entries.end());
        saveToFile();
    }

    void Directory::displayEntries() const {
        if (entries.empty()) {
            std::cout << "Phone directory is empty." << std::endl;
            return;
        }
        
        std::cout << "=== Phone Directory Entries ===" << std::endl;
        for (const auto& entry : entries) {
            std::cout << "Name: " << entry.first << ", Phone: " << entry.second << std::endl;
        }
        std::cout << "==============================" << std::endl;
    }

    void Directory::sortEntries() {
        std::sort(entries.begin(), entries.end());
        saveToFile();
    }

    Entry* Directory::findEntry(const Name& name) {
        auto it = std::find_if(entries.begin(), entries.end(),
                               [&name](const Entry& entry) { return entry.first == name; });
        return it != entries.end() ? &(*it) : nullptr;
    }

    void Directory::loadFromFile() {
        try {
            std::ifstream file("./cmake-build-debug/phonebook.txt");
            if (file.is_open()) {
                entries.clear();
                Name name;
                PhoneNumber number;
                while (file >> name >> number) {
                    entries.push_back(std::make_pair(name, number));
                }
                file.close();
            } else {
            }
        } catch (const std::exception& e) {
            std::cerr << "Error loading from file: " << e.what() << std::endl;
        }
    }

    void Directory::saveToFile() const {
        try {
            std::ofstream file("./cmake-build-debug/phonebook.txt", std::ios::trunc);
            if (file.is_open()) {
                for (const auto& entry : entries) {
                    file << entry.first << " " << entry.second << std::endl;
                }
                file.close();
            } else {
                std::cerr << "Error: Could not open phonebook.txt for writing." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "Error saving to file: " << e.what() << std::endl;
        }
    }

}