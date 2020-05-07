#include <iostream>
#include "./Population.h"

using namespace std;

int main() {
	int done = 0, pop = 0, births = 0, deaths = 0;	
	Population p(500, 100, 10);

	while (done == 0) {
		cout << "Birth Rate: " << p.getBirthRate() <<endl;
		cout << "Death Rate: " << p.getDeathRate() <<endl;

		cout << "Do you want to enter more new numbers? (0-yes, 1-no) ";
		cin >> done;

		if (done == 0) {
			cout << "Enter the current population: ";
			cin >> pop;

			cout << "Enter the number of births: ";
			cin >> births;

			cout << "Enter the number of deaths: ";
			cin >> deaths;
			
			p.setPopulation(pop, births, deaths);
		}		
	}	

	return 0;
}
