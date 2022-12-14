#pragma once
#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include <fstream>
#include <istream>
#include <sstream>
#include <iterator>

namespace fs = std::filesystem;

std::vector<std::string> read_lines(const fs::path & fp);

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

        Point2 operator+(const Point2 & other) const {
            Point2 res;
            res.x_ = x_ + other.x_;
            res.y_ = y_ + other.y_;
            return res;
        }

        Point2 operator-(const Point2 & other) const {
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

        int norm_l1() const {
            return std::abs(x_) + std::abs(y_);
        }

        bool any_negative() const {
            return x_ < 0 || y_ < 0;
        }
};

using PointSet = boost::unordered_set<Point2>;
using PointList = std::vector<Point2>;
