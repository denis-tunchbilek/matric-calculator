#include "matrix.h"

Matrix::Matrix(int rows, int cols) : rows_(rows), cols_(cols), data_(rows * cols, 0.0)
{
    if (rows < 0 || cols < 0) {
        throw DimensionError("Matrix dimension cannot be negative");
    }
}

Matrix::Matrix(std::vector<std::vector<double>> data) {
    if (data.empty()) {
        rows_ = cols_ = 0;
        return;
    }

    rows_ = static_cast<int>(data.size());
    cols_ = static_cast<int>(data[0].size());
    data_.reserve(rows_ * cols_);

    for (auto& row : data) {
        if (static_cast<int>(row.size()) != cols_) {
            throw DimensionError("Matrix rows have inconsistent lengths");
        }
        for (double v : row)
            data_.push_back(v);
    }
}

double& Matrix::at(int r, int c) {
    if (r < 0 || r >= rows_ || c < 0 || c >= cols_) {
        throw std::out_of_range("Matrix::at — index out of range");
    }
    return data_[r * cols_ + c];
}

double Matrix::at(int r, int c) const {
    if (r < 0 || r >= rows_ || c < 0 || c >= cols_) {
        throw std::out_of_range("Matrix::at — index out of range");
    }
    return data_[r * cols_ + c];
}
//---
Matrix Matrix::identity(int n) {
    Matrix result(n, n);
    for (int i = 0; i < n; ++i) {
        result.at(i, i) = 1.0;
    }
    return result;
}

Matrix Matrix::transpose() const {
    Matrix result(cols_, rows_);
    for (int r = 0; r < rows_; ++r) {
        for (int c = 0; c < cols_; ++c) {
            result.at(c, r) = at(r, c);
        }
    }
    return result;
}

Matrix Matrix::operator+(const Matrix& other) const {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
        throw DimensionError("operator+: matrices have incompatible dimensions");
    }
    Matrix result(rows_, cols_);
    for (int i = 0; i < rows_ * cols_; ++i) {
        result.data_[i] = data_[i] + other.data_[i];
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
        throw DimensionError("operator-: matrices have incompatible dimensions");
    }
    Matrix result(rows_, cols_);
    for (int i = 0; i < rows_ * cols_; ++i) {
        result.data_[i] = data_[i] - other.data_[i];
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (cols_ != other.rows_)
        throw DimensionError("operator*: incompatible dimensions for matrix multiplication");
    Matrix result(rows_, other.cols_);
    for (int r = 0; r < rows_; ++r) {
        for (int c = 0; c < other.cols_; ++c) {
            double sum = 0.0;
            for (int k = 0; k < cols_; ++k) {
                sum += at(r, k) * other.at(k, c);
            }
            result.at(r, c) = sum;
        }
        return result;
    }
}

Matrix Matrix::operator*(double scalar) const {
    Matrix result(rows_, cols_);
    for (int i = 0; i < rows_ * cols_; ++i) {
        result.data_[i] = data_[i] * scalar;
    }
    return result;
}