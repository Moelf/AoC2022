#include <iostream>
#include "inputs/day5.hh"
#include <vector>
#include <deque>

int main(int argc, char** argv) {

    // Reinitialize
    std::vector<std::deque<char>> states;
    for (const auto v : init_state)  {
        std::deque<char> s(v.begin(), v.end());
        states.emplace_back(s);
    }

    auto p2_state = std::vector<std::deque<char>>(states);
    for (const auto v : cmds) {
        for (int i = 0; i < v.at(0); i++) {
            char tmp;
            tmp = states.at(v.at(1) - 1).front();
            states.at(v.at(1) - 1).pop_front();
            states.at(v.at(2) - 1).push_front(tmp);
        }
    }

    std::cout << "Part 1: ";
    for (const auto & v : states) {
        std::cout << v.front();
    }

    std::cout << std::endl;

    for (const auto v : cmds) {
        std::reverse_copy(
            p2_state.at(v.at(1) - 1).begin(),
            p2_state.at(v.at(1) - 1).begin() + v.at(0),
            std::front_inserter(p2_state.at(v.at(2) - 1))
        );
        p2_state.at(v.at(1) - 1).erase(
            p2_state.at(v.at(1) - 1).begin(),
            p2_state.at(v.at(1) - 1).begin() + v.at(0)
        );
    }

    std::cout << "Part 2: ";
    for (const auto & v : p2_state) {
        std::cout << v.front();
    }
    std::cout << std::endl;

    return 0;
}