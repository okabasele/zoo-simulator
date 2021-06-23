#ifndef POULE_H
#define POULE_H
#include <string>
#include "ianimal.h"

using namespace std;

class Poule : public IAnimal
{
public:
    Poule(double, char);
    virtual int getFoodCost(),
    getBuyingPrice(),
    getSellingPrice();
};

#endif // POULE_H
