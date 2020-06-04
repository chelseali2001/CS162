#include <iostream>
#include <string>
#include "./Person.h"
#include "./BankAccounts.h"

using namespace std;

void printPersonInfo(Person p) {
    cout << "Person name: " << p.get_name() <<endl;
    cout << "Account numbers:" <<endl;
    
    for (int x = 0; x < p.get_bank_accounts(); x++)
        cout << p.get_accounts()[x].get_account_number() <<endl;
}

int main () {
    string name = "";
    int bank_acccounts = 0;
    int account_number = 0;
	
    cout << "Enter name: ";
    cin >> name;
    
    cout << "How many account numbers do you want to enter: ";
    cin >> bank_acccounts;
 
    Person p(name, bank_acccounts);
    
    for (int x = 0; x < bank_acccounts; x++) {
        cout << "Enter account number: ";
        cin >> account_number;
        p.get_accounts()[x].set_account_number(account_number);
    }
 
    printPersonInfo(p);
    
    delete [] p.get_accounts();
    
	return 0;
}