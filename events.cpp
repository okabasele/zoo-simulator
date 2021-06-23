#include "events.h"


void Events::Grossesse(Habitat *habitat)
{
    // // Code littéraire
    // indivi_sante != malade
    // individu_tour > 1
    // individu_faim == false;
    // surpop == false
    // gestation ==false
    // cndition_porte == false
    if (habitat->getSurpop() == false && habitat->getAnimals()[0]->getBabies() + 1 < habitat->getMaxSize())
    {
        for (int i = 0; i < habitat->getAnimalCount(); i++)
        {
            if (habitat->getAnimals()[i]->isOldEnough() && habitat->getAnimals()[i]->isSick() == false && habitat->getAnimals()[i]->isPregnant() == false && habitat->getAnimals()[i]->isHungry() == false && habitat->getAnimals()[i]->getTour() > 1)
            {
                habitat->getAnimals()[i]->becomePregnant();
                cout << "Un animal est tombe enceinte !" << endl;
            }
        }
    }
}

void Events::Naissance(Habitat *habitat)
{
    // // Code littéraire
    // individu_faim == false
    // surpop == false
    if (habitat->getSurpop() == false)
    {
        for (int i = 0; i < habitat->getAnimalCount(); i++)
        {
            if (habitat->getAnimals()[i]->getGestation() == 9 && habitat->getAnimals()[i]->isHungry() == false)
            {
                for (int b = 0; b < habitat->getAnimals()[i]->getBabies(); b++)
                {
                    if (habitat->getEspece() == "tigre")
                    {
                        Tigre *baby = (new Tigre(0, 'f'));
                        baby->setGenderRandomly();
                        habitat->addAnimal(baby);
                    }
                    else if (habitat->getEspece() == "aigle")
                    {
                        Aigle *baby = (new Aigle(0, 'f'));
                        baby->setGenderRandomly();
                        habitat->addAnimal(baby);
                    }
                    else if (habitat->getEspece() == "poule")
                    {
                        Poule *baby = (new Poule(0, 'f'));
                        baby->setGenderRandomly();
                        habitat->addAnimal(baby);
                    }
                }
            }
        }
        cout << "Un animal a accouché!" << endl;
    }
}

void Events::Mort_infantile(Habitat *habitat)
{
    // // Code littéraire
    // gestation == true
    for (int i = 0; i < habitat->getAnimalCount(); i++)
    {
        if (habitat->getAnimals()[i]->isPregnant() == true)
        {
            habitat->getAnimals()[i]->setBabies(habitat->getAnimals()[i]->getBabies() / 2);
            cout << "Un animal a perdu la moitie de ses bebes." << endl;
            return;
        }
    }
}

void Events::Mort_individu(Habitat *habitat)
{
    // // Code littéraire
    // indivi_age > esperance_de_vie
    // individu_santé == malade
    // surpop == true

    for (int i = 0; i < habitat->getAnimalCount(); i++)
    {
        if (habitat->getAnimals()[i]->getAge() >= 25 || habitat->getAnimals()[i]->isSick() == true)
        {
            habitat->getAnimals()[i]->becomePregnant();
            cout << "Un animal est mort." << endl;
        }
    }
}

void Events::Surpopulation(Habitat *habitat)
{
    //     // Code littéraire
    //    len(habitant) > capacité
    if (habitat->getAnimalCount() > habitat->getMaxSize())
    {
        habitat->setSurpop();
        habitat->removeRandomAnimal();
        cout << "Un animal est mort du a la surpopulation." << endl;
    }
}

void Events::Maladie(Habitat *habitat)
{
    //     // Code littéraire
    //    individu == malade

    //Pick animal randomly
    int random = rand() % habitat->getAnimalCount();
    habitat->getAnimals()[random]->becomeSick();
    cout << "Un animal est tombe malade." << endl;
}