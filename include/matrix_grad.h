//
// Created by btobab on 2022/3/19.
//

#ifndef EFFECTIVE_C___MATRIX_GRAD_H
#define EFFECTIVE_C___MATRIX_GRAD_H

#include "matrix.h"
#include <set>
#include <map>
#include <vector>

class Matrix_grad {
public:
    struct grad {
        int tar;
        Matrix gradient;
    };

    Matrix_grad();

    Matrix_grad(const std::vector<float> &, int row, int column);

    Matrix_grad(float val, int row, int column);

    Matrix_grad(int row, int column, float mean = 0.0, float std = 1.0);

    Matrix_grad(const Matrix_grad &);

    explicit Matrix_grad(const Matrix &);

    ~Matrix_grad();

    void print_all();

    void print_matrix();

    bool find_tar(int id, int &);

    static Matrix_grad *find_mag(int);

    friend Matrix_grad &operator+(Matrix_grad &lhs, Matrix_grad &rhs);

    friend Matrix_grad &operator-(Matrix_grad &lhs, Matrix_grad &rhs);

    Matrix_grad &operator-();

    friend Matrix_grad &operator*(Matrix_grad &lhs, Matrix_grad &rhs);

    friend Matrix_grad &operator/(Matrix_grad &lhs, Matrix_grad &rhs);

    Matrix_grad &operator+=(Matrix_grad &rhs);

    Matrix_grad &operator-=(Matrix_grad &rhs);

    Matrix_grad &operator*=(Matrix_grad &rhs);

    Matrix_grad &operator/=(Matrix_grad &rhs);

    Matrix_grad &operator=(const Matrix_grad &rhs);

    float operator()(int, int);

    Matrix_grad &T();

    static void add_mag(Matrix_grad &rhs);

    static void forward();

    void update(float lr);

private:
    static std::vector<Matrix_grad *> pmag_vec;

    // Matrix _ma;
    std::shared_ptr<Matrix> _spm;
    std::vector<grad> _ga_vec;
    int id;
    static int num;
};


#endif //EFFECTIVE_C___MATRIX_GRAD_H
