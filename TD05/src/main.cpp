#include "hachage.hpp"
#include "robots.hpp"
#include "card.hpp"

std::vector<Card> get_cards(size_t const size);

std::string card_name(Card const& card);

int main() {

    /************ EXERCICE 1 ************/

    // std::string str {"Il etait une fois"};
    // size_t max {9999};

    // /* 1 */
    // std::cout << "hachage 1 : " << folding_string_hash(str, max) << std::endl;

    // /* 2 */
    // std::cout << "hachage 2 : " << folding_string_ordered_hash(str, max) << std::endl;

    // /* 3 */
    // size_t p {13};
    // std::cout << "hachage 3 : " << polynomial_rolling_hash(str, p, max) << std::endl;
    
    
    // /************ EXERCICE 2 ************/
    
    // /* 1 */
    // std::cout << "Reparations par robot : " << std::endl;
    // for (auto & robot : robots_fixes_map(get_robots_fix(5))) {
    //     std::cout << robot.first << " : \n";
    //     for (auto & fix : robot.second) {
    //         std::cout << " - " << fix << std::endl;
    //     }
    // }
    // std::cout << std::endl;

    // /* 2 */
    // std::cout << "Somme de float : " << float_sum({2.1, 3.2, 8.5}) << std::endl;

    // /* 3 */
    // std::cout << "Somme des réparations par robot : " << std::endl;
    // for (auto & robot : robots_fixes_map(get_robots_fix(100))) {
    //     std::cout << robot.first << " : " << float_sum(robot.second) << std::endl;
    // }
    // std::cout << std::endl;


    /************ EXERCICE 3 ************/

    std::vector<Card> cards = get_cards(2);
    /* 1 */
    if (cards[0] == cards[2]) std::cout << "equals";
    else std::cout << "not equals";
    std::cout << std::endl;


    /* 2 & 3 */
    for (auto & card : cards) {
        std::cout << card_name(card) << " = " << card.hash() << std::endl;
    }

    /* 4 */
    std::unordered_map<int, int> card_count_map {}; 
    for (auto & card : get_cards(100)) {
        card_count_map[card.hash()] += 1;
    }
    for (auto & element : card_count_map) {
        std::cout << card_name(get_card_from_hash(element.first)) << " : " << element.second << std::endl;
    }
    
}

std::vector<Card> get_cards(size_t const size) {
    std::vector<Card> cards {};
    cards.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}

std::string card_name(Card const& card) {
    std::string name {};

    unsigned int card_value {(static_cast<unsigned int>(card.value)+2) % 14};

    if (card_value == 0) {
        name += "Ace";
    }else if (card_value < 10) {
        name += '0' + card_value;
    }else if (card_value == 10) {
        name += "10";
    }else if (card_value == 11) {
        name += 'V';
    }else if (card_value == 12) {
        name += 'Q';
    }else if (card_value == 13) {
        name += 'K';
    }

    name += " of ";

    if (card.kind == CardKind::Heart) {
        name += "Heart";
    }else if (card.kind == CardKind::Diamond) {
        name += "Diamond";
    }else if (card.kind == CardKind::Club) {
        name += "Club";
    }else if (card.kind == CardKind::Spade) {
        name += "Spade";
    }
    return name;
}