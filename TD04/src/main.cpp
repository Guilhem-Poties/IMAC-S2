#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <math.h>

int sizeWord(std::string const& word);

std::vector<std::string> split_string(std::string const& str);


bool is_palindrome(std::string str);


int square_sum(std::vector<int> vec);

int even_product(std::vector<int> vec);

int main() {

    /************ EXERCICE 1 ************/

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
    
    
    /************ EXERCICE 2 ************/

    /* 1 */
    std::cout << sizeWord("Il etait une fois") << std::endl;
    
    /* 2 */
    for (std::string str : split_string("Il etait une fois")) std::cout << str << std::endl;


    /************ EXERCICE 3 ************/

    if (is_palindrome("ABBA")) std::cout << "C'est un palindrome";
    else std::cout << "Ce n'est pas un palindrome";


    /************ EXERCICE 3 ************/


    std::cout << "Somme des carrés : " << square_sum(vec) << std::endl;
    std::cout << "Produit des pairs : " << even_product(vec) << std::endl;

    return 0;
}

int sizeWord(std::string const& word) {
    auto const is_space = [](char letter){ return letter == ' '; };

    if (auto it = std::find_if(word.begin(), word.end(), is_space); it != word.end()) {
        return std::distance(word.begin(), it);
    }
    else {
        return 0;
    }
}

std::vector<std::string> split_string(std::string const& str) {
    std::vector<std::string> tabStr {};
    size_t lastWordPos {0};
    
    while (true) {
        size_t size = sizeWord(str.substr(lastWordPos));
        if (size != 0) {
            // std::cout << lastWordPos << ", " << size << ", " << str.substr(lastWordPos) << std::endl;
            tabStr.push_back(str.substr(lastWordPos, size));
            lastWordPos += size + 1;
        }
        else {
            tabStr.push_back(str.substr(lastWordPos));
            break;
        }
    }
    return tabStr;
}



bool is_palindrome(std::string str) {
    return std::equal(str.begin(), str.end(), str.rbegin(), str.rend());
}



int square_sum(std::vector<int> vec) {
    return std::accumulate(vec.begin(), vec.end(), 0, [](int sum, int element) {return sum + std::pow(element, 2);});
}

int even_product(std::vector<int> vec) {
    return std::accumulate(vec.begin(), vec.end(), 0, [](int product, int element) {return (element%2==1 ? product*element : product);});
}