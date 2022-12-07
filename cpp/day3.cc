#include <iostream>
#include <unordered_set>
#include <filesystem>
#include <cxxopts.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <istream>
#include <sstream>

namespace fs = std::filesystem;

std::vector<std::string> read_lines(const fs::path & fp) {

    std::vector<std::string> lines;
    std::ifstream input_file(fp.c_str());
    std::copy(std::istream_iterator<std::string>(input_file),
        std::istream_iterator<std::string>(),
        std::back_inserter(lines)
    );

    return lines;
}

inline int get_priority(char c) {
    return c > '`' ? c - '`' : c - '@' + 26;
}

int part_1(const std::vector<std::string> & lines) {
    int val = 0;
    for (const auto & line : lines) {
        std::unordered_set<char> first_compartment;
        std::unordered_set<char> seen;

        for (size_t i = 0; i < line.size(); ++i) {
            if (i < (line.size() / 2))
            {
                first_compartment.insert(line.at(i));
            }
            else
            {
                if (first_compartment.find(line.at(i)) != first_compartment.end()
                    && seen.find(line.at(i)) == seen.end())
                {
                    val += get_priority(line.at(i));
                    seen.insert(line.at(i));
                }
            }
        }
    }
    return val;
}

int part_2(const std::vector<std::string> & lines) {
    int val = 0;
    for (size_t i = 0; i < lines.size() / 3; ++i) {
        int idx = i * 3;
        std::unordered_set<char> badge_candidate;
        std::unordered_set<char> candidate_2;

        // TODO: too ugly, but won't fix later
        for (const auto c : lines.at(idx)) {
            badge_candidate.insert(c);
        }

        for (const auto c : lines.at(idx + 1)) {
            if (badge_candidate.find(c) != badge_candidate.end()) {
                candidate_2.insert(c);
            }
        }

        for (const auto c : lines.at(idx + 2)) {
            if (candidate_2.find(c) != candidate_2.end()) {
                val += get_priority(c);
                break;
            }
        }
    }

    return val;
}

int main(int argc, char** argv) {
    cxxopts::Options options("day 2", "Day one AoC on elf calories");
    options.add_options()
        ("i,input", "Input file directory", cxxopts::value<std::string>());
    auto cli_results = options.parse(argc, argv);

    fs::path input_dir(cli_results["input"].as<std::string>());
    input_dir = fs::absolute(input_dir);
    if (!fs::exists(input_dir)) {
        std::cout << "Input file not found: " << cli_results["input"].as<std::string>() << std::endl;
        return 1;
    }

    const auto inputs = read_lines(input_dir);

    int out = part_1(inputs);
    std::cout << "Part 1: "  << out << std::endl;
    std::cout << "Part 2: " << part_2(inputs) << std::endl;

    return 0;
}