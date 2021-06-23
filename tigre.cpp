#include "tigre.h"

//Constructor to initialize values of Tigre object
Tigre::Tigre(double year, char g)
{
    malade = false;
    tour = 1;
    faim = false;
    gestation = 0;
    multiplier = 0;
    gender = g;
    age = year;
    m_current_state = 0;
    numberOfBabies = 2;
    payoff = 43800;
    foodCost = 75;
}

//Function to return the food cost of the Tigre
int Tigre::getFoodCost()
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

//Function to return the buying price of the Tigre
int Tigre::getBuyingPrice()
{
    int price=0;
    if (age == 0.5)
    {
        price = 3000;
    }
    else if (age == 4)
    {
        price = 120000;
    }
    else if (age == 14)
    {
        price = 60000;
    }
    return price;
}

//Function to return the selling price of the Tigre
int Tigre::getSellingPrice()
{
    int price=0;
    if (age == 0.5)
    {
        price = 1500;
    }
    else if (age == 4)
    {
        price = 60000;
    }
    else if (age == 14)
    {
        price = 10000;
    }
    return price;
}
