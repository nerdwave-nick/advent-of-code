#include <iostream>
#include <string>
#include <vector>

#include "common.h"

const std::vector<std::string> lettered_digits = {
    "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

struct DigitWithPos {
    int digit;
    int pos;
};

std::vector<DigitWithPos> get_strdigit_in_substr(std::string const& line) {
    std::vector<DigitWithPos> rv = {};
    int pos;
    for (int i = 0; i < lettered_digits.size(); i++) {
        pos = -1;
        while ((pos = line.find(lettered_digits[i], pos + 1)) !=
               std::string::npos) {
            rv.push_back({i + 1, pos});
        }
    }
    return rv;
}

int get_first_digit(std::string const& line) {
    int count = 0, index = 0;
    char c;
    for (int i = 0; i < line.size(); i++) {
        c = line[i];
        if (c > '/' && c < ':') {
            count = c - 48;
            index = i;
            break;
        }
    }
    std::vector<DigitWithPos> digits =
        get_strdigit_in_substr(line.substr(0, index));
    int lowest_index = line.size();
    for (auto& digit : digits) {
        if (digit.pos < lowest_index) {
            lowest_index = digit.pos;
            count = digit.digit;
        }
    }

    return count * 10;
}

int get_last_digit(std::string const& line) {
    int count = 0, index = line.size();
    char c;
    for (int i = line.size() - 1; i >= 0; i--) {
        c = line[i];
        if (c > '/' && c < ':') {
            count = c - 48;
            index = i;
            break;
        }
    }
    std::vector<DigitWithPos> digits =
        get_strdigit_in_substr(line.substr(index, line.size() - index));
    int highest_index = 0;
    for (auto& digit : digits) {
        if (digit.pos >= highest_index) {
            highest_index = digit.pos;
            count = digit.digit;
        }
    }

    return count;
}

int get_line_value(std::string const& line) {
    int c1 = get_first_digit(line);
    int c2 = get_last_digit(line);
    int rv = c1 + c2;
    return rv;
}

int main() {
    auto input = get_input_from_stdin();
    int cum = 0;
    for (auto& line : input) {
        cum += get_line_value(line);
    }
    std::cout << cum << std::endl;
    return 0;
}