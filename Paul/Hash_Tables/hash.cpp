#include <cstdlib>
#include <iostream>
#include <string>

#include "hash.h"

Hash::Hash(){
    for(int i = 0; i < tableSize; i++){
        HashTable[i] = new item;
        HashTable[i]->name = "empty";
        HashTable[i]->drink = "empty";
        HashTable[i]->next = nullptr;
    }
}

void Hash::AddItem(std::string name, std::string drink){
    int index = Hash_func(name);
    if(HashTable[index]->name == "empty"){
        HashTable[index]->name = name;
        HashTable[index]->drink = drink;
    }else{
        item *ptr = HashTable[index];
        item *n = new item;
        n->name = name;
        n->drink = drink;
        n->next = nullptr;

        while(ptr->next != nullptr){
            ptr = ptr->next;
        }
        ptr->next = n;
    }
}

int Hash::NumberOfItemsInIndex(int index){
    int count = 0;
    if(HashTable[index]->name == "empty"){
        return count;
    }else{
        count++;
        item *ptr = HashTable[index];
        while(ptr->next != nullptr){
            count++;
            ptr = ptr->next;
        }
    }
    return count;
}

void Hash::PrintTable(){
    int number;
    for(auto i = 0; i < tableSize; i++){
        number = NumberOfItemsInIndex(i);
        std::cout << "-------------------\n";
        std::cout << "index = " << i << std::endl;
        std::cout << HashTable[i]->name << std::endl;
        std::cout << HashTable[i]->drink << std::endl;
        std::cout << "# of items = " << number << std::endl;
        std::cout << "-------------------\n";
    }
}

void Hash::PrintItemsInIndex(int index){
    item *ptr = HashTable[index];
    if(ptr->name == "empty"){
        std::cout << "bucket = " << index << " is empty" << std::endl;
    }else{
        std::cout << "bucket = " << index << " contains the following items\n";
        while(ptr != nullptr){
            std::cout << "-------------------\n";
            std::cout << " name: " << ptr->name << std::endl;
            std::cout << " drink: " << ptr->drink << std::endl;
            std::cout << "-------------------\n";
            ptr = ptr->next;
        }
    }
}

void Hash::FindDrink(std::string name){
    item *ptr;
    for(auto i = 0; i < tableSize; i++){
        ptr = HashTable[i];
        while(ptr != nullptr){
            if(ptr->name == name){
                std::cout << "-------------------\n";
                std::cout << " name: " << ptr->name << std::endl;
                std::cout << " drink: " << ptr->drink << std::endl;
                std::cout << "-------------------\n";
                return;
            }
            // if(ptr->name == "empty"){
            //     ptr = ptr->next;
            // }
            ptr = ptr->next;
        }
    }
    std::cout << "-------------------\n";
    std::cout << "name: " << name << " does not exist" << std::endl;
}

void Hash::RemoveItem(std::string name){
    int index = Hash_func(name);
    item *delptr;
    item *p1;
    item *p2;

    // Case 0 - Bucket is empty
    if(HashTable[index]->name == "empty"){
        std::cout << "name: " << name << " does not exist" << std::endl;
    }
    // Case 1 - only one item in bucket and item has matching name
    else if(HashTable[index]->name == name && HashTable[index]->next == nullptr){
        HashTable[index]->name = "empty";
        HashTable[index]->drink = "empty";
        std::cout << "name: " << name << " was removed from HashTable" << std::endl;
    }
    // Case 2 - match is located in the first item in the bucket but there
    //          are more items in the bucket
    else if(HashTable[index]->name == name){
        delptr = HashTable[index];
        HashTable[index] = HashTable[index]->next;
        delete delptr;
        std::cout << "name: " << name << " was removed from HashTable" << std::endl;
    }
    // Case 3 - Bucket contains items but first item is not a match
    else{
        p1 = HashTable[index]->next;
        p2 = HashTable[index];
        while(p1 != nullptr && p1->name != name){
            p2 = p1;
            p1 = p1->next;
        }
        // Case 3.1 - no match
        if(p1 == nullptr){
            std::cout << "name: " << name << " does not exist" << std::endl;
        }
        // Case 3.2 - match found
        else{
            delptr = p1;
            p1 = p1->next;
            p2->next = p1;

            delete delptr;
            std::cout << "name: " << name << " was removed from HashTable" << std::endl;
        }
    }
}

int Hash::Hash_func(std::string key){
    int Hash = 0;
    int index;
    
    for(auto item : key){
        Hash = (Hash + static_cast<int>(item)) * 17;
        //std::cout << "Hash = " << Hash << std::endl;
    }

    index = Hash % this->tableSize;

    return index;
}