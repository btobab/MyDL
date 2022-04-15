//
// Created by btobab on 2022/3/19.
//

#include <matrix_grad.h>
#include <iostream>
#include <vector>
#include <set>

int Matrix_grad::num = 0;

//std::vector<int> Matrix_grad::ma_vec;
//std::set<int> Matrix_grad::ma_set;
std::vector<Matrix_grad *> Matrix_grad::pmag_vec;


Matrix_grad::Matrix_grad() {
    _ma = Matrix();
    id = num++;
}

Matrix_grad::Matrix_grad(const std::vector<float> &vec, int row, int column) {
    _ma = Matrix(vec, row, column);
    id = num++;
}

Matrix_grad::Matrix_grad(int row, int column, float mean, float std) {
    _ma = Matrix(row, column, mean, std);
    id = num++;
}

Matrix_grad::Matrix_grad(const Matrix_grad &mag) {
    _ma = mag._ma;
    id = mag.id;
    std::vector<grad>().swap(_ga_vec);
    _ga_vec.insert(_ga_vec.begin(), mag._ga_vec.begin(), mag._ga_vec.end());
}

Matrix_grad &Matrix_grad::operator=(const Matrix_grad &rhs) {
    _ma = rhs._ma;
    id = rhs.id;
    std::vector<grad>().swap(_ga_vec);
    _ga_vec.insert(_ga_vec.begin(), rhs._ga_vec.begin(), rhs._ga_vec.end());
    return *this;
}

Matrix_grad::Matrix_grad(const Matrix &rhs) {
    _ma = Matrix(rhs);
    id = num++;
}

Matrix_grad::Matrix_grad(float val, int row, int column) {
    _ma = Matrix(val, row, column);
    id = num++;
}

Matrix_grad::~Matrix_grad() {
    std::vector<grad>().swap(_ga_vec);
}

bool Matrix_grad::find_tar(int mid, int &pos) {
    for (int i = 0; i < _ga_vec.size(); ++i) {
        if (_ga_vec[i].tar == mid) {
            pos = i;
            return true;
        }
    }
    return false;
}

Matrix_grad *Matrix_grad::find_mag(int mag_id) {
    int len = (int) pmag_vec.size();
    Matrix_grad *pmag = nullptr;
    for (int i = 0; i < len; ++i) {
        if (pmag_vec[i]->id == mag_id) {
            pmag = pmag_vec[i];
            return pmag;
        }
    }
    return pmag;
}

void Matrix_grad::add_mag(Matrix_grad &rhs) {
    if (std::find(pmag_vec.begin(), pmag_vec.end(), &rhs) == pmag_vec.end()) {
        Matrix_grad::pmag_vec.push_back(&rhs);
    }
}

Matrix_grad &operator+(Matrix_grad &lhs, Matrix_grad &rhs) {
    auto *tmp = new Matrix_grad(lhs._ma + rhs._ma);
    auto *ga = new Matrix_grad::grad();
    ga->tar = tmp->id;
    ga->gradient = Matrix::eye(lhs._ma._row);
    lhs._ga_vec.push_back(*ga);

    ga->gradient = Matrix::eye(rhs._ma._row);
    rhs._ga_vec.push_back(*ga);

    Matrix_grad::add_mag(lhs);
    Matrix_grad::add_mag(rhs);
    return *tmp;
}

Matrix_grad &Matrix_grad::operator+=(Matrix_grad &rhs) {
    *this = *this + rhs;
    return *this;
}

Matrix_grad &Matrix_grad::operator-() {
    auto pmag = new Matrix_grad(-_ma);
    Matrix_grad::grad tga;
    for (int ix = 0; ix < _ga_vec.size(); ++ix) {
        tga = _ga_vec[ix];
        tga.gradient = -tga.gradient;
        pmag->_ga_vec.push_back(tga);
    }
    return *pmag;
}

Matrix_grad &operator-(Matrix_grad &lhs, Matrix_grad &rhs) {
    auto *tmp = new Matrix_grad(lhs._ma - rhs._ma);
    auto *ga = new Matrix_grad::grad();
    ga->tar = tmp->id;

    ga->gradient = Matrix::eye(lhs._ma._row);
    lhs._ga_vec.push_back(*ga);

    ga->gradient = - Matrix::eye(rhs._ma._row);
    rhs._ga_vec.push_back(*ga);

    Matrix_grad::add_mag(lhs);
    Matrix_grad::add_mag(rhs);
    return *tmp;
}

