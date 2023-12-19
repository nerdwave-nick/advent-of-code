#include "common.h"

#include <iostream>
std::vector<std::string> get_input_from_stdin() {
    std::vector<std::string> lines;
    for (std::string l; getline(std::cin, l);) {
        lines.push_back(l);
    }
    return lines;
}