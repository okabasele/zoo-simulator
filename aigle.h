#ifndef AIGLE_H
#define AIGLE_H
#include <string>
#include "ianimal.h"

using namespace std;

class Aigle : public IAnimal
{
public:
    Aigle(double, char);
    virtual int getFoodCost(),
    getBuyingPrice(),
    getSellingPrice();
};

#endif // AIGLE_H