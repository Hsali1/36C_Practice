#include <cstdlib>
#include <iostream>
#include <string>

#ifndef HASH_H
#define HASH_H

class Hash{
private:

    static const int tableSize = 4;

    struct item{
        std::string name;
        std::string drink;
        item *next;
    };

    item *HashTable[tableSize];

public:

    Hash();
    // returns index value associated with key
    // converts key to an int by dividing it with the size
    // the remainder is the index(bucket) of the hash table
    int Hash_func(std::string key);
    void AddItem(std::string name, std::string drink);
    int NumberOfItemsInIndex(int index);
    void PrintTable(); // prints out the info of item in the table. Not all in index
    void PrintItemsInIndex(int index);
    void FindDrink(std::string name);
    void RemoveItem(std::string name);
};

#endif /*HASH_H*/