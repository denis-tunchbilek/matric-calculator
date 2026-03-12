#include "matrix.h"

Matrix::Matrix(int rows, int cols) : rows_(rows), cols_(cols), data_(rows * cols, 0.0)
{
    if (rows < 0 || cols < 0) {
        throw std::invalid_argument("Matrix dimension cannot be negative");
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
            throw std::invalid_argument("Matrix rows have inconsistent lengths");
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