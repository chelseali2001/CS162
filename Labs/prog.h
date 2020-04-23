#include <iostream>

using namespace std;

class Card{
    private:
        int rank;
        int suit;
    
    public:
        Card(){};
        Card(int, int);
        int get_rank();
        int get_suit();
};

class Hand {
    private:
        Card* cards;
        int n_cards;
    
    public:
        Hand();
        ~Hand();
        Hand(const Hand&);
        Hand& operator = (const Hand&);
        int get_n_cards();
        Card get_card(int);
};