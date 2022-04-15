//
// Created by btobab on 2022/3/24.
//

#include <new_sequence.h>

bool AbsNumSeq::check(int pos) const {
    if (pos < 0 || pos >= _elems.size()) {
        return false;
    } else {
        return true;
    }
}

int AbsNumSeq::elem(int pos) const {
    return _elems[pos - 1];
}

AbsNumSeq::~AbsNumSeq() {
    std::vector<int>().swap(_elems);
    std::cout << "deconstruct a AbsNumSeq \n";
}

bool AbsNumSeq::empty() const {
    return _elems.empty();
}

bool AbsNumSeq::full() const {
    return _elems.size() == _elems.max_size();
}

Fibonacci::~Fibonacci() {
    std::vector<int>().swap(_elems);
    std::cout << "deconstruct a Fibonacci sequence \n";
}

void Fibonacci::gen_seq(int pos) {
    if (empty()) {
        _elems.push_back(1);
        _elems.push_back(1);
    }
    for (int ix = static_cast<int>(_elems.size()); ix < pos; ++ix) {
        _elems.push_back(_elems[ix - 2] + _elems[ix - 1]);
    }
}

void Fibonacci::print() {
    std::cout << "the elements of Fibonacci are: \n";
    for (int ix = 0; ix < _elems.size(); ++ix) {
        std::cout << (ix % 10 ? "\t" : "\n\t");
        std::cout << _elems[ix];
    }
}

int Fibonacci::elem(int pos) {
    if (pos < 0) {
        std::cerr << "position is invalid";
    } else if (pos >= _elems.size()) {
        gen_seq(pos);
    }
    return _elems[pos - 1];
}


