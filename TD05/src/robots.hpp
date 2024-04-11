#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_map>

#pragma once;

std::string random_name(size_t size);

std::vector<std::pair<std::string, float>> get_robots_fix(size_t size);

std::unordered_map<std::string, std::vector<float>> robots_fixes_map(std::vector<std::pair<std::string, float>> const& robots_fixes);