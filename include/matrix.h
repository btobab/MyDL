//
// Created by btobab on 2022/3/18.
//

#ifndef EFFECTIVE_C___MATRIX_H
#define EFFECTIVE_C___MATRIX_H

#include <vector>

class Matrix {

public:
    int _row, _column;

    explicit Matrix() : _row(0), _column(0) {};

    Matrix(const std::vector<float> &vec, int row, int column);

    Matrix(float val, int row, int column);

    Matrix(int row, int column, float mean = 0.0, float std = 1.0);

    Matrix(const Matrix &);

    Matrix &operator=(const Matrix &rhs);

    void print() const;

    Matrix &T();

    static Matrix &eye(int);

    friend Matrix &operator+(Matrix &lhs, Matrix &rhs);

    friend Matrix &operator*(Matrix &lhs, Matrix &rhs);

    friend Matrix &operator-(Matrix &lhs, Matrix &rhs);

    friend Matrix &operator/(Matrix &lhs, Matrix &rhs);

    Matrix &operator-();

    Matrix &operator+=(Matrix &rhs);

    Matrix &operator-=(Matrix &rhs);

    Matrix &operator*=(Matrix &rhs);

    Matrix &operator/=(Matrix &rhs);

    float operator()(int, int);

    Matrix &broadcast(bool, int);

    //std::vector<float> &getVec();

    Matrix &inv();

private:
    std::shared_ptr<std::vector<float> > _spv;
};

#endif //EFFECTIVE_C___MATRIX_H
