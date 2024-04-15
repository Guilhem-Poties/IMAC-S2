#include "card.hpp"


bool operator==(Card c1, Card c2) {
    return (c1.kind == c2.kind && c1.value == c2.value);
}

int Card::hash() {
    return (int)value + 13*(int)kind;
}

Card get_card_from_hash(int hash) {
    return {(CardKind)((hash - hash%13)/13), (CardValue)(hash%13)};
}