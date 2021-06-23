#ifndef EVENTS_H
#define EVENTS_H
#include "habitat.h"
#include "tigre.h"
#include "aigle.h"
#include "poule.h"
#include <iostream>
using namespace std;
class Events
{

public:
    void Grossesse(Habitat *);
    void Naissance(Habitat *);
    void Mort_infantile(Habitat *);
    void Mort_individu(Habitat *);
    void Maladie(Habitat *);
    void Surpopulation(Habitat *);
};

#endif // EVENTS_H
