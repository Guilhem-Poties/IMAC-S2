#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric> 

int main() {
    /* 1 */
    std::vector<int> vec {};

    for (int _ = 0; _ < 99; _++) {
        vec.push_back(rand() % 100);
    }

    std::vector<int>::iterator begin {vec.begin()};

    std::vector<int>::iterator end {vec.end()};

    /* 5 */
    std::sort(begin, end);

    /* 2 */
    for (std::vector<int>::iterator it = begin; it < end; ++it) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;

    /* 3 */
    std::cout << "Entrez une valeur : ";
    int value {}; 
    std::cin >> value;
    std::cout << std::endl;

    if (end != std::find(begin, end, value)) {
        std::cout << value << " est dans le tableau" << std::endl;
    }
    else {
        std::cout << value << " n'est pas dans le tableau" << std::endl;
    }
    
    /* 4 */
    std::cout << value << " apparait " << std::count(begin, end, value) << " fois dans le tableau";

    /* 6 */
    std::cout << "La somme du tableau vaut " << std::accumulate(begin, end, 0) << std::endl;
    
    
    return 0;
}