#include "./prog.h"

void Card::set_suit(string suit_val) {
    suit = suit_val;
}

void Card::set_rank(int rank_val) {
    rank = rank_val;
}

string Card::get_suit() {
    return suit;
}

int Card::get_rank() {
    return rank;
}

void Deck::create_deck() {
    cards = new Card[52];
    int index = 0;

    for (int x = 0; x < 13; x++)
        for (int i = 0; i < 4; i++) {
            cards[index].set_rank(x + 1);
            
            if (i == 0)
                cards[index].set_suit("Hearts");
            else if (i == 1)
                cards[index].set_suit("Spades");
            else if (i == 2)
                cards[index].set_suit("Clovers");
            else if (i == 3)
                cards[index].set_suit("Diamonds");
            
            index++;
        }
}

void Deck::shuffle_deck() {
    srand(time(NULL));

    for (int x = 0; x < 52; x++)
        if (rand() % 2 == 1) {
            int index = x;

            while (index == x)
                index = rand() % 52;

            Card random_card = cards[index];
            cards[index] = cards[x];
            cards[x] = random_card;
        }
}

void Deck::print_deck() {
    for (int x = 0; x < 52; x++) {
        if (cards[x].get_rank() == 1)
            cout << "Ace of ";
        else if (cards[x].get_rank() == 11)
            cout << "Jack of ";
        else if (cards[x].get_rank() == 12)
            cout << "Queen of ";
        else if (cards[x].get_rank() == 13)
            cout << "King of ";
        else
            cout << cards[x].get_rank() << " of ";
        
        cout << cards[x].get_suit() <<endl;
    }
}

void Deck::delete_deck() {
    delete [] cards;
}