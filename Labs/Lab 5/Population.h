#include <iostream>

using namespace std;

class Population {
	private:
		int current_population;
		int annual_births;
		int annual_deaths;
		float birth_rate;
		float death_rate;
	
	public:
		Population(int, int, int);
		float getBirthRate();
		float getDeathRate();
		void setPopulation(int, int, int);
};
