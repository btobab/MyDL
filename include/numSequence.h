//
// Created by btobab on 2022/3/16.
//

#ifndef EFFECTIVE_C___NUMSEQUENCE_H
#define EFFECTIVE_C___NUMSEQUENCE_H

#include <iostream>
#include <string>
#include <vector>

class SeqIter;

class NumSequence {
public:
    typedef void (NumSequence::* PtrType)(int);

    explicit NumSequence(int beg_pos = 1, int length = 1):
            _beg_pos(beg_pos > 0 ? beg_pos : 1),
            _length(length > 0 ? length : 1),
            _next(_length - 1) {
        v1 = new std::vector<int>(beg_pos);
        v2 = new std::vector<int>(beg_pos);
        v3 = new std::vector<int>(beg_pos);
        seq_arr = new std::vector<int>*[3] {v1, v2 ,v3};
    }

    ~NumSequence() {
        std::vector<int>().swap(*v1);
        std::vector<int>().swap(*v2);
        std::vector<int>().swap(*v3);
    }

    inline bool check_var(int pos) {
        if (pos < 0) {
            std::cerr << "position is invalid";
            return false;
        } else if (pos <= _pv->size()) {
            return false;
        } else {
            return true;
        }
    }

    void seq_k1(int pos);

    void seq_k2(int pos);

    void seq_k3(int pos);

    bool set_sequence(int ix);

    int get_elem(int pos);

    void gen_seq(int pos);

    void print();


    friend int operator*(SeqIter& rhs);

    SeqIter& begin();

    SeqIter& end();

    enum buf {
        k1, k2, k3
    };
private:
    int _beg_pos, _length, _next;
    static const int fun_num = 3;
    std::vector<int> *v1, *v2, *v3;
    std::vector<int> **seq_arr;
    static std::vector<int> *_pv;
    PtrType _pf;
    constexpr static NumSequence::PtrType fun_pool[fun_num] = {&NumSequence::seq_k1, &NumSequence::seq_k2,
                                                               &NumSequence::seq_k3};
};



#endif //EFFECTIVE_C___NUMSEQUENCE_H
