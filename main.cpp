#include "zoo.h"
#include "events.h"
#include <vector>
#include <iostream>
using namespace std;

// #include "bdd.hpp"

//Ask user if he wants to buy an animal
int InputChoice()
{
    int choix;
    cout << "Voulez-vous faire?" << endl;
    cout << "1. Acheter un animal.\n";
    cout << "2. Vendre un animal.\n";
    cout << "3. Acheter un habitat.\n";
    cout << "4. Vendre un habitat.\n";
    cout << "5. Rien.\n";
    cin >> choix;
    while (choix < 1 || choix > 5)
    {
        cout << "Voulez-vous faire?" << endl;
        cout << "1. Acheter un animal.\n";
        cout << "2. Vendre un animal.\n";
        cout << "3. Acheter un habitat.\n";
        cout << "4. Vendre un habitat.\n";
        cout << "5. Consulter le budget.\n";
        cout << "6. Rien.\n";
        cin.clear();
        cin.ignore();
        cin >> choix;
    }
    return choix;
}

//Input animal species
int InputSpecies()
{
    int espece;
    cout << "\nQuel espece voulez-vous?" << endl;
    cout << "1. Tigre\n";
    cout << "2. Aigle\n";
    cout << "3. Poule\n";
    cin >> espece;
    while (espece < 1 || espece > 3)
    {
        cout << "\nErreur. Entree invalide.\n";
        cout << "Veuillez recommencer.\n\n";

        cout << "\nQuel espece voulez-vous?" << endl;
        cout << "1. Tigre\n";
        cout << "2. Aigle\n";
        cout << "3. Poule\n";
        cin.clear();
        cin.ignore();
        cin >> espece;
    }
    return espece;
}

//Input age for the animal
int InputAge()
{
    int age;
    cout << "\nQuel tranche d'age vous interresse?" << endl;
    cout << "1. Bebe\n";
    cout << "2. Adult\n";
    cout << "3. Age\n";
    cin >> age;
    while (age < 1 || age > 3)
    {
        cout << "\nErreur. Entree invalide.\n";
        cout << "Veuillez recommencer.\n\n";

        cout << "\nQuel tranche d'age vous interresse?" << endl;
        cout << "1. Bebe\n";
        cout << "2. Adult\n";
        cout << "3. Age\n";
        cin.clear();
        cin.ignore();
        cin >> age;
    }
    return age;
}

//Input gender for the animal
int InputGender()
{
    int gender;
    cout << "\n Quel type d'animal voulez-vous?" << endl;
    cout << "1. Masculin\n";
    cout << "2. Feminin\n";
    cin >> gender;
    while (gender < 1 || gender > 3)
    {
        cout << "\nErreur. Entree invalide.\n";
        cout << "Veuillez recommencer.\n\n";

        cout << "\n Quel type d'animal voulez-vous?" << endl;
        cout << "1. Masculin\n";
        cout << "2. Feminin\n";
        cin.clear();
        cin.ignore();
        cin >> gender;
    }
    return gender;
}

//User buy an animal
void BuyAnimal(Zoo zoo)
{
    int m_species=0;
    int m_gender=0;
    int m_animalAge=0;
    m_species = InputSpecies();
    m_gender = InputGender();
    switch (m_species)
    {
    case 1:
        m_animalAge = InputAge();
        if (m_gender == 1)
        {
            if (m_animalAge == 1)
            {
                zoo.AchatTigre(new Tigre(0.5, 'm'));
            }
            else if (m_animalAge == 2)
            {
                zoo.AchatTigre(new Tigre(4, 'm'));
            }
            else if (m_animalAge == 3)
            {
                zoo.AchatTigre(new Tigre(14, 'm'));
            }
        }
        else if (m_gender == 2)
        {
            if (m_animalAge == 1)
            {
                zoo.AchatTigre(new Tigre(0.5, 'f'));
            }
            else if (m_animalAge == 2)
            {
                zoo.AchatTigre(new Tigre(4, 'f'));
            }
            else if (m_animalAge == 3)
            {
                zoo.AchatTigre(new Tigre(14, 'f'));
            }
        }

        break;

    case 2:
        m_animalAge = InputAge();
        if (m_gender == 1)
        {
            if (m_animalAge == 1)
            {
                zoo.AchatAigle(new Aigle(0.5, 'm'));
            }
            else if (m_animalAge == 2)
            {
                zoo.AchatAigle(new Aigle(4, 'm'));
            }
            else if (m_animalAge == 3)
            {
                zoo.AchatAigle(new Aigle(14, 'm'));
            }
        }
        else if (m_gender == 2)
        {
            if (m_animalAge == 1)
            {
                zoo.AchatAigle(new Aigle(0.5, 'f'));
            }
            else if (m_animalAge == 2)
            {
                zoo.AchatAigle(new Aigle(4, 'f'));
            }
            else if (m_animalAge == 3)
            {
                zoo.AchatAigle(new Aigle(14, 'f'));
            }
        }

        break;

    case 3:
        if (m_gender == 1)
        {
            zoo.AchatPoule(new Poule(0.5, 'm'));
        }
        else if (m_gender == 2)
        {
            zoo.AchatPoule(new Poule(0.5, 'f'));
        }

        break;
    }
}

