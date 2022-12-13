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
