#include <iostream>
#include <string>
#include <vector>

#include "common.h"

int get_line_value(std::string const& line) {
    int c1 = -1, c2;
    for (char const& c : line) {
        if (c > '/' && c < ':') {
            if (c1 < 0) {
                c1 = c - 48;
            }
            c2 = c - 48;
        }
    }
    int rv = c1 * 10 + c2;
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
