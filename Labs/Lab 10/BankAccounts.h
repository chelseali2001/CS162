#include <iostream>
#include <string>

#ifndef BANKACCOUNT
#define BANKACCOUNT

using namespace std;

class BankAccount {
    private:
        int account_number;
    
    public:
        BankAccount();
        int get_account_number();
        void set_account_number(int);
};

#endif
