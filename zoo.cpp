#include "zoo.h"

//Get budget
Budget Zoo::getBudget()
{
    return budget;
}

//Initialization Zoo
Zoo::Zoo(string name)
    :m_name(name)
{
    //NOMBRE D'HABITATS
    habitats_tigre = 1;
    habitats_aigle = 1;
    habitats_poule = 2;

    //TIGRES
    m_tigres[0]->addAnimal(new Tigre(0.5, 'f'));
    m_tigres[0]->addAnimal(new Tigre(0.5, 'm'));

    //AIGLES
    m_aigles[0]->addAnimal(new Aigle(0.5, 'f'));
    m_aigles[0]->addAnimal(new Aigle(0.5, 'm'));

    //POULES
    for (int i = 0; i < habitats_poule; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i == 0 && j == 0) //ajouter un coq
            {
                m_poules[0]->addAnimal(new Poule(0.5, 'm'));
            }
            else if (i == 0) //ajouter 9 poules
            {
                m_poules[0]->addAnimal(new Poule(0.5, 'f'));
            }
        }
        m_poules[1]->addAnimal(new Poule(0.5, 'f')); //10eme poule dans un autre habitat
    }
    cout <<"CONSTRUCTION ZOO OBJECT DONE"<<endl;
}


string Zoo::getName(){
    return m_name;
}

//Function to buy a new tigre
void Zoo::AchatTigre(Tigre *tigre)
{
    int money;
    for (int i = 0; i < habitats_tigre; i++)
    {
        //Check if the array is currently full.
        if (m_tigres[i]->getAnimalCount() + 1 < 2)
        {
            m_tigres[i]->addAnimal(tigre);
            money = budget.getMoney() - tigre->getBuyingPrice();
            budget.setMoney(money);
            cout << "Vous avez acheter un nouveau tigre." << endl;
            return;
        }
        else if (i == habitats_tigre - 1)
        {
            cout << "Vous ne pouvez pas acheter un tigre." << endl;
            return;
        }
    }
}

//Function to buy a new aigle
void Zoo::AchatAigle(Aigle *aigle)
{
    int money;
    for (int i = 0; i < habitats_aigle; i++)
    {
        //Check if the array is currently full.
        if (m_aigles[i]->getAnimalCount() + 1 < 2)
        {
            m_aigles[i]->addAnimal(aigle);
            money = budget.getMoney() - aigle->getBuyingPrice();
            budget.setMoney(money);
            cout << "Vous avez acheter un nouveau aigle." << endl;
            return;
        }
        else if (i == habitats_tigre - 1)
        {
            cout << "Vous ne pouvez pas acheter un aigle." << endl;
            return;
        }
    }
}

//Function to buy a new poule
void Zoo::AchatPoule(Poule *poule)
{
    int money;
    for (int i = 0; i < habitats_poule; i++)
    {
        //Check if the array is currently full.
        if (m_poules[i]->getAnimalCount() + 1 < 2)
        {
            m_poules[i]->addAnimal(poule);
            money = budget.getMoney() - poule->getBuyingPrice();
            budget.setMoney(money);
            cout << "Vous avez acheter une nouvelle poule." << endl;
            return;
        }
        else if (i == habitats_tigre - 1)
        {
            cout << "Vous ne pouvez pas acheter une poule." << endl;
            return;
        }
    }
}

//Function to buy new habitat for tigres
void Zoo::AchatHabitatTigre()
{
    habitats_tigre++;
    Habitat *tigres = new Habitat();
    tigres->setMaxSize(2);
    tigres->initAnimalCount(0);
    tigres->setEspece("tigre");
    m_tigres.push_back(tigres);

    int money = budget.getMoney() - 2000;
    budget.setMoney(money);
    cout << "Vous avez acheter un nouvel habitat pour vos tigres." << endl;
}

