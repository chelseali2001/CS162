#include <iostream>
#include <string>
#include "./Person.h"
#include "./BankAccounts.h"

using namespace std;

BankAccount::BankAccount() {
    account_number = 0;
}

int BankAccount::get_account_number() {
    return account_number;
}

void BankAccount::set_account_number(int n) {
    account_number = n;
}