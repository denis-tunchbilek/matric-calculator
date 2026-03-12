#ifndef MATRIC_CALCULATOR_MATRIX_INPUT_H
#define MATRIC_CALCULATOR_MATRIX_INPUT_H
#pragma once
#include <istream>
#include "matrix.h"

class MatrixInput {
public:
    Matrix read(std::istream& in);
};
#endif //MATRIC_CALCULATOR_MATRIX_INPUT_H