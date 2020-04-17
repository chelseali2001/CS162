#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class Card {
    private:
        string suit;
        int rank;
    
    public:
        void set_suit(string);
        void set_rank(int);
        string get_suit();
        int get_rank();
};

class Deck {
    private:
        Card* cards;

    public:
        void create_deck();
        void shuffle_deck();
        void print_deck();
        void delete_deck();
};