#ifndef STACK_H
#define STACK_H

#include <string>

class Stack{
private:
    struct item
    {
        std::string name;
        int value;
        item *prev;
    };

    item *stack_pointer;

public:
    void Push(std::string name, int value);
    void Pop();
    void read_item(item *r);
    void Print(); // will print the current contents of the stack

    Stack();
    ~Stack();
};

#endif /*STACK_H*/