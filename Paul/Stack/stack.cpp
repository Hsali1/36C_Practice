#include <cstdlib>
#include <iostream>

#include "stack.h"

Stack::Stack(){
    this->stack_pointer = nullptr;
}

Stack::~Stack(){
    item *p1;
    item *p2;

    p1 = stack_pointer;
    while(p1 != nullptr){
        p2 = p1;
        p1 = p1->prev;
        p2->prev = nullptr;
        delete p2;
    }
}

void Stack::Push(std::string name, int value){
    item *new_stack = new item;
    new_stack->name = name;
    new_stack-> value = value;
    if(stack_pointer == nullptr){
        stack_pointer = new_stack;
        stack_pointer->prev = nullptr;
    }else{
        new_stack->prev = stack_pointer;
        stack_pointer = new_stack;
    }
}

void Stack::read_item(item *r){
    std::cout << "---------------" << std::endl;
    std::cout << "name: " << r->name << std::endl;
    std::cout << "value: " << r->value << std::endl;
    std::cout << "---------------" << std::endl;
}

void Stack::Pop(){
    if(stack_pointer != nullptr){
    item *temp_ptr = stack_pointer;
    read_item(temp_ptr);
    stack_pointer = stack_pointer->prev;
    temp_ptr->prev = nullptr;
    delete temp_ptr;
    }else{
        std::cout << "Stack Empty" << std::endl;
    }
}

void Stack::Print(){
    item *temp_ptr = stack_pointer;
    while(temp_ptr != nullptr){
        read_item(temp_ptr);
        temp_ptr = temp_ptr->prev;
    }
}