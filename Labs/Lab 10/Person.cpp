#include <iostream>
#include <string>
#include "./Person.h"
#include "./BankAccounts.h"

using namespace std;

Person::Person(string n, int x) {
    name = n;
    bank_accounts = x;
    accounts = new BankAccount[x];
}

string Person::get_name() {
    return name;
}

int Person::get_bank_accounts() {
    return bank_accounts;
}

BankAccount* Person::get_accounts() {
    return accounts;
}