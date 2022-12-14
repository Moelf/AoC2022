#pragma once

#include <deque>
#include <vector>


std::vector<std::deque<long>> monkeys = {
    {54, 82, 90, 88, 86, 54},
    {91, 65},
    {62, 54, 57, 92, 83, 63, 63},
    {67, 72, 68},
    {68, 89, 90, 86, 84, 57, 72, 84},
    {79, 83, 64, 58},
    {96, 72, 89, 70, 88},
    {79}
};

std::vector<std::vector<long>> destination = {
    {11, 2, 6},
    {5, 7, 4},
    {7, 1, 7},
    {2, 0, 6},
    {17, 3, 5},
    {13, 3, 0},
    {3, 1, 2},
    {19, 4, 5}
};

std::vector<std::pair<char, long>> ops = {
    {'*', 7},
    {'*', 13},
    {'+', 1},
    {'*', -1},
    {'+', 7},
    {'+', 6},
    {'+', 4},
    {'+', 8}
};

// std::vector<std::deque<long>> monkeys = {
//     {79, 98},
//     {54, 65, 75, 74},
//     {79, 60, 97},
//     {74}
// };

// std::vector<std::vector<long>> destination = {
//     {23, 2, 3},
//     {19, 2, 0},
//     {13, 1, 3},
//     {17, 0, 1},
// };

// llong common = 23 * 19 * 13 * 17;

// std::vector<std::pair<char, long>> ops = {
//     {'*', 19},
//     {'+', 6},
//     {'*', -1},
//     {'+', 3},
// };