Matrix_grad &Matrix_grad::operator-=(Matrix_grad &rhs) {
    *this = *this - rhs;
    return *this;
}

Matrix_grad &operator*(Matrix_grad &lhs, Matrix_grad &rhs) {
    Matrix_grad::grad ga;
    auto tmp = new Matrix_grad(0.0, lhs._ma._row, rhs._ma._column);
    tmp->_ma = lhs._ma * rhs._ma;
    ga.tar = tmp->id;

    ga.gradient = rhs._ma.T();
    lhs._ga_vec.push_back(ga);

    ga.gradient = lhs._ma.T();
    rhs._ga_vec.push_back(ga);

    Matrix_grad::add_mag(lhs);
    Matrix_grad::add_mag(rhs);
    return *tmp;
}

Matrix_grad &Matrix_grad::operator*=(Matrix_grad &rhs) {
    *this = *this * rhs;
    return *this;
}

Matrix_grad &operator/(Matrix_grad &lhs, Matrix_grad &rhs) {
    Matrix_grad::grad ga;
    Matrix tma = rhs._ma.inv().T();
    auto tmag = new Matrix_grad();
    tmag->_ma = lhs._ma / rhs._ma;
    ga.tar = tmag->id;

    ga.gradient = tma;
    lhs._ga_vec.push_back(ga);

    ga.gradient = - tma * tma * lhs._ma.T();
    rhs._ga_vec.push_back(ga);

    Matrix_grad::add_mag(lhs);
    Matrix_grad::add_mag(rhs);
    return *tmag;
}

Matrix_grad &Matrix_grad::operator/=(Matrix_grad &rhs) {
    *this = *this / rhs;
    return *this;
}

float Matrix_grad::operator()(int i, int j) {
    return _ma(i, j);
}

void Matrix_grad::print_all() {
    std::cout << "the matrix # " << id << " is :" << std::endl;
    _ma.print();
    for (int ix = 0; ix < _ga_vec.size(); ++ix) {
        std::cout << "the derivation of Matrix # " << _ga_vec[ix].tar << " to Matrix # " << id << " is: \n";
        _ga_vec[ix].gradient.print();
    }
}

void Matrix_grad::print_matrix() {
    _ma.print();
}

Matrix_grad &Matrix_grad::T() {
    auto mag = new Matrix_grad();
    mag->_ma = _ma.T();
    for (int i = 0; i < _ga_vec.size(); ++i) {
        grad tga;
        tga.tar = _ga_vec[i].tar;
        tga.gradient = _ga_vec[i].gradient.T();
        mag->_ga_vec.push_back(tga);
    }
    return *mag;
}

void Matrix_grad::forward() {
    Matrix_grad *ptmag, *tmag;
    Matrix_grad::grad tga, tmp;
    Matrix tma, next_ma;
    int cur_id, pos;
    for (int ix = 0; ix < Matrix_grad::pmag_vec.size(); ++ix) {
        ptmag = pmag_vec[ix];
        cur_id = ptmag->id;
        std::vector<grad> &ga_vec = ptmag->_ga_vec;
        for (int j = 0; j < ga_vec.size(); ++j) {
            tga = ga_vec[j];
            tmp.tar = tga.tar;
            tmp.gradient = tga.gradient;
            while ((tmag = Matrix_grad::find_mag(tga.tar))) {
                tmp.gradient *= tmag->_ga_vec[0].gradient;
                tmp.tar = tmag->_ga_vec[0].tar;
                tga = tmag->_ga_vec[0];
            }
            if (!ptmag->find_tar(tmp.tar, pos)) {
                ga_vec.erase(ga_vec.begin() + j);
                ga_vec.push_back(tmp);
            } else {
                ga_vec[pos].gradient = tmp.gradient;
            }
        }
    }
}

void Matrix_grad::update(float lr) {
    Matrix m_lr = Matrix(lr, _ma._column, _ma._column);
    _ma = _ma - _ga_vec[0].gradient * m_lr;
}
