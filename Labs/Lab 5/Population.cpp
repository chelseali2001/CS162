#include <iostream>
#include "./Population.h"

using namespace std;

Population::Population(int pop, int births, int deaths) {
	current_population = pop;
	annual_births = births;
	annual_deaths = deaths;
	birth_rate = (float) annual_births / (float) current_population;
	death_rate = (float) annual_deaths / (float) current_population;
}

float Population::getBirthRate() {
	return birth_rate;
}

float Population::getDeathRate() {
	return death_rate;
}

void Population::setPopulation(int pop, int births, int deaths) {
	current_population = pop;
	annual_births = births;
	annual_deaths = deaths;
	birth_rate = (float) annual_births / (float) current_population;
	death_rate = (float) annual_deaths / (float) current_population;
}
