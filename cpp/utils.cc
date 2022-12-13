#include "utils.h"

std::vector<std::string> read_lines(const fs::path & fp) {
    std::vector<std::string> lines;
    std::ifstream input_file(fp.c_str());
    std::string line;
    while (getline(input_file, line)) {
        lines.push_back(line);
    }

    return lines;
}
