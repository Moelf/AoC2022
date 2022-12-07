#include <iostream>
#include <vector>
#include <cxxopts.hpp>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <istream>
#include <string>
#include <numeric>
#include <queue>

namespace fs = std::filesystem;
using ElfBucket = std::vector<int>;

std::vector<ElfBucket> read_list_to_sum(const fs::path & fp) {
    std::string line;
    std::ifstream myfile(fp.c_str());
    std::vector<ElfBucket> ret_data;
    ElfBucket data;
    while (getline(myfile, line)) {
        if (line != "\0") {
            data.push_back(std::stoi(line));
        } else {
            ret_data.emplace_back(data);
            data.clear();
        }
    }

    myfile.close();
    return ret_data;
}

int max_food_bucket(const std::vector<ElfBucket> & bk) {
    int max_food = 0;
    for (const ElfBucket & b : bk) {
        max_food = std::max(std::accumulate(b.begin(), b.end(), 0), max_food);
    }

    return max_food;
}

int top_three_food(const std::vector<ElfBucket> & bk) {
    std::priority_queue<int, std::vector<int>, std::greater<int> > top_list;
    for (const ElfBucket & b : bk) {
        int kcal = std::accumulate(b.begin(), b.end(), 0);
        top_list.push(kcal);
        if (top_list.size() > 3) top_list.pop();
    }

    int sum = 0;
    while (!top_list.empty()) {
        sum += top_list.top();
        top_list.pop();
    }

    return sum;
}


int main(int argc, char** argv) {
    cxxopts::Options options("day 1", "Day one AoC on elf calories");
    options.add_options()
        ("i,input", "Input file directory", cxxopts::value<std::string>());
    auto cli_results = options.parse(argc, argv);

    fs::path input_dir(cli_results["input"].as<std::string>());
    input_dir = fs::absolute(input_dir);
    std::cout << input_dir.string() << std::endl;
    if (!fs::exists(input_dir)) {
        std::cout << "Input file not found: " << cli_results["input"].as<std::string>() << std::endl;
        return 1;
    }

    auto food_list = read_list_to_sum(input_dir);

    auto max_food = max_food_bucket(food_list);

    std::cout << "Most food: " << max_food << std::endl;

    auto max_four_sum = top_three_food(food_list);
    
    std::cout << max_four_sum << std::endl;

    return 0;
}

