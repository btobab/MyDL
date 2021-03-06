//
// Created by btobab on 2022/3/18.
//
#include <iostream>
#include <random>
#include <vector>
#include <matrix.h>


Matrix::Matrix(const std::vector<float> &vec, int row, int column) {
    if (row > 0 && column > 0) {
        _spv = std::make_shared<std::vector<float> >(vec);
        _row = row;
        _column = column;
    } else {
        std::cerr << "argument is invalid";
    }
}

Matrix::Matrix(float val, int row, int column) {
    if (row >= 0 && column >= 0) {
        _row = row;
        _column = column;
        _spv = std::make_shared<std::vector<float> >(row * column, val);
    } else {
        std::cerr << "row or column is invalid";
    }
}

Matrix::Matrix(int row, int column, float mean, float std) {
    if (row > 0 && column > 0 && std >= 0) {
        std::default_random_engine generator;
        std::normal_distribution<float> distribution(mean, std);
        _row = row;
        _column = column;
        _spv = std::make_shared<std::vector<float> >(row * column);
        for (int i = 0; i < row * column; ++i) {
            _spv->at(i) = distribution(generator);
        }
    } else {
        std::cerr << "argument is invalid";
    }
}

Matrix::Matrix(const Matrix &rhs) {
    _spv = rhs._spv;
    _row = rhs._row;
    _column = rhs._column;
}

Matrix &Matrix::operator=(const Matrix &rhs) {
    _spv = rhs._spv;
    _row = rhs._row;
    _column = rhs._column;
    return *this;
}

void Matrix::print() const {
    std::cout << "row: " << _row << " column: " << _column << std::endl;
    std::cout << "elements of matrix: " << std::endl;
    for (int i = 0; i < _spv->size(); ++i) {
        std::cout << "\t";
        std::cout << _spv->at(i) << (!((i + 1) % _column) ? "\t\n" : "\t");
    }
}

float Matrix::operator()(int i, int j) const{
    if (i >= 0 && j >= 0) {
        return _spv->at(i * _column + j);
    } else {
        std::cerr << "argument is invalid";
        return 0.0;
    }
}

Matrix &Matrix::T() {
    std::vector<float> vec;
    auto ma = new Matrix(vec, _column, _row);
    for (int i = 0; i < _column; ++i) {
        for (int j = 0; j < _row; ++j) {
            ma->_spv->push_back(_spv->at(j * _column + i));
        }
    }
    return *ma;
}

Matrix &Matrix::broadcast(bool is_row, int val) const{
    auto tmp = new Matrix(*this);
    if (is_row) {
        tmp->_row = val;
        tmp->_spv->resize(tmp->_row * tmp->_column);
        for (int ix = 1; ix < tmp->_row; ++ix) {
            for (int j = 0; j < tmp->_column; ++j) {
                tmp->_spv->at(ix * tmp->_column + j) = tmp->_spv->at(j);
            }
        }
    } else {
        tmp->_column = val;
        tmp->_spv->resize(tmp->_row * tmp->_column);
        for (int ix = 1; ix < tmp->_column; ++ix) {
            for (int j = 0; j < tmp->_row; ++j) {
                tmp->_spv->at(ix * tmp->_row + j) = tmp->_spv->at(j);
            }
        }
    }
    return *tmp;
}


Matrix operator+(const Matrix &lhs, const Matrix &rhs) {
    Matrix lma, rma, *tmp;
    if (lhs._row == rhs._row && lhs._column == rhs._column) {
        lma = Matrix(lhs);
        rma = Matrix(rhs);
    } else {
        //std::cout << "the shape of lhs and rhs is not the same\n";
        if (lhs._column == rhs._column && lhs._row != rhs._row) {
            if (lhs._row == 1) {
                lma = lhs.broadcast(true, rhs._row);
                rma = Matrix(rhs);
            } else if (rhs._row == 1){
                lma = Matrix(lhs);
                rma = rhs.broadcast(true, lhs._row);
            }
        } else if (lhs._row == rhs._row && lhs._column != rhs._column) {
            if (lhs._column == 1) {
                lma = lhs.broadcast(false, rhs._column);
                rma = Matrix(rhs);
            } else if (rhs._column == 1) {
                lma = Matrix(lhs);
                rma = rhs.broadcast(false, lhs._column);
            }
        } else {
            std::cerr << "can not add lhs and rhs" << std::endl;
        }
    }
    int _row = lma._row, _column = rma._column;
    // tmp = new Matrix(lma);
    auto spv = std::make_shared<std::vector<float> >(*lma._spv);
    for (int i = 0; i < _row; ++i) {
        for (int j = 0; j < _column; ++j) {
            spv->at(i * _column + j) += rma._spv->at(i * _column + j);
        }
    }
    return Matrix(*spv, lma._row, lma._column);
}

