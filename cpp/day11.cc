#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "utils.h"
#include "inputs/day11.hh"
#include <numeric>

using Op = std::pair<char, long>;

size_t operate(std::vector<Op> & ops, size_t monkey_idx, long item) {
    Op op = ops.at(monkey_idx);

    long sec_op = op.second;
    sec_op = sec_op < 0 ? item : sec_op;
    switch (op.first)
    {
    case '*':
        item = item * sec_op;
        break;
    case '+':
        item = item + sec_op;
        break;
    default:
        throw std::runtime_error("Unknown operator");
    }

    return item;
}

void step_round(std::vector<std::deque<long>> & states, std::vector<Op> ops, std::vector<long> & book_keep, bool p1) {

    long common = 1;
    for (auto v : destination) {
        common *= v.at(0);
    }

    for (size_t idx = 0; idx < states.size(); ++idx) {
        while (!states.at(idx).empty()) {
            long item = states.at(idx).front();
            states.at(idx).pop_front();
            item = operate(ops, idx, item);

            if (p1) {
                item /= 3;
            } else {
                if (item > common) {
                    item -= (item / common) * common;
                } 
            }

            if (item % destination.at(idx).at(0) == 0) {
                states.at(destination.at(idx).at(1)).push_back(item);
            } else {
                states.at(destination.at(idx).at(2)).push_back(item);
            }

            book_keep.at(idx) = book_keep.at(idx) + 1;
        }
    }
}

int main(int argc, char** argv) {
    std::vector<long> book_keep_p1(monkeys.size(), 0);
    std::vector<long> book_keep_p2(monkeys.size(), 0);
    std::vector<std::deque<long>> monkey_p1;
    for (const auto v : monkeys) {
        std::deque<long> m(v.begin(), v.end());
        monkey_p1.emplace_back(m);
    }

    std::vector<std::deque<long>> monkey_p2;
    for (const auto v : monkeys) {
        std::deque<long> m(v.begin(), v.end());
        monkey_p2.emplace_back(m);
    }

    for (int i = 0; i < 20; ++i) {
        step_round(monkey_p1, ops, book_keep_p1, true);
    }

    for (int i = 0; i < 10000; ++i) {
        step_round(monkey_p2, ops, book_keep_p2, false);
    }

    std::sort(book_keep_p1.begin(), book_keep_p1.end());
    std::sort(book_keep_p2.begin(), book_keep_p2.end());
    std::cout << "Part 1: " << book_keep_p1.back() * *(book_keep_p1.end() - 2) << std::endl;
    std::cout << "Part 2: " << book_keep_p2.back() * *(book_keep_p2.end() - 2) << std::endl;

    return 0;
}