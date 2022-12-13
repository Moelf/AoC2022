#include <iostream>
#include <vector>
#include <cxxopts.hpp>
#include <filesystem>
#include <string>
#include <fstream>
#include <istream>
#include <numeric>

using Matrix2d = std::vector<std::vector<int>>;
namespace fs = std::filesystem;

void print_mat(const Matrix2d & mat) {
    for (const auto & r : mat) {
        for (const int i : r) {
            std::cout << i << ", ";
        }
        std::cout << std::endl;
    }
    return;
}

Matrix2d load_matrix(const fs::path & input) {
    std::string line;
    std::ifstream input_file(input.c_str());
    Matrix2d ret_val;
    while (getline(input_file, line)) {
        std::vector<int> row(line.begin(), line.end());
        ret_val.emplace_back(row);
    }

    return ret_val;
}

void hori_pass(Matrix2d & mat, Matrix2d & mask) {
    for (size_t idx = 0; idx < mat.size(); ++idx) {
        int max_val = -1;
        for (size_t col_idx = 0; col_idx < mat.at(idx).size(); ++col_idx) {
            if (mat[idx][col_idx] > max_val) {
                mask[idx][col_idx] = 1;
                max_val = mat[idx][col_idx];
            } 
        }
    }

    for (size_t idx = 0; idx < mat.size(); ++idx) {
        int max_val = -1;
        for (size_t col_idx = mat.at(idx).size() - 1; col_idx < mat.at(idx).size(); --col_idx) {
            // When col_idx goes to -1, size_t makes it max, therefore exits
            if (mat[idx][col_idx] > max_val) {
                mask[idx][col_idx] = 1;
                max_val = mat[idx][col_idx];
            } 
        }
    }
    return;
}

void vert_pass(Matrix2d & mat, Matrix2d & mask) {
    for (size_t idx = 0; idx < mat.at(0).size(); ++idx) {
        int max_val = -1;
        for (size_t row_idx = 0; row_idx < mat.size(); ++row_idx) {
            if (mat[row_idx][idx] > max_val) {
                mask[row_idx][idx] = 1;
                max_val = mat[row_idx][idx];
            } 
        }
    }

    for (size_t idx = 0; idx < mat.at(0).size(); ++idx) {
        int max_val = -1;
        for (size_t row_idx = mat.size() - 1; row_idx < mat.size(); --row_idx) {
            // When col_idx goes to -1, size_t makes it max, therefore exits
            if (mat[row_idx][idx] > max_val) {
                mask[row_idx][idx] = 1;
                max_val = mat[row_idx][idx];
            } 
        }
    }
    return;
}

int mat_sum(const Matrix2d & mat) {
    std::vector<int> sum_mat;
    for (const auto & v : mat) {
        sum_mat.push_back(std::accumulate(v.begin(), v.end(), 0));
    }
    return std::accumulate(sum_mat.begin(), sum_mat.end(), 0);
}

// Todo: too ugly, fix this :)
int calculate_score(const Matrix2d & mat, size_t row, size_t col) {
    size_t row_count = mat.size();
    size_t col_count = mat.at(0).size();
    if (row == 0 || row == row_count - 1|| col == 0 || col == col_count - 1) {
        return 0;
    }

    int left_view = 1; int right_view = 1; int top_view = 1; int bottom_view = 1;
    int left_idx = row - 1;
    while (left_idx >= 0 && mat[left_idx][col] < mat[row][col]) {
        left_idx--;
    }
    if (left_idx < 0) left_view = int(row);
    else left_view = int(row - left_idx);

    left_idx = row + 1;
    while (left_idx < row_count && mat[left_idx][col] < mat[row][col]) {
        left_idx++;
    }
    if (left_idx == row_count) right_view = int(row_count - 1 - row);
    else right_view = left_idx - row;

    left_idx = col - 1;
    while (left_idx >= 0 && mat[row][left_idx] < mat[row][col]) {
        left_idx--;
    }
    if (left_idx < 0) top_view = int(col);
    else top_view = int(col - left_idx);

    left_idx = col + 1;
    while (left_idx < col_count && mat[row][left_idx] < mat[row][col]) {
        left_idx++;
    }
    if (left_idx == col_count) bottom_view = int(col_count - 1 - col);
    else bottom_view = int(left_idx - col);

    int score = left_view * right_view * top_view * bottom_view;
    return score;
}

int high_score(const Matrix2d & mat, const Matrix2d & mask) {
    int max_score = 0;
    for (size_t idx = 0; idx < mat.size(); idx++) {
        for (size_t col = 0; col < mat.at(0).size(); ++col) {
            if (mask[idx][col] > 0) {
                int score = calculate_score(mat, idx, col);
                max_score = std::max(max_score, score);
            }
        }
    }
    return max_score;
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

    Matrix2d mat = load_matrix(input_dir);

    Matrix2d mask(std::vector<std::vector<int>>(mat.size(), std::vector<int>(mat.at(0).size()) ));

    hori_pass(mat, mask);
    vert_pass(mat, mask);

    // print_mat(mask);
    std::cout << "Part 1: " << mat_sum(mask) << std::endl;
    std::cout << "Part 2: " << high_score(mat, mask) << std::endl;

    return 0;
}

