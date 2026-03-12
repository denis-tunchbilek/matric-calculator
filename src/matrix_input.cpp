#include "matrix_input.h"
#include <cctype>
#include <sstream>
#include <string>
#include "errors.h"

namespace {

    std::string trim(const std::string& s) {
        std::size_t begin = 0;
        while (begin < s.size() && std::isspace(static_cast<unsigned char>(s[begin]))) {
            ++begin;
        }

        std::size_t end = s.size();
        while (end > begin && std::isspace(static_cast<unsigned char>(s[end - 1]))) {
            --end;
        }

        return s.substr(begin, end - begin);
    }

    std::string readAll(std::istream& in) {
        std::ostringstream buffer;
        buffer << in.rdbuf();
        return buffer.str();
    }

}

Matrix MatrixInput::read(std::istream& in) {
    const std::string rawText = readAll(in);
    const std::string text = trim(rawText);

    if (text.empty()) {
        throw ParseError("empty input");
    }

    throw ParseError("Matrix parser is not implemented yet");
}