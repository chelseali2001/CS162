#include "./prog.h"

Card::Card(int r, int s) {
    rank = r;
    suit = s;
}

int Card::get_rank() {
    return rank;
}

int Card::get_suit() {
    return suit;
}

Hand::Hand() {
    n_cards = 7;
    cards = new Card[7];
    
    for (int x = 0; x < n_cards; x++)
        cards[x] = Card(x, rand() % 4);
    
    cout << "Hand() was called" <<endl;
}

Hand::~Hand() {
    delete [] cards;
    cout << "~Hand() was called" <<endl;
}

Hand::Hand(const Hand& oldHand) {
    n_cards = oldHand.n_cards;
    cards = new Card[n_cards];
    
    for (int x = 0; x < n_cards; x++)
        cards[x] = oldHand.cards[x];
    
    cout << "Hand(const Hand&) was called" <<endl;
}

Hand& Hand::operator = (const Hand& h) {
    n_cards = h.n_cards;
    
    delete [] this->cards;
    
    cards = new Card[n_cards];
    
    for (int x = 0; x < n_cards; x++)
        cards[x] = h.cards[x];
    
    cout << "Hand& operator was called" <<endl;
    return *this;
}

int Hand::get_n_cards() {
    return n_cards;
}

Card Hand::get_card(int n) {
    return cards[n];
}