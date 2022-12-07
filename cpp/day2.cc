#include <iostream>
#include <unordered_map>
#include <filesystem>
#include <cxxopts.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <istream>
#include <sstream>

namespace fs = std::filesystem;
using Round = std::pair<char, char>;

std::vector<Round> parse_input(const fs::path & input) {
    std::string line;
    std::ifstream myfile(input.c_str());
    std::vector<Round> ret_data;
    while (getline(myfile, line) && (line.length() > 1)) {
        ret_data.emplace_back(line[0], line[2]);
    }

    return ret_data;
}

std::unordered_map<char, int> score {
    {'X', 1}, {'Y', 2}, {'Z', 3}
};

std::unordered_map<char, int> score_op {
    {'A', 1}, {'B', 2}, {'C', 3}
};

std::unordered_map<char, int> outcome {
    {'X', 0}, {'Y', 3}, {'Z', 6}
};

std::unordered_map<char, std::unordered_map<char, int>> match_lookup {
    {'X', {{'A', 3}, {'B', 0}, {'C', 6}}},
    {'Y', {{'A', 6}, {'B', 3}, {'C', 0}}},
    {'Z', {{'A', 0}, {'B', 6}, {'C', 3}}},
};

std::unordered_map<char, std::unordered_map<char, int>> match_lookup_p2 {
    {'A', {{'X', 3}, {'Y', 1}, {'Z', 2}}},
    {'B', {{'X', 1}, {'Y', 2}, {'Z', 3}}},
    {'C', {{'X', 2}, {'Y', 3}, {'Z', 1}}},
};


int single_round(const Round & r) {
    return score[r.second] + match_lookup[r.second][r.first];
}

int run_game(const std::vector<Round> & game) {
    int score = 0;
    for (const auto & r : game) {
        score += single_round(r);
    }
    return score;
}

int single_round_p2(const Round & r) {

    return match_lookup_p2[r.first][r.second] + outcome[r.second];
}

int run_game_part2(const std::vector<Round> & game) {
    int score = 0;
    for (const auto & r : game) {
        score += single_round_p2(r);
    }
    return score;
}


int main(int argc, char** argv) {
    cxxopts::Options options("day 1", "Day one AoC on elf calories");
    options.add_options()
        ("i,input", "Input file directory", cxxopts::value<std::string>());
    auto cli_results = options.parse(argc, argv);

    fs::path input_dir(cli_results["input"].as<std::string>());
    input_dir = fs::absolute(input_dir);
    if (!fs::exists(input_dir)) {
        std::cout << "Input file not found: " << cli_results["input"].as<std::string>() << std::endl;
        return 1;
    }

    const auto input = parse_input(input_dir);

    // for (const auto & p : input) {
    //     std::cout << p.first << ", " << p.second << "\n";
    // }
    // std::cout << std::endl;
    int output = run_game(input);
    std::cout << output << std::endl;
    int o2 = run_game_part2(input);
    std::cout << o2 << std::endl;

    return 0;
}