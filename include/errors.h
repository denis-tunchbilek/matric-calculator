#ifndef MATRIC_CALCULATOR_ERRORS_H
#define MATRIC_CALCULATOR_ERRORS_H

#pragma once
#include <stdexcept>
#include <string>

struct ParseError : std::runtime_error {
    explicit ParseError(const std::string& msg)
        : std::runtime_error("ParseError: " + msg) {}
};


struct DimensionError : std::runtime_error {
    explicit DimensionError(const std::string& msg)
        : std::runtime_error("DimensionError: " + msg) {}
};

struct SingularError : std::runtime_error {
    explicit SingularError(const std::string& msg)
        : std::runtime_error("SingularError: " + msg) {}
};

struct EvalError : std::runtime_error {
    explicit EvalError(const std::string& msg)
        : std::runtime_error("EvalError: " + msg) {}
};

#endif //MATRIC_CALCULATOR_ERRORS_H