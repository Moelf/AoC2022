#include <vector>
#include <iostream>
#include <istream>
#include <fstream>
#include <ostream>
#include <cxxopts.hpp>
#include <filesystem>
#include "utils.h"
#include <unordered_set>
#include <boost/functional/hash.hpp>
#include <boost/unordered_set.hpp>
#include <boost/unordered_map.hpp>

class Point2 {
    public: 
        int x_;
        int y_;

        Point2() : x_(0), y_(0) {}
        Point2(int x, int y) : x_(x), y_(y) {}
        
        bool operator==(const Point2 & other) const {
            return x_ == other.x_ && y_ == other.y_;
        }

        Point2 operator+(const Point2 & other) {
            Point2 res;
            res.x_ = x_ + other.x_;
            res.y_ = y_ + other.y_;
            return res;
        }

        Point2 operator-(const Point2 & other) {
            Point2 res;
            res.x_ = x_ - other.x_;
            res.y_ = y_ - other.y_;
            return res;
        }

        friend std::size_t hash_value(const Point2 & p) {
            std::size_t seed = 0;
            boost::hash_combine(seed, p.x_);
            boost::hash_combine(seed, p.y_);
            return seed;
        }

        friend std::ostream& operator<<(std::ostream & os, const Point2 & p) {
            os << p.x_ << ", " << p.y_;
            return os;
        }
};

using PointSet = boost::unordered_set<Point2>;

boost::unordered_map<char, Point2> motion = {
    {'R', Point2(1, 0)},
    {'L', Point2(-1, 0)},
    {'U', Point2(0, 1)},
    {'D', Point2(0, -1)},
};

void follow(const Point2 & head, Point2 & tail) {
    bool h = std::abs(head.x_ - tail.x_) > 1;
    bool v = std::abs(head.y_ - tail.y_) > 1;

    if (h) {
        tail.x_ = (head.x_ + tail.x_) / 2;
        tail.y_ = head.y_;
    } else if (v) {
        tail.y_ = (head.y_ + tail.y_) / 2;
        tail.x_ = head.x_;
    }

    return;
}

void long_string(const std::string & s, PointSet & visited, std::vector<Point2> & rope) {
    Point2 head_mov = motion[s[0]];
    int num = std::stoi(std::string(s.begin() + 2, s.end()));
    for (int i = 0; i < num; ++i) {
        rope[0] = rope[0] + head_mov;
        for (size_t i = 1; i < rope.size(); i++) {
            follow(rope[i-1], rope[i]);
        }
        visited.insert(rope.back());
    }
}

void simulate_long_tails(const std::vector<std::string> & cmds, int length) {
    boost::unordered_set<Point2> visited;
    std::vector<Point2> rope(length, Point2());
    for (const auto c : cmds) {
        // step_through(c, visited, head, tail);
        long_string(c, visited, rope);
    }
    std::cout << "Part 2 num tiles: " << visited.size() << std::endl;
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

    auto cmds = read_lines(input_dir);
    simulate_long_tails(cmds, 2);
    simulate_long_tails(cmds, 10);
    return 0;
}