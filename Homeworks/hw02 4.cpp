/*
hw02.cpp
Programmer: Jerry Wan
This program models a game of medieval times in which warriors fight each other
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


struct Warrior
{
    string name;
    int strength;
};


void processText (ifstream& ifs, vector<Warrior>& warriors);

void Status (const vector<Warrior>& vectWarrior);

void Battle (string warrior1, string warrior2, vector<Warrior>& vectWarrior);


int main()
{
    ifstream ifs ("warriors.txt");
    if (!ifs)
    {
        cerr << "Could not open file!" << endl;
        exit (1);
    }
    vector<Warrior> warriors;
    processText(ifs, warriors);
    return 0;
}


void processText (ifstream& ifs, vector<Warrior>& warriors) //This function fills the Struct
{
    string warrior;
    string warriorName;
    int warriorStrength;
    string BattleWarrior1, BattleWarrior2;
    while (ifs >> warrior)
    {
        if (warrior == "Warrior")
        {
            ifs >> warriorName;
            ifs >> warriorStrength;
            Warrior warriorStruct;
            warriorStruct.name = warriorName;
            warriorStruct.strength = warriorStrength;
            warriors.push_back(warriorStruct);
        }
        else if (warrior == "Status")
        {
            Status(warriors);
        }
        else if (warrior == "Battle")
        {
            ifs >> BattleWarrior1;
            ifs >> BattleWarrior2;
            Battle (BattleWarrior1, BattleWarrior2, warriors);
        }
    }
}


void Status (const vector<Warrior>& vectWarrior) //This function displays the status of the warriors
{
    size_t warriorCount = vectWarrior.size();
    cout << "There are: " << warriorCount << " warriors" << endl;
    for (Warrior x : vectWarrior)
    {
        cout << "Warrior: " << x.name << ", Strength: " << x.strength << endl;
    }
}


void Battle (string warrior1, string warrior2, vector<Warrior>& vectWarrior) //This function executes battles
{
    cout << warrior1 << " Battles " << warrior2 << endl;
    int warrior1strength = 0, warrior2strength = 0;
    for (Warrior& i : vectWarrior)
    {
        if (i.name == warrior1)
        {
            warrior1strength = i.strength;
        }
        else if (i.name == warrior2)
        {
            warrior2strength = i.strength;
        }
    }
    if (warrior1strength > warrior2strength)
    {
        cout << warrior1 << " defeats " << warrior2 << endl;
        warrior1strength = warrior1strength - warrior2strength;
        warrior2strength = 0;
    }
    else if (warrior2strength > warrior1strength)
    {
        cout << warrior2 << " defeats " << warrior1 << endl;
        warrior2strength = warrior2strength - warrior1strength;
        warrior1strength = 0;
    }
    else if (warrior1strength == warrior2strength)
    {
        cout << "Mutual Annihilation: " << warrior1 << " and " << warrior2 << " die at each other's hands" << endl;
        warrior1strength = 0;
        warrior2strength = 0;
    }
    for (Warrior& i : vectWarrior)
    {
        if (i.name == warrior1)
        {
            i.strength = warrior1strength;
        }
        else if (i.name == warrior2)
        {
            i.strength = warrior2strength;
        }
    }
}