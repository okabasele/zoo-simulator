#include "budget.h"

//Initialize budget
Budget::Budget()
{
    money = 80000;
}

//Function to return the current amount of money
int Budget::getMoney()
{
    return money;
}

//Function to set the current amount of money
void Budget::setMoney(int amount)
{
    money = amount;
}
