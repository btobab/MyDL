//
// Created by btobab on 2022/3/17.
//

#include <SeqIter.h>

bool SeqIter::operator==(const SeqIter& rs) const {
    return _pos == rs._pos;
}

bool SeqIter::operator!=(const SeqIter& rs) const {
    return _pos != rs._pos;
}

SeqIter& operator+(SeqIter&lhs, SeqIter& rhs) {
    SeqIter *tmp = new SeqIter();
    tmp->_pos = lhs._pos + rhs._pos;
    return *tmp;
}

SeqIter& operator-(SeqIter&lhs, SeqIter& rhs) {
    SeqIter *tmp = new SeqIter();
    tmp->_pos = lhs._pos - rhs._pos;
    return *tmp;
}

SeqIter& SeqIter::operator++() {
    _pos++;
    return *this;
}

SeqIter SeqIter::operator++(int) {
    SeqIter *tmp = new SeqIter(_pos);
    _pos++;
    return *tmp;
}

int operator*(SeqIter& rhs) {
    return (*NumSequence::_pv)[rhs._pos];
}
