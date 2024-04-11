#include "hachage.hpp"

int main() {
    std::string str {"Il etait une fois"};
    size_t max {9999};

    /************ EXERCICE 1 ************/

    /* 1 */
    std::cout << "hachage 1 : " << folding_string_hash(str, max) << std::endl;

    /* 2 */
    std::cout << "hachage 2 : " << folding_string_ordered_hash(str, max) << std::endl;

    /* 3 */
    size_t p {13};
    std::cout << "hachage 3 : " << polynomial_rolling_hash(str, p, max) << std::endl;
    
    
    /************ EXERCICE 2 ************/
    /* 1 */
}