//Function to buy new habitat for aigles
void Zoo::AchatHabitatAigle()
{
    habitats_aigle++;
    Habitat *aigles = new Habitat();

    aigles->setMaxSize(4);
    aigles->initAnimalCount(0);
    aigles->setEspece("aigle");
    m_aigles.push_back(aigles);
    int money = budget.getMoney() - 2000;
    budget.setMoney(money);
    cout << "Vous avez acheter un nouvel habitat pour vos aigles." << endl;
}

//Function to buy new habitat for poules
void Zoo::AchatHabitatPoule()
{
    habitats_poule++;
    Habitat *poules = new Habitat();
    poules->setMaxSize(4);
    poules->initAnimalCount(0);
    poules->setEspece("poule");
    m_poules.push_back(poules);
    int money = budget.getMoney() - 300;
    budget.setMoney(money);
    cout << "Vous avez acheter un nouvel habitat pour vos poules." << endl;
}

//Function to sell a specific tigre
void Zoo::VenteTigre(double year)
{
    int money;

    for (int i = 0; i < habitats_tigre; i++)
    {

        for (int j = 0; j < m_tigres[i]->getAnimalCount(); j++)
        {
            if (m_tigres[i]->getAnimals()[j]->getAge() == year)
            {
                money = budget.getMoney() + m_tigres[i]->getAnimals()[j]->getSellingPrice();
                m_tigres[i]->removeAnimal(m_tigres[i]->getAnimals()[j]);
                budget.setMoney(money);
                cout << "Vous avez vendu un tigre" << endl;
            }
            else if (i == habitats_tigre - 1 && j == m_tigres[i]->getAnimalCount() - 1)
            {
                cout << "Vous ne pouvez pas vendre un tigre" << endl;
            }
        }
    }
}

//Function to sell a specific aigle
void Zoo::VenteAigle(double year)
{
    int money;

    for (int i = 0; i < habitats_aigle; i++)
    {

        for (int j = 0; j < m_aigles[i]->getAnimalCount(); j++)
        {
            if (m_aigles[i]->getAnimals()[j]->getAge() == year)
            {
                money = budget.getMoney() + m_aigles[i]->getAnimals()[j]->getSellingPrice();
                m_aigles[i]->removeAnimal(m_aigles[i]->getAnimals()[j]);
                budget.setMoney(money);
                cout << "Vous avez vendu un aigle" << endl;
            }
            else if (i == habitats_aigle - 1 && j == m_aigles[i]->getAnimalCount() - 1)
            {
                cout << "Vous ne pouvez pas vendre un aigle" << endl;
            }
        }
    }
}

//Function to sell a specific poule
void Zoo::VentePoule(double year, char g)
{
    int money;

    for (int i = 0; i < habitats_poule; i++)
    {

        for (int j = 0; j < m_poules[i]->getAnimalCount(); j++)
        {
            if (m_poules[i]->getAnimals()[j]->getAge() == year && m_poules[i]->getAnimals()[j]->getGender() == g)
            {
                money = budget.getMoney() + m_poules[i]->getAnimals()[j]->getSellingPrice();
                m_poules[i]->removeAnimal(m_poules[i]->getAnimals()[j]);
                budget.setMoney(money);
                cout << "Vous avez vendu une poule" << endl;
            }
            else if (i == habitats_poule - 1 && j == m_poules[i]->getAnimalCount() - 1)
            {
                cout << "Vous ne pouvez pas vendre une poule" << endl;
            }
        }
    }
}

//Function to sell the newest habitat for tigres
void Zoo::VenteHabitatTigre()
{
    habitats_tigre--;
    m_tigres.pop_back();
    int money = budget.getMoney() - 2000;
    budget.setMoney(money);
    cout << "Vous avez vendu un habitat pour tigres" << endl;
}

//Function to sell the newest habitat for aigles
void Zoo::VenteHabitatAigle()
{
    habitats_aigle--;
    m_aigles.pop_back();
    int money = budget.getMoney() - 2000;
    budget.setMoney(money);
    cout << "Vous avez vendu un habitat pour aigles" << endl;
}