//User sell an animal
void SellAnimal(Zoo zoo)
{
    double age = 0;
    int m_species=0;
    int m_animalAge=0;
    int m_gender=0;
    m_species = InputSpecies();
    switch (m_species)
    {
    case 1:
        m_animalAge = InputAge();

        if (m_animalAge == 1)
        {
            age = 0.5;
        }
        else if (m_animalAge == 2)
        {
            age = 4;
        }
        else if (m_animalAge == 3)
        {
            age = 14;
        }

        zoo.VenteTigre(age);
        break;

    case 2:
        m_animalAge =InputAge();
        if (m_animalAge == 1)
        {
            age = 0.5;
        }
        else if (m_animalAge == 2)
        {
            age = 4;
        }
        else if (m_animalAge == 3)
        {
            age = 14;
        }

        zoo.VenteAigle(age);
        break;

    case 3:
        m_gender = InputGender();
        if (m_gender == 1)
        {
            zoo.VentePoule(0.5, 'm');
        }
        else if (m_gender == 2)
        {

            zoo.VentePoule(0.5, 'f');
        }
        break;
    }
}

//User buy an animal habitat
void BuyHabitat(Zoo zoo)
{
    int m_species;
    m_species = InputSpecies();
    switch (m_species)
    {
    case 1:
        zoo.AchatHabitatTigre();
        break;
    case 2:
        zoo.AchatHabitatAigle();
        break;
    case 3:
        zoo.AchatHabitatPoule();
        break;

    default:
        break;
    }
}

//User sell an animal habitat
void SellHabitat(Zoo zoo)
{
    int m_species;
    m_species = InputSpecies();
    switch (m_species)
    {
    case 1:
        zoo.VenteHabitatTigre();
        break;
    case 2:
        zoo.VenteHabitatAigle();
        break;
    case 3:
        zoo.VenteHabitatPoule();
        break;

    default:
        break;
    }
}

//User menu
void Menu(Zoo zoo)
{
    int choice = InputChoice();
    switch (choice)
    {
    case 1:
        BuyAnimal(zoo);
        break;
    case 2:
        SellAnimal(zoo);
        break;
    case 3:
        BuyHabitat(zoo);
        break;
    case 4:
        SellHabitat(zoo);
        break;
    case 5:
        return;
    default:
        break;
    }
}

//Function to create a random event each day
void RandomEvent(Zoo zoo)
{
    Events m_events;
    int event = rand() % 6 + 1;
    Habitat *aigles = zoo.getAigles()[0];
    switch (event)
    {
    //Grossesse
    case 1:
        m_events.Grossesse(aigles);
        break;

    //Naissance
    case 2:
        m_events.Naissance(aigles);
        break;

    //Mort infantile
    case 3:
        m_events.Mort_infantile(aigles);
        break;

    //Mort individu
    case 4:
        m_events.Mort_individu(aigles);
        break;

    //Maladie
    case 5:
        m_events.Maladie(aigles);
        break;

    //Surpopulation
    case 6:
        m_events.Surpopulation(aigles);
        break;
    default:
        break;
    }
    zoo.getAigles()[0]->setAnimals(aigles->getAnimals());
}

void Run(Zoo zoo)
{
    cout << "Bienvenue au " << zoo.getName() << " !" << endl;
    int tour = 1;
    while (tour < 3)
    {
        cout << "Mois " << tour << endl;
        RandomEvent(zoo);
        Menu(zoo);
        zoo.feeding();
        zoo.ageMonthly();
        zoo.checkAnimalsState();
        cout << "\nLe mois " << tour << " se termine." << endl;
        cout << "Current Stats:" << endl;
        cout << "\nMoney: $" << zoo.getBudget().getMoney() << endl;
        cout << "Tigres: " << zoo.getTigres().size() << endl;
        cout << "Aigles: " << zoo.getTigres().size() << endl;
        cout << "Poules: " << zoo.getTigres().size() << endl;
        cout << "---------------------------------------------------";
        tour++;
    }
}

void Game()
{
    Zoo zoo("Zoo de la Montagne");
    Run(zoo);
}

int main()
{
    Game();
    return 0;
}
