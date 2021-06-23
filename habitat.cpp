#include "habitat.h"

//Function to set animal species
void Habitat::setEspece(string espece)
{
    m_espece = espece;
}
//Function to set animal species
string Habitat::getEspece()
{
    return m_espece;
}
//Function to set the max number of animals in array
void Habitat::setMaxSize(int max)
{
    m_maxSize = max;
}

//Function to get the max number of animals in array
int Habitat::getMaxSize()
{
    return m_maxSize;
}

//Function to init the number of animals in array
void Habitat::initAnimalCount(int init)
{
    m_animals_count = init;
}

//Function to add a animal to the array of animals when we buy it
void Habitat::addAnimal(IAnimal *animal)
{

    m_animals_count++;
    m_animals.push_back(animal);
}

//Function to remove a animal from array of m_animals when we sell it
void Habitat::removeAnimal(IAnimal *animal)
{
    for (int i = 0; i < m_animals_count; i++)
    {
        if (m_animals[i]->getAge() == animal->getAge() && m_animals[i]->getGender() == animal->getGender())
        {
            m_animals[i] = m_animals[i + 1];
        }
    }
    m_animals_count--;
}

//Function to remove a random animal from array of m_animals
void Habitat::removeRandomAnimal()
{
    int random = rand() % m_animals_count;
    for (int x = random; x < m_animals_count; x++)
    {
        m_animals[x] = m_animals[x + 1];
    }
    m_animals_count--;
}

//Function to return the number of animals currently in array
int Habitat::getAnimalCount()
{
    return m_animals_count;
}

//Function to return the array
AnimalList Habitat::getAnimals()
{
    return m_animals;
}
//Function to set the array
void Habitat::setAnimals(AnimalList animals)
{
    m_animals = animals;
}
//Function to return the money to remove at the beginning of each day for feeding animals
int Habitat::feedingCost()
{
    return m_animals[0]->getFoodCost() * m_animals_count;
}

//Function to return the money to remove at the beginning of each day for feeding animals
int Habitat::payOff()
{
    return m_animals[0]->getPayoff() * m_animals_count;
}

//Function to get surpop value
bool Habitat::getSurpop()
{
    return surpop;
}

//Function to set surpop variable
void Habitat::setSurpop()
{
    surpop = true;
}

//Function to check animals's state.
void Habitat::checkAnimalsState()
{
    for (int i = 0; i < m_animals_count; i++)
    {
        if (m_espece == "tigre" || m_espece == "aigle")
        {
            m_animals[i]->checkState(UNKNOWN, BABY, true);
            m_animals[i]->checkState(BABY, ADULT, m_animals[i]->getAge() > 4);

            m_animals[i]->checkState(ADULT, OLD, m_animals[i]->getAge() > 14);

            m_animals[i]->checkState(OLD, DEAD, m_animals[i]->getAge() > 25);

            m_animals[i]->checkState(ADULT, CAN_CREATE_CHILDREN, m_animals[i]->getGender() == 'f');

            m_animals[i]->checkState(ADULT, LOOK_FOR_FEMALE, m_animals[i]->getGender() == 'm');
            if (m_animals[i]->getState() == OLD)
            {
                removeAnimal(m_animals[i]);
            }
        }
        else if (m_espece == "poule")
        {
            m_animals[i]->checkState(UNKNOWN, BABY, true);
            m_animals[i]->checkState(BABY, ADULT, m_animals[i]->getAge() > 0.5);

            m_animals[i]->checkState(ADULT, OLD, m_animals[i]->getAge() > 8);

            m_animals[i]->checkState(OLD, DEAD, m_animals[i]->getAge() > 15);

            m_animals[i]->checkState(ADULT, CAN_CREATE_CHILDREN, m_animals[i]->getGender() == 'f');

            m_animals[i]->checkState(ADULT, LOOK_FOR_FEMALE, m_animals[i]->getGender() == 'm');
            if (m_animals[i]->getState() == OLD)
            {
                removeAnimal(m_animals[i]);
            }
        }
    }
}