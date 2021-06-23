#include "aigle.h"

//Constructor to initialize values of Aigle object
Aigle::Aigle(double year, char g)
{
    malade = false;
    tour = 1;
    faim = false;
    gestation = 0;
    multiplier = 0;
    age = year;
    gender = g;
    m_current_state = 0;
    numberOfBabies = 2;
    payoff = 43800;
    foodCost = 75;
}

//Function to return the food cost of the Aigle
int Aigle::getFoodCost()
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

//Function to return the buying price of the Aigle
int Aigle::getBuyingPrice()
{
    int price=0;
    if (age == 0.5)
    {
        price = 1000;
    }
    else if (age == 4)
    {
        price = 4000;
    }
    else if (age == 14)
    {
        price = 2000;
    }
    return price;
}

//Function to return the selling price of the Aigle
int Aigle::getSellingPrice()
{
    int price=0;
    if (age == 0.5)
    {
        price = 500;
    }
    else if (age == 4)
    {
        price = 2000;
    }
    else if (age == 14)
    {
        price = 400;
    }
    return price;
}