Matrix &Matrix::operator+=(const Matrix &rhs) {
    *this = rhs + *this;
    return *this;
}

Matrix Matrix::operator-() const{
    std::vector<float>vec;
    vec.resize(_row * _column);
    for (int ix = 0; ix < _row * _column; ++ix) {
        vec[ix] = -_spv->at(ix);
    }
    return Matrix(vec, _row, _column);
}

Matrix operator-(const Matrix &lhs, const Matrix &rhs) {
    return lhs + (-rhs);
}


Matrix &Matrix::operator-=(const Matrix &rhs) {
    *this = *this - rhs;
    return *this;
}

Matrix operator*(const Matrix &lhs, const Matrix &rhs) {
    Matrix tmp, tma;
    if (lhs._column == rhs._row) {
        tmp = Matrix(lhs);
        tma = Matrix(rhs);
    } else {
        //std::cout << "the column of lhs != the row of rhs, thus broadcast matrix" << std::endl;
        if (lhs._column == 1) {
            tmp = lhs.broadcast(false, rhs._row);
            tma = Matrix(rhs);
        }
        else if (rhs._row == 1){
            tmp = Matrix(lhs);
            tma = rhs.broadcast(true, lhs._column);
        }
    }
    auto spv = std::make_shared<std::vector<float> >(tmp._row * tma._column);
    for (int i = 0; i < tmp._row; ++i) {
        for (int j = 0; j < tma._column; ++j) {
            float tmp_v = 0.0;
            for (int k = 0; k < tma._row; ++k) {
                tmp_v += tmp(i, k) * tma(k, j);
            }
            spv->at(i * tma._column + j) = tmp_v;
        }
    }
    return Matrix(*spv, tmp._row, tma._column);
}


Matrix &Matrix::operator*=(const Matrix &rhs) {
    *this = *this * rhs;
    return *this;
}


Matrix operator/(const Matrix &lhs, const Matrix &rhs) {
    return lhs * rhs.inv();
}

Matrix &Matrix::operator/=(const Matrix &rhs) {
    *this = *this / rhs;
    return *this;
}

Matrix &Matrix::eye(int row) {
    std::vector<float> vec;
    auto tma = new Matrix(vec, row, row);
    for (int i = 0; i < row * row; ++i) {
        if (i % row == i / row) {
            tma->_spv->push_back(1.0);
        } else {
            tma->_spv->push_back(0.0);
        }
    }
    return *tma;
}

