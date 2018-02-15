/*
Programmer: Jerry Wan
hw06.cpp
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Lord;

class Noble
{
private:
    string name;
    unsigned strength;
    bool alive;

public:
    virtual void battle(Noble &n) = 0;
    virtual void die() = 0;
    virtual unsigned get_strength() = 0;
    virtual void set_strength(unsigned stg) = 0;
    virtual string get_name() const = 0;
    virtual bool is_alive() = 0;
    virtual void battle_cry() const = 0; 
};

void Noble::battle(Noble &n)
{
    cout << this->get_name() << " battles " << n.get_name() << "\n";
    if (!this->is_alive() && !n.is_alive())
        cout << "Oh, NO! They're both dead! Yuck!\n";
    else if (!this->is_alive())
        cout << this->get_name() << " is already dead.\n";
    else if (!n.is_alive())
        cout << n.get_name() << " is already dead.\n";
    else if (this->get_strength() > n.get_strength())
    {
        this->battle_cry();
        n.battle_cry();
        cout << this->get_name() << " defeats " << n.get_name() << "\n";
        double ratio = (double)n.get_strength() / (double)this->get_strength();
        n.die();
        this->set_strength((double)this->get_strength() * ratio);
    }
    else if (this->get_strength() < n.get_strength())
    {
        this->battle_cry();
        n.battle_cry();
        cout << n.get_name() << " defeats " << this->get_name() << "\n";
        double ratio = (double)this->get_strength() / (double)n.get_strength();
        this->die();
        n.set_strength(n.get_strength() * ratio);
    }
    else if (this->get_strength() == n.get_strength())
    {
        cout << "Mutual annihilation: " << this->get_name() << " and " << n.get_name()
            << " die at each other's arms.\n";
        this->die();
        n.die();
    }
}

class Protector
{
private:
    string name;
    unsigned strength;
    bool alive;
    Lord *lord;

public:
    Protector(const string &nm, unsigned stg) : name(nm), strength(stg) {}
    Lord* get_lord() { return lord; }
    void hire(Lord *l) { lord = l; }
    unsigned get_strength() { return strength; }
    void die()
    {
        strength = 0;
        alive = false;
    }
    virtual void battle_cry() const = 0;
};

class Noble_With_Strength : public Noble
{
private:
    string name;
    unsigned strength;
    bool alive;

public:
    Noble_With_Strength(const string &nm, unsigned stg) : Noble(), name(nm), strength(stg), alive(true) {}
    void battle(Noble &n) { Noble::battle(n); }
    string get_name() const { return name; }
    bool is_alive() { return alive; }
    unsigned get_strength() { return strength; }
    void set_strength(unsigned stg) { strength = stg; }
    void die()
    {
        strength = 0;
        alive = false;
    }
    void battle_cry() const { cout << ""; }
};

class Lord : public Noble
{
private:
    string name;
    unsigned strength;
    vector<Protector*> army;
    bool alive;

public:
    Lord(const string &nm) : Noble(), name(nm), alive(true), strength(0) {}
    void battle(Noble &n) { Noble::battle(n); }
    string get_name() const { return name; }
    unsigned get_strength() { return strength; }
    void set_strength(unsigned stg) { strength = stg; }
    bool is_alive() { return alive; }
    void hires(Protector &p)
    {
        if (alive) // check to see dead or alive
        {
            if (p.get_lord() == nullptr) // whether or not to hire
            {
                p.hire(this);
                army.push_back(&p);
                strength += p.get_strength();
            }
        }
    }
    void die()
    {
        for (size_t i = 0; i < army.size(); i++)
            army[i]->die();
        strength = 0;
        alive = false;
    }
    void battle_cry() const
    {
        for (size_t i = 0; i < army.size(); i++)
            army[i]->battle_cry();
    }
};

void Protector::battle_cry() const
{
    cout << name << " says: Take that in the name of my lord, " << lord->get_name() << ".\n";
}

class Wizard : public Protector
{
public:
    Wizard(const string &nm, unsigned stg) : Protector(nm, stg) {}
    void battle_cry() const { cout << "POOF!\n"; }
};

class Warrior : public Protector
{
public:
    Warrior(const string &nm, unsigned stg) : Protector(nm, stg) {}
    virtual void battle_cry() const = 0;
};

class Archer : public Warrior
{
public:
    Archer(const string &nm, unsigned stg) : Warrior(nm, stg) {}
    void battle_cry() const
    {
        cout << "TWANG! ";
        Protector::battle_cry();
    }
};

class Swordsman : public Warrior
{
public:
    Swordsman(const string &nm, unsigned stg) : Warrior(nm, stg) {}
    void battle_cry() const
    {
        cout << "CLANG! ";
        Protector::battle_cry();
    }
};


int main()
{
    Lord sam("Sam");
    Archer samantha("Samantha", 200);
    sam.hires(samantha);
    Lord joe("Joe");
    Noble_With_Strength randy("Randolf the Elder", 250);
    joe.battle(randy);
    joe.battle(sam);
    Lord janet("Janet");
    Swordsman hardy("TuckTuckTheHardy", 100);
    Swordsman stout("TuckTuckTheStout", 80);
    janet.hires(hardy);
    janet.hires(stout);
    Noble_With_Strength barclay("Barclay the Bold", 300);
    janet.battle(barclay);
    janet.hires(samantha);
    Archer pethora("Pethora", 50);
    Archer thora("Thorapleth", 60);
    Wizard merlin("Merlin", 150);
    janet.hires(pethora);
    janet.hires(thora);
    sam.hires(merlin);
    janet.battle(barclay);
    sam.battle(barclay);
    joe.battle(barclay);
}

