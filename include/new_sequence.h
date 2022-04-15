//
// Created by btobab on 2022/3/24.
//

#ifndef EFFECTIVE_C___NEW_SEQUENCE_H
#define EFFECTIVE_C___NEW_SEQUENCE_H

#include <vector>
#include <iostream>

class AbsNumSeq {
public:
    AbsNumSeq(int beg_pos, int length) : _beg_pos(beg_pos), _length(length) {
        std::cout << "construct a AbsNumSeq \n";
    }

    ~AbsNumSeq();

    bool check(int) const;

    virtual void gen_seq(int) = 0;

    int elem(int) const;

    virtual void print() = 0;

    bool empty() const;

    bool full() const;

protected:
    int _beg_pos, _length;
    std::vector<int> _elems;
};


class Fibonacci : public AbsNumSeq {
public:
    Fibonacci(int beg_pos = 0, int length = 1) : AbsNumSeq(beg_pos, length) {
        gen_seq(beg_pos + length);
        std::cout << "construct a Fibonacci Sequence \n";
    }

    ~Fibonacci();

    void gen_seq(int) override;

    void print() override;

    int elem(int);
};


#endif //EFFECTIVE_C___NEW_SEQUENCE_H
