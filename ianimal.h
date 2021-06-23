#ifndef IANIMAL_H
#define IANIMAL_H
#include <stdlib.h>

const int UNKNOWN = 0;
const int BABY = 1;
const int ADULT = 2;
const int CAN_CREATE_CHILDREN = 3;
const int LOOK_FOR_FEMALE = 4;
const int OLD = 5;
const int DEAD = 6;
const int LIFE_SPAN = 25;
class IAnimal
{
protected:
	int m_current_state;
	bool malade;
	bool faim;
	int tour;
	int gestation;

	double age;
	int numberOfBabies;
	int payoff;
	int foodCost;
	int multiplier; //if animal is pregnant
	char gender;	//'f' = Female // 'm' = Male
public:
    virtual int getFoodCost()=0,
    getBuyingPrice()=0,
    getSellingPrice()=0;

    int getBabies(),
    getPayoff(),
    getTour(),
    getGestation(),
    getState();

    void setAge(double),
    setGender(char),
    setGenderRandomly(),
    setBabies(int),
    becomePregnant(),
    becomeSick(),
    checkState(int, int, bool);

    double getAge();
    char getGender();
    bool isSick(),
    isPregnant(),
    isHungry(),
    isOldEnough();


};

#endif // IANIMAL_H
