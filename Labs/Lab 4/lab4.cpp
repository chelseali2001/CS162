#include "./prog.h"

int main() {
    Hand hand0;
    Hand hand1 = hand0;
    Hand hand2;
    hand2 = hand0;

    cout << "Cards in hand0: " << hand0.get_n_cards() <<endl;
    for (int x = 0; x < 7; x++)
        cout << x + 1 << ". " << hand0.get_card(x).get_rank() << " " << hand0.get_card(x).get_suit() <<endl;

    cout << "\nCards in hand1: " << hand1.get_n_cards() <<endl;
    for (int x = 0; x < 7; x++)
        cout << x + 1 << ". " << hand1.get_card(x).get_rank() << " " << hand1.get_card(x).get_suit() <<endl;
        
    cout << "\nCards in hand2: " << hand2.get_n_cards() <<endl;
    for (int x = 0; x < 7; x++)
        cout << x + 1 << ". " << hand2.get_card(x).get_rank() << " " << hand2.get_card(x).get_suit() <<endl;

    return 0;
}