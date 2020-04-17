#include "./prog.h"

int main() {
    Deck card_deck;

    card_deck.create_deck();
    card_deck.shuffle_deck();
    card_deck.print_deck();
    card_deck.delete_deck();

    return 0;
}