//Function to sell the newest habitat for poules
void Zoo::VenteHabitatPoule()
{
    habitats_poule--;
    m_poules.pop_back();
    int money = budget.getMoney() - 300;
    budget.setMoney(money);
    cout << "Vous avez vendu un habitat pour poules" << endl;
}

//Returns the vector m_tigres
Habitats Zoo::getTigres()
{
    return m_tigres;
}

//Returns the vector m_aigles
Habitats Zoo::getAigles()
{
    return m_aigles;
}

//Returns the vector m_poules
Habitats Zoo::getPoules()
{
    return m_poules;
}

//Sets the vector m_tigres
void Zoo::setTigres(Habitats tigres)
{
    m_tigres = tigres;
}

//Sets the vector m_aigles
void Zoo::setAigles(Habitats aigles)
{
    m_aigles = aigles;
}

//Sets the vector m_poules
void Zoo::setPoules(Habitats poules)
{
    m_poules = poules;
}

//Function to add money each year
void Zoo::profit()
{
    int money = 0;
    for (int i = 0; i < habitats_tigre; i++)
    {
        money += m_tigres[i]->payOff();
    }
    for (int i = 0; i < habitats_aigle; i++)
    {
        money += m_aigles[i]->payOff();
    }
    for (int i = 0; i < habitats_poule; i++)
    {
        money += m_poules[i]->payOff();
    }

    int payoff = budget.getMoney() + money;
    budget.setMoney(payoff);
}

//Function to return the money made each day
void Zoo::getVisitorsMoney()
{
    int price = 0;
    if (m_tigres.empty() == false)
    {
        price += 400;
    }
    else if (m_aigles.empty() == false)
    {
        price += 300;
    }
    else if (m_poules.empty() == false)
    {
        price += 50;
    }
    budget.setMoney(budget.getMoney() + price);
}

//Function to age each animal at the beginning of each day
void Zoo::ageMonthly()
{
    for (int i = 0; i < habitats_tigre; i++)
    {
        AnimalList tmp = m_tigres[i]->getAnimals();
        for (int j = 0; i < m_tigres[i]->getAnimalCount(); i++)
        {
            tmp[j]->setAge(tmp[j]->getAge() + 0.1);
        }
        m_tigres[i]->setAnimals(tmp);
    }
    for (int i = 0; i < habitats_aigle; i++)
    {
        AnimalList tmp = m_aigles[i]->getAnimals();
        for (int j = 0; i < m_aigles[i]->getAnimalCount(); i++)
        {
            tmp[j]->setAge(tmp[j]->getAge() + 0.1);
        }
        m_aigles[i]->setAnimals(tmp);
    }
    for (int i = 0; i < habitats_poule; i++)
    {
        AnimalList tmp = m_poules[i]->getAnimals();
        for (int j = 0; i < m_poules[i]->getAnimalCount(); i++)
        {
            tmp[j]->setAge(tmp[j]->getAge() + 0.1);
        }
        m_poules[i]->setAnimals(tmp);
    }
}

//Checks animals's state
void Zoo::checkAnimalsState()
{
    for (int i = 0; i < habitats_tigre; i++)
    {
        m_tigres[i]->checkAnimalsState();
    }
    for (int i = 0; i < habitats_aigle; i++)
    {
        m_aigles[i]->checkAnimalsState();
    }
    for (int i = 0; i < habitats_poule; i++)
    {
        m_poules[i]->checkAnimalsState();
    }
}

void Zoo::feeding()
{
    int cost = 0;
    //nourrir les tigres
    for (int i = 0; i < habitats_tigre; i++)
    {
        cost += m_tigres[i]->feedingCost();
    }
    //nourrir les aigles
    for (int i = 0; i < habitats_aigle; i++)
    {
        cost += m_aigles[i]->feedingCost();
    }
    //nourrir les poules
    for (int i = 0; i < habitats_poule; i++)
    {
        cost += m_poules[i]->feedingCost();
    }
    cout << "Vous avez nourrit tout les animaux." << endl;
    budget.setMoney(budget.getMoney() - cost);
}
