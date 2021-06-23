#ifndef TIGRE_H
#define TIGRE_H

#include "ianimal.h"

#include <string>

using namespace std;

class Tigre : public IAnimal
{
public:
    Tigre(double, char);
    virtual int getFoodCost(),
    getBuyingPrice(),
    getSellingPrice();
};

#endif // TIGRE_H
