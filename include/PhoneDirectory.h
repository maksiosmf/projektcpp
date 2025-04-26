#ifndef PHONEDIRECTORY_H
#define PHONEDIRECTORY_H

#include <string>
#include <vector>
#include <fstream>

namespace PhoneBook {

    typedef std::string PhoneNumber;
    typedef std::string Name;
    typedef std::pair<Name, PhoneNumber> Entry;

    class Directory {
    private:
        std::vector<Entry> entries;
        const std::string filename = "phonebook.txt";

    public:
        Directory();
        ~Directory();
        
        void addEntry(const Name& name, const PhoneNumber& number);
        void removeEntry(const Name& name);
        void displayEntries() const;
        void sortEntries();
        Entry* findEntry(const Name& name);
        void loadFromFile();
        void saveToFile() const;
    };

}

#endif