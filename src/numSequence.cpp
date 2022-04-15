//
// Created by btobab on 2022/3/16.
//

#include <numSequence.h>
#include <SeqIter.h>
#include <string>
#include <iostream>


std::vector<int>* NumSequence::_pv;

void NumSequence::seq_k1(int pos) {
    if (check_var(pos)) {
        for (int ix = (int) (*_pv).size(); ix <= pos; ++ix) {
            (*_pv).push_back(ix * 1);
        }
    }
}

void NumSequence::seq_k2(int pos) {
    if (check_var(pos)) {
        for (int ix = (int) (*_pv).size(); ix <= pos; ++ix) {
            (*_pv).push_back(ix * 2);
        }
    }
}

void NumSequence::seq_k3(int pos) {
    if (check_var(pos)) {
        for (int ix = (int) (*_pv).size(); ix <= pos; ++ix) {
            _pv->push_back(ix * 3);
        }
    }
}

bool NumSequence::set_sequence(int ix) {
    if (ix >= 0 && ix < fun_num){
        _pv = seq_arr[ix];
        _pf = NumSequence::fun_pool[ix];
        return true;
    } else {
        return false;
    }
}

void NumSequence::gen_seq(int pos) {
    if (check_var(pos)) {
        (this->*_pf)(pos);
    }
}

int NumSequence::get_elem(int pos) {
    if (check_var(pos)) {
        gen_seq(pos);
    }
    return (*_pv)[pos];
}

void NumSequence::print() {
    SeqIter iter = this->begin();
    while (iter != this->end()) {
        std::cout << *iter << "\t";
        ++iter;
    }
}

SeqIter& NumSequence::begin() {
    SeqIter *iter = new SeqIter(0);
    return *iter;
}

SeqIter& NumSequence::end() {
    SeqIter *iter = new SeqIter(NumSequence::_pv->size());
    return *iter;
}


