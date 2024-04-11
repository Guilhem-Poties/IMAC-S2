#include "hachage.hpp"
#include "robots.hpp"

int main() {

    /************ EXERCICE 1 ************/

    std::string str {"Il etait une fois"};
    size_t max {9999};

    /* 1 */
    std::cout << "hachage 1 : " << folding_string_hash(str, max) << std::endl;

    /* 2 */
    std::cout << "hachage 2 : " << folding_string_ordered_hash(str, max) << std::endl;

    /* 3 */
    size_t p {13};
    std::cout << "hachage 3 : " << polynomial_rolling_hash(str, p, max) << std::endl;
    
    
    /************ EXERCICE 2 ************/
    
    /* 1 */
    std::cout << "Reparations par robot : " << std::endl;
    for (auto & robot : robots_fixes_map(get_robots_fix(5))) {
        std::cout << robot.first << " : \n";
        for (auto & fix : robot.second) {
            std::cout << " - " << fix << std::endl;
        }
    }
    std::cout << std::endl;

    /* 2 */
    std::cout << "Somme de float : " << float_sum({2.1, 3.2, 8.5}) << std::endl;

    /* 3 */
    std::cout << "Somme des réparations par robot : " << std::endl;
    for (auto & robot : robots_fixes_map(get_robots_fix(100))) {
        std::cout << robot.first << " : " << float_sum(robot.second) << std::endl;
    }
    std::cout << std::endl;
}