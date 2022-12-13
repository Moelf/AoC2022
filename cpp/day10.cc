#include "utils.h"
#include "cxxopts.hpp"
#include <vector>

int part_1(const std::vector<std::string> & ins) {
    int cycle_count = 1;
    int reg = 1;
    int score = 0;

    size_t ins_count = 0;
    bool wait = false;
    int buffered_add = -1;
    std::vector<std::vector<char>> crt_screen(6, std::vector<char>(40, '.'));
    while (ins_count < ins.size()) {
        if (((cycle_count - 20) % 40) == 0) {
            score += cycle_count * reg;
        }

        int row = (cycle_count - 1) / 40;
        int col = (cycle_count - 1) % 40;
        int sprite_col = reg % 40;
        if (std::abs(sprite_col - col) <= 1) {
            crt_screen.at(row).at(col) = '#';
        }
        
        if (wait) {
            ++cycle_count;
            wait = false;
            reg += buffered_add;
            continue;
        }

        std::string cmd = ins.at(ins_count++);
        if (cmd == "noop") {
        } else {
            std::string num = cmd.substr(cmd.find(" ") + 1, cmd.size() - cmd.find(" "));
            wait = true;
            buffered_add = std::stoi(num);
        }
        cycle_count += 1;
    }

    for (auto v : crt_screen) {
        for (auto c : v) {
            std::cout << c;
        }
        std::cout << std::endl;
    }

    return score;
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

    auto lines = read_lines(input_dir);
    std::cout << "P1 score: \n" << part_1(lines) << std::endl;
}
