//
// Created by btobab on 2022/3/24.
//

#ifndef EFFECTIVE_C___STACK_H
#define EFFECTIVE_C___STACK_H

#include <vector>
#include <iostream>


class Abs_stack {
public:
    void pop();
    void push(int);
    int size();
    bool empty();
    bool full();
    int peek();
    virtual void print();
protected:
    std::vector<int> _elem;
};

class LIFO_Stack: public Abs_stack {
public:
    LIFO_Stack() {
        std::cout << "creating a LIFO_Stack\n";
    }

    ~LIFO_Stack() {
        std::cout << "deconstruct a LIFO_Stack\n";
    }
    void print() override;
};

class Peekback_Stack: public Abs_stack {
public:
    Peekback_Stack() {
        std::cout << "creating a Peekback_Stack\n";
    }
    ~Peekback_Stack() {
        std::cout << "deconstruct a Peekback_Stack\n";
    }

    void print() override;

    int peek(int);

};


#endif //EFFECTIVE_C___STACK_H
