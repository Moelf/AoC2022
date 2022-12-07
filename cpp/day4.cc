#include <vector>
#include "inputs/day4.hh"
#include <iostream>

bool check_contain(const std::pair<int, int> a, const std::pair<int, int> b) {
    bool a_contains = a.first <= b.first && a.second >= b.second;
    bool b_contains = a.first >= b.first && a.second <= b.second;

    return a_contains || b_contains;
}

bool check_overlap(const std::pair<int, int> a, const std::pair<int, int> b) {
    return a.second < b.first || a.first > b.second;
}

int main(int argc, char** argv) {
    std::cout << day4_input.size() << std::endl;

    int ret = 0;
    for (const auto & p : day4_input) {
        if (check_contain(p.first, p.second)) {
            ++ret;
        }
    }
    std::cout << "Part 1: " << ret << std::endl;

    int ret2 = 0;
    for (const auto & p : day4_input) {
        if (!check_overlap(p.first, p.second)) {
            ++ret2;
            // std::cout << p.first.first << ", " << p.first.second << ", " << p.second.first << ", " << p.second.second << std::endl;
        }
    }
    std::cout << "Part 2: " << ret2 << std::endl;

    return 0;
}