Matrix Matrix::inv() const {
    int n = this->_row;
    float a[n][n], inv_a[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = (*this)(i, j);
        }
    }
    //?????????
    float l[n][n], u[n][n], c[n][n], ad_l[n][n], ad_u[n][n];
    memset(inv_a, 0, n * n * sizeof(float));
    memset(l, 0, n * n * sizeof(float));
    memset(u, 0, n * n * sizeof(float));
    memset(c, 0, n * n * sizeof(float));
    memset(ad_l, 0, n * n * sizeof(float));
    memset(ad_u, 0, n * n * sizeof(float));


    //LU??????
    for (int i = 0; i < n; i++)
        l[i][i] = 1;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i; j < n; j++) {
            float tem = 0;
            for (int k = 0; k < i; k++)
                tem += l[i][k] * u[k][j];
            u[i][j] = a[i][j] - tem;
        }
        for (int j = i + 1; j < n; j++) {
            float tem = 0;
            for (int k = 0; k < i; k++)
                tem += l[j][k] * u[k][i];
            l[j][i] = (a[j][i] - tem) / u[i][i];
        }
    }
    u[n - 1][n - 1] = a[n - 1][n - 1];
    for (int i = 0; i < n - 1; i++)
        u[n - 1][n - 1] -= l[n - 1][i] * u[i][n - 1];


    //U????????????
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j) ad_u[i][j] = 0;
            else if (i == j) {
                ad_u[i][j] = 1;
                for (int k = 0; k < n; k++)
                    if (k != j)
                        ad_u[i][j] *= u[k][k];
            } else if (j - i == 1) {
                ad_u[i][j] = -u[i][j];
                for (int k = 0; k < n; k++)
                    if (k != i && k != j)
                        ad_u[i][j] *= u[k][k];
            } else if (j - i >= 2) {
                float deltas_aii = 1;
                for (int k = 0; k < n; k++)
                    if (k < i || k > j)
                        deltas_aii *= u[k][k];
                int permutation[n];
                for (int t = 0; t < j - i; t++) permutation[t] = i + t + 1;
                float sum = 0;
                do {
                    int cnt = 0;
                    for (int t2 = 0; t2 < j - i; t2++)
                        for (int t3 = t2; t3 < j - i; t3++)
                            if (permutation[t3] < permutation[t2]) cnt++;
                    float mul = 1;
                    for (int t1 = i; t1 < j; t1++)
                        mul *= u[t1][permutation[t1 - i]];
                    if ((j - i + 1) % 2 == 0)mul *= -1;
                    if (cnt % 2 == 0) sum += mul;
                    else sum -= mul;
                } while (std::next_permutation(permutation, permutation + j - i));
                ad_u[i][j] = sum * deltas_aii;
            }
        }
    }
    float det_u = 1;
    for (int k = 0; k < n; k++) det_u *= u[k][k];
    if (det_u < 1e-16) {
        printf("????????????????????????????????????\n");
        Matrix ma = Matrix(-1.0, n, n);
        return ma;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ad_u[i][j] /= det_u;

    //l????????????
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j) ad_l[i][j] = 0;
            else if (i == j) {
                ad_l[i][j] = 1;
                for (int k = 0; k < n; k++)
                    if (k != j)
                        ad_l[i][j] *= l[k][k];
            } else if (i - j == 1) {
                ad_l[i][j] = -l[i][j];
                for (int k = 0; k < n; k++)
                    if (k != i && k != j)
                        ad_l[i][j] *= l[k][k];
            } else if (i - j >= 2) {
                float deltas_aii = 1;
                for (int k = 0; k < n; k++)
                    if (k < i || k > j)
                        deltas_aii *= l[i][i];
                int permutation[n];
                for (int t = 0; t < i - j; t++) permutation[t] = j + t + 1;
                float sum = 0;
                do {
                    int cnt = 0;
                    for (int t2 = 0; t2 < i - j; t2++)
                        for (int t3 = t2; t3 < i - j; t3++)
                            if (permutation[t3] < permutation[t2]) cnt++;
                    float mul = 1;
                    for (int t1 = j; t1 < i; t1++)
                        mul *= l[permutation[t1 - j]][t1];
                    if ((i - j + 1) % 2 == 0)mul *= -1;
                    if (cnt % 2 == 0) sum += mul;
                    else sum -= mul;
                } while (std::next_permutation(permutation, permutation + i - j));
                ad_l[i][j] = sum * deltas_aii;
            }
        }
    }
    float det_l = 1;
    for (int k = 0; k < n; k++) det_l *= l[k][k];
    if (det_u < 1e-16) {
        printf("????????????????????????????????????\n");
        Matrix ma = Matrix(-1.0, n, n);
        return ma;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ad_l[i][j] /= det_l;

    //??????a
    std::vector<float> vec1;
    for (int ix = 0; ix < n; ++ix) {
        for (int j = 0; j < n; ++j) {
            vec1.push_back(ad_l[ix][j]);
        }
    }
    Matrix ma1(vec1, n, n);
    std::vector<float> vec2;
    for (int ix = 0; ix < n; ++ix) {
        for (int j = 0; j < n; ++j) {
            vec2.push_back(ad_u[ix][j]);
        }
    }
    Matrix ma2(vec2, n, n);
    return Matrix(ma2 * ma1);
}