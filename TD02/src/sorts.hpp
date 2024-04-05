#include <vector>
#include <algorithm>
#include <iostream>

void bubble_sort(std::vector<int> & vec);

size_t quick_sort_partition(std::vector<int> & vec, size_t const& left, size_t const& right);
void quick_sort(std::vector<int> & vec);
void quick_sort(std::vector<int> & vec, size_t const& left, size_t const& right);

// void merge_sort_merge(std::vector<float> & vec, size_t const left, size_t const middle, size_t const right);

// void merge_sort(std::vector<float> & vec);

// void merge_sort(std::vector<float> & vec, size_t const left, size_t const right);