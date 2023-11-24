#include <cstdlib>
#include <iostream>

#include "stack.h"

int main(){

    Stack Hassan;

    Hassan.Push("Hassan", 1738);
    Hassan.Push("Burger", 0);
    Hassan.Push("Gaming", 0);
    Hassan.Push("C++", 9001);

    Hassan.Print();

    std::cout << "Popping" << std::endl;
    Hassan.Pop();
    std::cout << "Popping" << std::endl;
    Hassan.Pop();
    std::cout << "Popping" << std::endl;
    Hassan.Pop();
    std::cout << "Popping" << std::endl;
    Hassan.Pop();
    std::cout << "Popping" << std::endl;
    Hassan.Pop();

    std::cout << "\n\nNew Stack\n" << std::endl;
    Hassan.Push("GPA", 3.2);
    Hassan.Push("Books", 20);
    Hassan.Print();
    
    return 0;
}