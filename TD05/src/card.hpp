#include <iostream>

enum class CardKind {
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card {
    CardKind kind;
    CardValue value;

    int hash();
};

namespace std {
    template<>
    struct hash<Card> {
        size_t operator()(Card card) const {
            return card.hash();
        }
    };
}

bool operator==(Card c1, Card c2);

Card get_card_from_hash(int hash);