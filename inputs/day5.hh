#pragma once
#include <vector>

const std::vector<std::vector<char>> init_state = {
    {'S','L','F','Z','D','B','R','H'},
    {'R','Z','M','B','T'},
    {'S','N','H','C','L','Z',},
    {'J','F','C','S'},
    {'B','Z','R','W','H','G','P'},
    {'T','M','N','D','G','Z','J','V'},
    {'Q','P','S','F','W','N','L','G'},
    {'R','Z','M'},
    {'T','R','V','G','L','C','M'},
};

const std::vector<std::vector<int>> cmds = {
    { 6 , 1 , 7},
    { 2 , 2 , 4},
    { 2 , 7 , 4},
    { 6 , 4 , 3},
    { 1 , 5 , 1},
    { 3 , 8 , 3},
    { 15 , 3 , 4},
    { 6 , 5 , 9},
    { 14 , 4 , 2},
    { 3 , 2 , 7},
    { 1 , 2 , 7},
    { 9 , 9 , 1},
    { 3 , 2 , 1},
    { 7 , 6 , 7},
    { 1 , 6 , 8},
    { 2 , 9 , 1},
    { 9 , 2 , 3},
    { 8 , 3 , 9},
    { 1 , 1 , 4},
    { 1 , 8 , 6},
    { 1 , 6 , 2},
    { 5 , 9 , 8},
    { 2 , 9 , 1},
    { 1 , 4 , 2},
    { 17 , 1 , 9},
    { 1 , 3 , 1},
    { 3 , 2 , 3},
    { 2 , 4 , 5},
    { 12 , 7 , 3},
    { 16 , 9 , 2},
    { 5 , 7 , 5},
    { 2 , 1 , 2},
    { 1 , 3 , 6},
    { 1 , 4 , 6},
    { 1 , 7 , 3},
    { 1 , 6 , 3},
    { 7 , 3 , 4},
    { 5 , 8 , 3},
    { 1 , 6 , 7},
    { 7 , 3 , 4},
    { 6 , 3 , 1},
    { 2 , 4 , 8},
    { 1 , 5 , 2},
    { 10 , 4 , 5},
    { 3 , 5 , 2},
    { 2 , 8 , 9},
    { 5 , 2 , 8},
    { 1 , 3 , 5},
    { 2 , 5 , 8},
    { 12 , 5 , 7},
    { 1 , 4 , 2},
    { 5 , 9 , 4},
    { 1 , 2 , 5},
    { 6 , 1 , 3},
    { 6 , 3 , 5},
    { 10 , 7 , 4},
    { 2 , 7 , 3},
    { 4 , 7 , 6},
    { 1 , 9 , 5},
    { 12 , 2 , 1},
    { 1 , 8 , 7},
    { 3 , 7 , 4},
    { 4 , 4 , 8},
    { 7 , 5 , 3},
    { 1 , 2 , 4},
    { 10 , 1 , 5},
    { 2 , 1 , 2},
    { 4 , 6 , 7},
    { 8 , 8 , 3},
    { 5 , 4 , 9},
    { 12 , 3 , 8},
    { 4 , 3 , 8},
    { 2 , 9 , 2},
    { 3 , 5 , 4},
    { 1 , 3 , 5},
    { 1 , 7 , 6},
    { 14 , 4 , 6},
    { 6 , 5 , 9},
    { 8 , 2 , 8},
    { 3 , 5 , 7},
    { 21 , 8 , 4},
    { 16 , 4 , 9},
    { 8 , 6 , 2},
    { 4 , 6 , 1},
    { 1 , 4 , 6},
    { 2 , 4 , 8},
    { 3 , 1 , 8},
    { 2 , 4 , 6},
    { 1 , 6 , 2},
    { 3 , 8 , 4},
    { 2 , 2 , 5},
    { 2 , 5 , 7},
    { 1 , 8 , 9},
    { 1 , 4 , 9},
    { 1 , 1 , 6},
    { 3 , 6 , 3},
    { 3 , 2 , 3},
    { 1 , 4 , 6},
    { 3 , 6 , 7},
    { 10 , 9 , 7},
    { 1 , 4 , 7},
    { 6 , 8 , 3},
    { 1 , 6 , 8},
    { 2 , 2 , 5},
    { 1 , 2 , 1},
    { 1 , 8 , 9},
    { 1 , 2 , 8},
    { 1 , 1 , 9},
    { 7 , 9 , 1},
    { 1 , 8 , 5},
    { 7 , 1 , 7},
    { 3 , 5 , 8},
    { 3 , 7 , 2},
    { 1 , 8 , 4},
    { 1 , 2 , 4},
    { 2 , 4 , 6},
    { 5 , 3 , 1},
    { 9 , 7 , 2},
    { 6 , 3 , 8},
    { 8 , 2 , 7},
    { 2 , 6 , 4},
    { 2 , 1 , 7},
    { 2 , 1 , 4},
    { 24 , 7 , 4},
    { 4 , 8 , 9},
    { 2 , 7 , 5},
    { 1 , 5 , 2},
    { 1 , 3 , 8},
    { 4 , 2 , 8},
    { 13 , 9 , 2},
    { 2 , 8 , 6},
    { 3 , 9 , 6},
    { 26 , 4 , 2},
    { 1 , 5 , 7},
    { 2 , 6 , 2},
    { 2 , 4 , 1},
    { 7 , 2 , 1},
    { 15 , 2 , 6},
    { 8 , 2 , 8},
    { 4 , 6 , 8},
    { 9 , 2 , 9},
    { 13 , 6 , 7},
    { 6 , 1 , 9},
    { 2 , 2 , 4},
    { 4 , 1 , 6},
    { 3 , 8 , 3},
    { 1 , 4 , 9},
    { 2 , 6 , 7},
    { 1 , 4 , 3},
    { 3 , 3 , 2},
    { 14 , 7 , 4},
    { 5 , 9 , 5},
    { 9 , 8 , 5},
    { 7 , 9 , 6},
    { 2 , 5 , 6},
    { 2 , 9 , 2},
    { 10 , 5 , 1},
    { 1 , 3 , 1},
    { 2 , 8 , 1},
    { 1 , 9 , 2},
    { 1 , 7 , 5},
    { 4 , 2 , 1},
    { 1 , 9 , 8},
    { 3 , 4 , 1},
    { 1 , 8 , 6},
    { 12 , 1 , 5},
    { 1 , 1 , 6},
    { 1 , 7 , 5},
    { 4 , 6 , 9},
    { 2 , 2 , 4},
    { 1 , 9 , 6},
    { 1 , 1 , 5},
    { 2 , 9 , 7},
    { 10 , 6 , 5},
    { 1 , 6 , 7},
    { 20 , 5 , 1},
    { 1 , 7 , 9},
    { 2 , 9 , 1},
    { 3 , 5 , 1},
    { 2 , 8 , 4},
    { 2 , 8 , 7},
    { 1 , 5 , 9},
    { 1 , 8 , 4},
    { 22 , 1 , 7},
    { 5 , 4 , 8},
    { 1 , 5 , 9},
    { 19 , 7 , 4},
    { 2 , 9 , 1},
    { 1 , 5 , 9},
    { 10 , 1 , 8},
    { 1 , 9 , 1},
    { 1 , 8 , 3},
    { 8 , 4 , 7},
    { 1 , 5 , 6},
    { 3 , 4 , 5},
    { 1 , 5 , 9},
    { 11 , 7 , 4},
    { 4 , 4 , 9},
    { 1 , 6 , 2},
    { 1 , 3 , 9},
    { 5 , 9 , 4},
    { 5 , 7 , 9},
    { 23 , 4 , 2},
    { 17 , 2 , 7},
    { 2 , 2 , 8},
    { 4 , 4 , 7},
    { 1 , 4 , 5},
    { 2 , 5 , 2},
    { 5 , 8 , 9},
    { 5 , 2 , 7},
    { 9 , 7 , 5},
    { 11 , 9 , 2},
    { 1 , 4 , 3},
    { 5 , 8 , 7},
    { 3 , 8 , 5},
    { 2 , 1 , 3},
    { 2 , 3 , 9},
    { 1 , 5 , 8},
    { 5 , 7 , 5},
    { 15 , 5 , 4},
    { 2 , 8 , 1},
    { 2 , 5 , 1},
    { 4 , 4 , 1},
    { 1 , 8 , 7},
    { 8 , 2 , 1},
    { 4 , 2 , 8},
    { 2 , 7 , 4},
    { 5 , 8 , 6},
    { 5 , 7 , 9},
    { 4 , 6 , 5},
    { 7 , 4 , 8},
    { 1 , 6 , 1},
    { 1 , 3 , 1},
    { 2 , 5 , 1},
    { 7 , 1 , 5},
    { 5 , 1 , 3},
    { 4 , 7 , 9},
    { 4 , 3 , 9},
    { 2 , 9 , 7},
    { 6 , 9 , 2},
    { 1 , 4 , 1},
    { 1 , 3 , 5},
    { 1 , 2 , 5},
    { 5 , 9 , 4},
    { 4 , 4 , 6},
    { 1 , 8 , 9},
    { 8 , 4 , 3},
    { 7 , 7 , 3},
    { 5 , 1 , 3},
    { 11 , 5 , 9},
    { 1 , 7 , 6},
    { 2 , 3 , 5},
    { 1 , 3 , 1},
    { 3 , 6 , 2},
    { 2 , 5 , 1},
    { 2 , 1 , 2},
    { 3 , 1 , 5},
    { 5 , 9 , 2},
    { 2 , 6 , 8},
    { 2 , 3 , 8},
    { 4 , 9 , 7},
    { 3 , 5 , 2},
    { 2 , 1 , 8},
    { 1 , 9 , 8},
    { 1 , 9 , 2},
    { 4 , 7 , 9},
    { 11 , 8 , 7},
    { 1 , 8 , 2},
    { 6 , 9 , 7},
    { 3 , 7 , 1},
    { 13 , 2 , 7},
    { 24 , 7 , 1},
    { 2 , 2 , 6},
    { 1 , 8 , 3},
    { 1 , 9 , 3},
    { 5 , 2 , 4},
    { 1 , 2 , 5},
    { 1 , 6 , 2},
    { 1 , 6 , 3},
    { 1 , 2 , 4},
    { 3 , 7 , 3},
    { 2 , 1 , 7},
    { 2 , 3 , 8},
    { 2 , 7 , 8},
    { 9 , 3 , 2},
    { 3 , 4 , 8},
    { 1 , 5 , 1},
    { 9 , 2 , 1},
    { 3 , 4 , 9},
    { 1 , 7 , 8},
    { 6 , 3 , 9},
    { 2 , 1 , 5},
    { 15 , 1 , 3},
    { 13 , 3 , 9},
    { 11 , 1 , 4},
    { 5 , 4 , 1},
    { 6 , 3 , 6},
    { 4 , 4 , 8},
    { 6 , 1 , 4},
    { 1 , 5 , 2},
    { 1 , 2 , 1},
    { 3 , 4 , 2},
    { 2 , 8 , 5},
    { 2 , 4 , 2},
    { 9 , 9 , 3},
    { 9 , 3 , 5},
    { 2 , 9 , 4},
    { 5 , 2 , 6},
    { 1 , 1 , 8},
    { 1 , 4 , 1},
    { 10 , 9 , 2},
    { 9 , 2 , 4},
    { 10 , 4 , 1},
    { 3 , 1 , 3},
    { 4 , 1 , 2},
    { 5 , 2 , 4},
    { 2 , 5 , 2},
    { 4 , 1 , 7},
    { 10 , 5 , 4},
    { 2 , 2 , 4},
    { 1 , 9 , 2},
    { 2 , 3 , 5},
    { 1 , 3 , 5},
    { 3 , 6 , 7},
    { 8 , 4 , 9},
    { 6 , 6 , 1},
    { 4 , 9 , 5},
    { 2 , 9 , 1},
    { 1 , 2 , 6},
    { 6 , 5 , 2},
    { 3 , 7 , 9},
    { 4 , 8 , 2},
    { 1 , 7 , 9},
    { 1 , 5 , 3},
    { 2 , 7 , 4},
    { 1 , 7 , 1},
    { 14 , 1 , 9},
    { 1 , 1 , 9},
    { 1 , 3 , 8},
    { 3 , 2 , 5},
    { 2 , 4 , 2},
    { 6 , 8 , 1},
    { 1 , 2 , 1},
    { 5 , 1 , 9},
    { 1 , 1 , 7},
    { 2 , 8 , 5},
    { 1 , 5 , 4},
    { 1 , 6 , 1},
    { 8 , 2 , 7},
    { 2 , 6 , 1},
    { 9 , 9 , 5},
    { 11 , 4 , 8},
    { 4 , 7 , 4},
    { 6 , 4 , 6},
    { 1 , 7 , 4},
    { 6 , 6 , 7},
    { 1 , 5 , 9},
    { 6 , 8 , 9},
    { 8 , 9 , 5},
    { 1 , 4 , 5},
    { 15 , 9 , 3},
    { 3 , 1 , 4},
    { 6 , 7 , 2},
    { 3 , 4 , 9},
    { 2 , 7 , 3},
    { 1 , 7 , 3},
    { 1 , 7 , 2},
    { 2 , 8 , 1},
    { 3 , 8 , 5},
    { 2 , 1 , 7},
    { 8 , 3 , 6},
    { 3 , 6 , 5},
    { 1 , 6 , 1},
    { 10 , 5 , 7},
    { 6 , 5 , 4},
    { 4 , 2 , 4},
    { 6 , 5 , 1},
    { 6 , 1 , 8},
    { 2 , 9 , 2},
    { 2 , 9 , 7},
    { 6 , 3 , 7},
    { 1 , 3 , 5},
    { 1 , 1 , 9},
    { 2 , 8 , 1},
    { 2 , 5 , 4},
    { 3 , 3 , 7},
    { 10 , 4 , 6},
    { 1 , 9 , 7},
    { 12 , 7 , 3},
    { 12 , 3 , 8},
    { 2 , 1 , 5},
    { 1 , 1 , 3},
    { 13 , 8 , 1},
    { 7 , 7 , 1},
    { 13 , 6 , 9},
    { 1 , 7 , 4},
    { 6 , 5 , 3},
    { 3 , 4 , 3},
    { 6 , 3 , 1},
    { 10 , 9 , 4},
    { 2 , 7 , 6},
    { 8 , 1 , 9},
    { 3 , 2 , 9},
    { 1 , 3 , 5},
    { 1 , 3 , 5},
    { 1 , 1 , 4},
    { 6 , 9 , 3},
    { 2 , 6 , 7},
    { 4 , 9 , 5},
    { 4 , 1 , 6},
    { 1 , 2 , 4},
    { 6 , 1 , 4},
    { 3 , 9 , 3},
    { 3 , 6 , 8},
    { 3 , 8 , 7},
    { 5 , 5 , 1},
    { 1 , 3 , 9},
    { 1 , 9 , 5},
    { 1 , 3 , 2},
    { 2 , 5 , 1},
    { 1 , 6 , 9},
    { 1 , 6 , 3},
    { 2 , 9 , 7},
    { 2 , 8 , 1},
    { 1 , 3 , 2},
    { 1 , 2 , 5},
    { 1 , 7 , 1},
    { 7 , 7 , 9},
    { 12 , 1 , 9},
    { 1 , 5 , 2},
    { 1 , 7 , 1},
    { 13 , 4 , 7},
    { 1 , 9 , 4},
    { 5 , 7 , 3},
    { 4 , 9 , 1},
    { 8 , 7 , 9},
    { 3 , 2 , 3},
    { 4 , 3 , 7},
    { 5 , 4 , 6},
    { 3 , 9 , 4},
    { 10 , 1 , 5},
    { 3 , 4 , 7},
    { 16 , 9 , 2},
    { 3 , 9 , 2},
    { 6 , 5 , 3},
    { 4 , 6 , 2},
    { 1 , 4 , 6},
    { 2 , 6 , 8},
    { 1 , 5 , 2},
    { 1 , 5 , 8},
    { 7 , 7 , 2},
    { 16 , 2 , 1},
    { 1 , 5 , 1},
    { 10 , 2 , 8},
    { 14 , 8 , 5},
    { 2 , 2 , 6},
    { 1 , 2 , 5},
    { 2 , 2 , 1},
    { 8 , 1 , 7},
    { 4 , 1 , 7},
    { 2 , 1 , 7},
    { 5 , 3 , 2},
    { 1 , 1 , 6},
    { 2 , 2 , 5},
    { 4 , 1 , 7},
    { 1 , 2 , 8},
    { 1 , 2 , 8},
    { 3 , 6 , 7},
    { 10 , 7 , 5},
    { 1 , 2 , 8},
    { 27 , 5 , 9},
    { 1 , 5 , 6},
    { 1 , 6 , 4},
    { 1 , 4 , 3},
    { 3 , 3 , 7},
    { 4 , 3 , 6},
    { 2 , 6 , 4},
    { 3 , 8 , 1},
    { 2 , 6 , 1},
    { 12 , 7 , 8},
    { 2 , 3 , 9},
    { 1 , 9 , 2},
    { 1 , 2 , 8},
    { 2 , 1 , 2},
    { 6 , 3 , 8},
    { 1 , 7 , 4},
    { 15 , 9 , 5},
    { 7 , 9 , 4},
    { 1 , 2 , 1},
    { 16 , 8 , 2},
    { 8 , 5 , 2},
    { 24 , 2 , 9},
    { 3 , 1 , 2},
    { 24 , 9 , 1},
    { 5 , 5 , 9},
    { 3 , 4 , 1},
    { 1 , 7 , 6},
    { 1 , 6 , 3},
    { 1 , 3 , 2},
    { 3 , 2 , 3},
    { 1 , 5 , 6},
    { 1 , 2 , 7}
};