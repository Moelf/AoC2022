#include <iostream>
#include <vector>
#include <string>
#include <deque>

#include <cxxopts.hpp>
#include <boost/unordered_map.hpp>
#include <boost/heap/priority_queue.hpp>

#include "utils.h"

using Map = std::vector<std::string>;
using OriginMap = boost::unordered_map<Point2, Point2>;

Point2 find_character(const Map & map, const char c) {
    int row_count = static_cast<int>(map.size());
    int col_count = static_cast<int>(map.at(0).size());

    for (int row = 0; row < row_count; ++row) {
        for (int col = 0; col < col_count; ++col) {
            if (map[row][col] == c) {
                return Point2(row, col);
            }
        }
    }

    return Point2();
}

PointList directions = {
    Point2(-1, 0), Point2(1, 0), Point2(0, 1), Point2(0, -1)
};

struct p2a_comp {
    p2a_comp(Point2 end, boost::unordered_map<Point2, int> * score) {
        end_ = end;
        score_ = score;
    }

    Point2 end_;
    boost::unordered_map<Point2, int> * score_;

    bool operator()(const Point2 & p1, const Point2 & p2) const {
        auto iter1 = score_->find(p1);
        auto iter2 = score_->find(p2);
        int s1 = 60000;
        int s2 = 60000;
        if (iter1 != score_->end()) s1 = iter1->second;
        if (iter2 != score_->end()) s2 = iter2->second;
        return (s1 + (end_ - p1).norm_l1()) < s2 + (end_ - p2).norm_l1();
        // return s1 < s2;
    }
};

PointList find_neighbor(Point2 pos, const Map & map) {
    std::vector<Point2> new_nodes;
    char curr_height = map[pos.x_][pos.y_];
    if (curr_height == 'S') curr_height = 'a';

    for (const auto d : directions) {
        Point2 new_pos = pos + d;
        if (new_pos.x_ >= 0 && new_pos.y_ >= 0 && 
            new_pos.x_ < map.size() && new_pos.y_ < map.at(0).size() && 
            map[new_pos.x_][new_pos.y_] - curr_height < 2 //
            )
        {
            new_nodes.emplace_back(new_pos);
        }
    }
    return new_nodes;
}

PointList find_all_a(const Map & map, const char c) {
    int row_count = static_cast<int>(map.size());
    int col_count = static_cast<int>(map.at(0).size());

    PointList ret_list;

    for (int row = 0; row < row_count; ++row) {
        for (int col = 0; col < col_count; ++col) {
            if (map[row][col] == c) {
                ret_list.emplace_back(Point2(row, col));
            }
        }
    }

    return ret_list;
}

PointList bfs(const Map & map, Point2 start, Point2 end) {
    std::deque<Point2> open = {start};
    PointSet visited = {start};
    boost::unordered_map<Point2, int>* gScore = new boost::unordered_map<Point2, int>();
    (*gScore)[start] = 0;

    OriginMap trace_back;
    bool found_goal = false;
    Point2 goal;

    while (!open.empty()) {
        std::sort(open.begin(), open.end(), p2a_comp(end, gScore));
        auto curr_node = open.front(); open.pop_front();

        if (map[curr_node.x_][curr_node.y_] == 'z')
        {
            found_goal = true;
            goal = curr_node;
            break;
        }

        PointList neighbors = find_neighbor(curr_node, map);

        for (auto p : neighbors) {
            int teng = (*gScore)[curr_node] + 1;
            auto p_iter = gScore->find(p);
            if (p_iter == gScore->end() || p_iter->second > teng) {
                trace_back[p] = curr_node;
                if (p_iter == gScore->end())
                {
                    gScore->insert({p, teng});
                } else {
                    p_iter->second = teng;
                }
                open.emplace_back(p);
            }
        }
    }

    if (found_goal) {
        PointList path;
        while ((goal - start).norm_l1() > 0) {
            path.push_back(goal);
            goal = trace_back[goal];
        }
        return path;
    } else {
        std::cout << "Not goal found" << std::endl;
    }

    free(gScore);

    return {};
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

    Point2 start = find_character(lines, 'S');
    Point2 end = find_character(lines, 'z');
    auto bfs_path = bfs(lines, start, end);
    std::cout << "Part 1: " << bfs_path.size() + 1 << std::endl;

    PointList all_a = find_all_a(lines, 'S');
    int min_number = 100000;
    for (auto a : all_a) {
        auto l = bfs(lines, start, end);
        if (l.size() > 0) {
            min_number = std::min(min_number, static_cast<int>(l.size() + 1));
        }
    }

    std::cout << "Min number: " << min_number << std::endl;

    return 0;
}