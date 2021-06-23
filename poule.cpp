#include "poule.h"

//Constructor to initialize values of Poule object
Poule::Poule(double year, char g)
{
    malade = false;
    tour = 1;
    faim = false;
    gestation = 0;
    multiplier = 0;
    age = year;
    gender = g;
    m_current_state = 0;
    numberOfBabies = 4;
    payoff = 43800;
    foodCost = 75;
}

//Function to return the food cost of the Poule
int Poule::getFoodCost()
{
    if (gender == 'f')
    {
        foodCost *= 10 * multiplier;
    }
    else
    {
        foodCost *= 12;
    }

    return foodCost;
}

//Function to return the buying price of the Poule
int Poule::getBuyingPrice()
{
    int price=0;
    if (gender == 'f')
    {
        if (age == 0.5)
        {
            price = 20;
        }
    }
    else
    {
        if (age == 0.5)
        {
            price = 100;
        }
    }

    return price;
}

//Function to return the selling price of the Poule
int Poule::getSellingPrice()
{
    int price=0;
    if (gender == 'f')
    {
        if (age == 0.5)
        {
            price = 10;
        }
    }
    else
    {
        if (age == 0.5)
        {
            price = 20;
        }
    }

    return price;
}
