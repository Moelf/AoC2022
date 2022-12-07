#include <iostream>
#include <string>
#include <cxxopts.hpp>
#include <filesystem>
#include <fstream>
#include <istream>
#include <unordered_map>

namespace fs = std::filesystem;

int part1(const std::string & input_key, int max_length = 4) {
    int ptr1 = 0; int ptr2 = 1;
    std::unordered_map<char, int> visited;
    visited[input_key.at(ptr1)] = 0;
    
    const int str_size = static_cast<int>(input_key.size());
    while (ptr2 < str_size) {
        auto iter = visited.find(input_key[ptr2]);
        if (iter != visited.end() && iter->second >= ptr1) {
            ptr1 = iter->second + 1;
            visited[input_key[ptr2]] = ptr2;
            ptr2++;
        } else {
            if (ptr2 - ptr1 == max_length - 1) {
                return ptr2 + 1;
            } else {
                visited[input_key[ptr2]] = ptr2;
                ptr2++;
            }
        }
    }

    return -1;
}

int main(int argc, char** argv) {
    cxxopts::Options options("day 6", "Day one AoC on elf calories");
    options.add_options()
        ("i,input", "Input file directory", cxxopts::value<std::string>());
    auto cli_results = options.parse(argc, argv);

    fs::path input_dir(cli_results["input"].as<std::string>());
    input_dir = fs::absolute(input_dir);
    if (!fs::exists(input_dir)) {
        std::cout << "Input file not found: " << cli_results["input"].as<std::string>() << std::endl;
        return 1;
    }

    std::ifstream file(input_dir.c_str());
    std::string line;
    getline(file, line);
    file.close();

    int result = part1(line);
    std::cout << "Part 1: " << result << std::endl;

    int result2 = part1(line, 14);
    std::cout << "Part 2: " << result2 << std::endl;

    return 0;
}