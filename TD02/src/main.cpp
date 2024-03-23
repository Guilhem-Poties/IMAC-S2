#include "sorts.hpp"

bool is_sorted(std::vector<int> const& vec) { return std::is_sorted(vec.begin(), vec.end()); }

int main() {
    std::vector<int> array {6, 2, 8, 1, 5, 3, 9};
    bubble_sort(array);

    if (is_sorted(array)) {
        std::cout << "Le tableau est trié" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }
    return 0;
}