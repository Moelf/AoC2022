#include <iostream>
#include <string>
#include <vector>
#include <cxxopts.hpp>
#include <filesystem>
#include <fstream>
#include <istream>
#include <unordered_map>

namespace fs = std::filesystem;
using Path = std::vector<std::string>;
using DirSize = std::unordered_map<std::string, size_t>;

void update_all_parents(const Path & path, DirSize & dir_size, size_t new_file_size) {
    std::string dir = "";
    for (const auto p : path) {
        dir += "|" + p;
        auto iter = dir_size.find(dir);
        if (iter != dir_size.end()) {
            dir_size[dir] += new_file_size;
        } else {
            dir_size[dir] = new_file_size;
        }
    }
    return;
}

void parse_action(const std::string & cmd, std::vector<std::string> & curr_dir, std::unordered_map<std::string, size_t> & dir_size) {
    if (cmd == "$ ls") {
        // do nothing
    } else if (cmd == "$ cd .."){
        curr_dir.pop_back();
    } else {
        std::string token = cmd.substr(0, cmd.find(" "));
        if (token == "$") {
            std::string new_dir(cmd.begin() + 5, cmd.end());
            curr_dir.push_back(new_dir);
        } else if (token == "dir") {
            // Do nothing
        } else {
            size_t file_size = static_cast<size_t>(std::stoi(token));
            update_all_parents(curr_dir, dir_size, file_size);
        }
    }
}

DirSize propagate_filesystem(const fs::path & input) {
    std::vector<std::string> curr_directory;
    std::unordered_map<std::string, size_t> directory_size;

    std::string line;
    std::ifstream myfile(input.c_str());
    while (getline(myfile, line)) {
        parse_action(line, curr_directory, directory_size);
    }

    return directory_size;
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

    auto dir_log = propagate_filesystem(input_dir);

    size_t output_sum = 0;

    for (const auto iter : dir_log) {
        if (iter.second < 100000) {
            // std::cout << iter.first << ", " << iter.second << std::endl;
            output_sum += iter.second;
        }
    }
    std::cout << "Part 1: " << output_sum << std::endl;

    size_t total_space = dir_log["|/"];
    size_t req_size = total_space - (70000000 - 30000000);
    size_t min_size = std::numeric_limits<size_t>::max();

    for (const auto iter : dir_log) {
        if (iter.second > req_size) {
            min_size = std::min(min_size, iter.second);
        }
    }
    std::cout << "Part 2: " << min_size << std::endl;

    return 0;
}