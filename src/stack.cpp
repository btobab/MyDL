//
// Created by btobab on 2022/3/24.
//

#include <stack.h>

int Abs_stack::size() {
    return _elem.size();
}

bool Abs_stack::empty() {
    return _elem.empty();
}

bool Abs_stack::full() {
    return _elem.size() == _elem.max_size();
}

int Abs_stack::peek() {
    return _elem.back();
}

void Abs_stack::print() {
    std::cout << "It's Abs_stack \n"
    << "elements are \n";
    for (int i = 0; i < _elem.size(); ++i) {
        std::cout << _elem[i] << " ";
    }
}

void Abs_stack::pop() {
    _elem.pop_back();
}

void Abs_stack::push(int rhs) {
    _elem.push_back(rhs);
}

void LIFO_Stack::print() {
    std::cout << "It's LIFO_Stack\n"
            << "elements are \n";
    for (int i = 0; i < _elem.size(); ++i) {
        std::cout << _elem[i] << " ";
    }
}

void Peekback_Stack::print() {
    std::cout << "It's Peekback_Stack\n"
            << "elements are \n";
    for (int i = 0; i < _elem.size(); ++i) {
        std::cout << _elem[i] << " ";
    }
}

int Peekback_Stack::peek(int ix) {
    if (ix > 0 && ix < _elem.size()) {
        return _elem[ix - 1];
    }
}



