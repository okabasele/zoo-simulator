#include "ianimal.h"

//Set the age of the animal
void IAnimal::setAge(double year)
{
	age = year;
}

//Set the gender of the animal
void IAnimal::setGender(char g)
{

	gender = g;
}

//Set the gender of newborn babies randomly
void IAnimal::setGenderRandomly()
{
	int chance = (rand() % 10) + 1;
	if (chance == 3 || chance == 6 || chance == 9)
	{
		gender = 'f';
	}
	else
	{
		gender = 'm';
	}
}

//Set the number of babies of the animal
void IAnimal::setBabies(int babies)
{
	numberOfBabies = babies;
}

//Set the multiplier if animal is pregnant
void IAnimal::becomePregnant()
{
	gestation = 1;
	multiplier = 2;
}

//Function to get the age of the animal
double IAnimal::getAge()
{
	return age;
}

//Function to get the gender of the animal
char IAnimal::getGender()
{
	return gender;
}

//Function to get the number of babies of the animal
int IAnimal::getBabies()
{
	return numberOfBabies;
}

//Function to get the payoff amount for the animal
int IAnimal::getPayoff()
{
	return payoff;
}

bool IAnimal::isSick()
{
	return malade;
}

void IAnimal::becomeSick()
{
	malade = true;
}

bool IAnimal::isPregnant()
{
	if (gestation != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int IAnimal::getTour()
{
	return tour;
}

int IAnimal::getGestation()
{
	return gestation;
}

bool IAnimal::isHungry()
{
	return faim;
}

bool IAnimal::isOldEnough()
{
	if (m_current_state == CAN_CREATE_CHILDREN)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Check animal state
void IAnimal::checkState(int src_state, int target_state, bool condition)
{
	if (m_current_state == src_state && condition)
	{
		m_current_state = target_state;
	}
}

//Get animal state
int IAnimal::getState()
{
	return m_current_state;
}
