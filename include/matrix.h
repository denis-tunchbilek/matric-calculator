#ifndef MATRIC_CALCULATOR_MATRIX_H
#define MATRIC_CALCULATOR_MATRIX_H

#pragma once
#include <vector>
#include <stdexcept>

class Matrix {
private:
    int rows_, cols_;
    std::vector<double> data_;
public:
    Matrix() : rows_(0), cols_(0) {}
    Matrix(int rows, int cols);

    explicit Matrix(std::vector<std::vector<double>> data);

    int rows() const { return rows_; }
    int cols() const { return cols_; }

    double& at(int r, int c);
    double  at(int r, int c) const;
};

#endif //MATRIC_CALCULATOR_MATRIX_H