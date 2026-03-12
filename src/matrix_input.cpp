#include "matrix_input.h"

#include <sstream>
#include <string>

#include "errors.h"

Matrix MatrixInput::read(std::istream& in) {
    std::ostringstream buffer;
    buffer << in.rdbuf();
    const std::string text = buffer.str();

    if (text.empty()) {
        throw ParseError("empty input");
    }

    throw ParseError("Matrix parser is not implemented yet");
}