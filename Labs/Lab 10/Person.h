#include <iostream>
#include <string>
#include "./BankAccounts.h"
using namespace std;

class Person {
    private:
        string name;
        int bank_accounts;
        BankAccount* accounts;   
    
    public:
        Person(string, int);
        string get_name();
        int get_bank_accounts();
        BankAccount* get_accounts();
};