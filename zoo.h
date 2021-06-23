#ifndef ZOO_H
#define ZOO_H
#include "habitat.h"
#include "tigre.h"
#include "aigle.h"
#include "poule.h"
#include "budget.h"
#include <vector>
#include <iostream>
using namespace std;
typedef vector<Habitat *> Habitats;

class Zoo
{
    string m_name;
    Budget budget;
    int habitats_tigre;
    int habitats_aigle;
    int habitats_poule;
    Habitats m_tigres;
    Habitats m_aigles;
    Habitats m_poules;

public:
    Zoo(string name = "");
    string getName();
    Budget getBudget();
    void AchatTigre(Tigre *);
    void AchatAigle(Aigle *);
    void AchatPoule(Poule *);
    void AchatHabitatTigre();
    void AchatHabitatAigle();
    void AchatHabitatPoule();
    void VenteTigre(double);
    void VenteAigle(double);
    void VentePoule(double, char);
    void VenteHabitatTigre();
    void VenteHabitatAigle();
    void VenteHabitatPoule();
    Habitats getTigres();
    Habitats getAigles();
    Habitats getPoules();
    void setTigres(Habitats);
    void setAigles(Habitats);
    void setPoules(Habitats);
    void profit();
    void getVisitorsMoney();
    void ageMonthly();
    void feeding();
    void checkAnimalsState();
};

#endif // ZOO_H
