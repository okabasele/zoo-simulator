#ifndef HABITAT_H
#define HABITAT_H
#include "ianimal.h"
#include <vector>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef vector<IAnimal *> AnimalList;

class Habitat
{
	string m_espece;
	int m_maxSize;
	int m_animals_count;
	AnimalList m_animals;
	bool surpop;
public:
	void setEspece(string);
	string getEspece();
	void setMaxSize(int);
	int getMaxSize();
	void initAnimalCount(int);
	void addAnimal(IAnimal *animal);
	void removeAnimal(IAnimal *animal);
	void removeRandomAnimal();
	bool oldEnough(char);
	int getAnimalCount();
	AnimalList getAnimals();
	void setAnimals(AnimalList);
	int feedingCost();
	int payOff();
	bool getSurpop();
	void setSurpop();
	void checkAnimalsState();
};

#endif // HABITAT_H
