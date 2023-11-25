#include <cstdlib>
#include <iostream>
#include <string>

#include "hash.h"

int main(){
    
    Hash Hashy;

    Hashy.AddItem("Paul", "Locha");
	Hashy.AddItem("Kim", "Iced Mocha");
	Hashy.AddItem("Emma", "Strawberry Smoothie");
	Hashy.AddItem("Annie", "Hot Chocolate");
	Hashy.AddItem("Sarah", "Passion Tea");
	Hashy.AddItem("Pepper", "Caramel Mocha");
	Hashy.AddItem("Mike", "Chai Tea");
	Hashy.AddItem("Steve", "Apple Cider");
	Hashy.AddItem("Bill", "Root Beer");
	Hashy.AddItem("Marie", "Skinny Latte");
	Hashy.AddItem("Susan", "Water");
	Hashy.AddItem("Joe", "Green Tea");

    // Hashy.PrintTable();

    // Hashy.PrintItemsInIndex(0);
    // Hashy.PrintItemsInIndex(9);
    // Hashy.PrintItemsInIndex(3);

    // Hashy.FindDrink("Hassan");

    Hashy.PrintItemsInIndex(2);

    for(std::string name; std::cin >> name; ){
        if(name == "exit"){
            break;
        }else{
            Hashy.RemoveItem(name);
        }
    }

    // Hashy.PrintTable();
    Hashy.PrintItemsInIndex(2);

    return 0;
}