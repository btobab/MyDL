//
// Created by btobab on 2022/3/17.
//

#ifndef EFFECTIVE_C___SEQITER_H
#define EFFECTIVE_C___SEQITER_H
#include <vector>
#include "numSequence.h"

class SeqIter {
public:
    explicit SeqIter(int pos = 0): _pos(pos) {}
    bool operator==(const SeqIter& rs) const;
    bool operator!=(const SeqIter& rs) const;
    friend SeqIter& operator+(SeqIter&lhs, SeqIter& rhs);
    friend SeqIter& operator-(SeqIter&lhs, SeqIter& rhs);
    SeqIter& operator++();
    SeqIter operator++(int);
    friend int operator*(SeqIter& rhs);
private:
    int _pos;
};

#endif //EFFECTIVE_C___SEQITER_H
