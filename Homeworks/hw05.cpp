/*
Programmer: Jerry Wan
hw05.cpp

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Warrior
{
private:
	string name;
	
	unsigned strength;
	
	bool employed;

public:
	Warrior(const string &nm, unsigned stg) : 
	name(nm), strength(stg), employed(false) 
	{}

	void display() const { cout << name << ": " << strength << endl; }

	string getName() const { return name; }
	
	unsigned getStrength() const { return strength; }
	
	void setStrength(unsigned stg) { strength = stg; }
	
	void die() { strength = 0; }
	
	void employ() { employed = true; }
	
	void fire() { employed = false; }
	
	bool isHired() { return employed; }
};

class Noble
{
private:
	string name;
	
	vector <Warrior*> warriors;
	
	bool alive = true;

public:
	Noble(const string &nm) : 
	name(nm) 
	{}
	void display() const
	{
		if (warriors.size() == 0)
			cout << name << "'s army is empty :-(\n";
		else
		{
			cout << name << " has an army of " << warriors.size() << endl;
			for (size_t i = 0; i < warriors.size(); i++)
			{
				cout << "\t";
				warriors[i]->display();
			}
		}
	}

	void hire(Warrior &w)
	{
		w.employ();
		warriors.push_back(&w);
	}

	void fire(Warrior &w)
	{
		int n;
		for (size_t i = 0; i < warriors.size(); i++)
		{
			if (w.getName() == warriors[i]->getName())
				n = i;
		}
		if (!n)
			cout << "Warrior doesn't exist\n";
		else
		{
			cout << w.getName() << ", you're fired! - " << name << endl;
			warriors[n]->fire();
			warriors.erase(warriors.begin() + n);
		}
	}

	vector<Warrior*> get_warriors() { return warriors; }

	bool isAlive() { return alive; }

	string getName() const { return name; }

	void setAlive(bool alv) { alive = alv; }

	void battle(Noble &n)
	{
		cout << name << " battles " << n.getName() << endl;
		if (alive && n.isAlive())
		{
			int cum_stg_1 = 0, cum_stg_2 = 0;
			double ratio;
			for (size_t i = 0; i < warriors.size(); i++)
				cum_stg_1 += warriors[i]->getStrength();
			for (size_t i = 0; i < n.get_warriors().size(); i++)
				cum_stg_2 += n.get_warriors()[i]->getStrength();
			if (cum_stg_1 > cum_stg_2)
			{
				ratio = (double)cum_stg_2 / (double)cum_stg_1;
				for (size_t i = 0; i < warriors.size(); i++)
				{
					int a = warriors[i]->getStrength() - (warriors[i]->getStrength() * ratio);
					warriors[i]->setStrength(a);
				}
				for (size_t i = 0; i < n.get_warriors().size(); i++)
					n.get_warriors()[i]->die();
				n.setAlive(false);
				cout << name << " defeats " << n.getName() << endl;
			}
			else if (cum_stg_2 > cum_stg_1)
			{
				ratio = (double)cum_stg_1 / (double)cum_stg_2;
				for (size_t i = 0; i < n.get_warriors().size(); i++)
				{
					int a = n.get_warriors()[i]->getStrength() - (n.get_warriors()[i]->getStrength() * ratio);
					n.get_warriors()[i]->setStrength(a);
				}
				for (size_t i = 0; i < warriors.size(); i++)
					warriors[i]->die();
				alive = false;
				cout << n.getName() << " defeats " << name << endl;
			}
			else if (cum_stg_1 == cum_stg_2)
			{
				for (size_t i = 0; i < warriors.size(); i++)
					warriors[i]->die();
				for (size_t i = 0; i < n.get_warriors().size(); i++)
					n.get_warriors()[i]->die();
				n.setAlive(false);
				alive = false;
				cout << "Mutual Annihilation: " << name << " and " << n.getName()
					<< " die at each other's hands\n";
			}
		}
		else if (!alive && !n.isAlive())
			cout << "Oh, NO! They're both dead! Yuck!\n";
		else if (!alive || !n.isAlive())
			cout << "One of the participants is already dead. They're beating a dead noble.\n";
	}
};

int main()
{
	vector<Noble*> nobles;
	vector<Warrior*> warriors;
	ifstream ifs("noblewarriors.txt");
	string cmd;
	if (!ifs)
	{
		cerr << "Could not open file!" << endl;
		exit(1);
	}
	while (ifs >> cmd)
	{
		if (cmd == "Noble")
		{
			string nm;
			ifs >> nm;
			bool exists = false;
			for (size_t i = 0; i < nobles.size(); i++)
			{
				if (nobles[i]->getName() == nm)
				{
					exists = true;
					cout << "Noble \"" << nm << "\" already exists\n";
				}
			}
			if (!exists)
			{
				Noble *n = new Noble(nm);
				nobles.push_back(n);
			}

		}
		else if (cmd == "Warrior")
		{
			string nm;
			int stg;
			ifs >> nm >> stg;
			bool exists = false;
			for (size_t i = 0; i < warriors.size(); i++)
			{
				if (warriors[i]->getName() == nm)
				{
					exists = true;
					cout << "Warrior \"" << nm << "\" already exists\n";
				}
			}
			if (!exists)
			{
				Warrior *w = new Warrior(nm, stg);
				warriors.push_back(w);
			}
		}
		else if (cmd == "Hire")
		{
			string n, w;
			ifs >> n >> w;
			int idxn, idxw;
			bool nexist = false, wexist = false;
			for (size_t i = 0; i < nobles.size(); i++)
			{
				if (nobles[i]->getName() == n)
				{
					idxn = i;
					nexist = true;
				}
			}
			for (size_t i = 0; i < warriors.size(); i++)
			{
				if (warriors[i]->getName() == w)
				{
					idxw = i;
					wexist = true;
				}
			}
			if (!nexist)
				cout << "Error: Noble does not exist\n";
			else if (!wexist)
				cout << "Error: Warrior does not exist\n";
			else
				nobles[idxn]->hire(*warriors[idxw]);
		}
		else if (cmd == "Fire")
		{
			string n, w;
			ifs >> n >> w;
			int idxn, idxw;
			for (size_t i = 0; i < nobles.size(); i++)
			{
				if (nobles[i]->getName() == n)
					idxn = i;
			}
			for (size_t i = 0; i < warriors.size(); i++)
			{
				if (warriors[i]->getName() == w)
					idxw = i;
			}
			nobles[idxn]->fire(*warriors[idxw]);
		}
		else if (cmd == "Status")
		{
			cout << "Status\n======\nNobles:\n";
			for (size_t i = 0; i < nobles.size(); i++)
				nobles[i]->display();
			if (nobles.size() == 0)
				cout << "NONE\n";
			cout << "Unemployed Warriors:\n";
			bool exists = false;
			for (size_t i = 0; i < warriors.size(); i++)
			{
				if (!warriors[i]->isHired())
				{
					exists = true;
					warriors[i]->display();
				}
			}
			if (!exists)
				cout << "NONE\n";
		}
		else if (cmd == "Battle")
		{
			string n1, n2;
			ifs >> n1 >> n2;
			int idx1, idx2;
			for (size_t i = 0; i < nobles.size(); i++)
			{
				if (n1 == nobles[i]->getName())
					idx1 = i;
				else if (n2 == nobles[i]->getName())
					idx2 = i;
			}
			nobles[idx1]->battle(*nobles[idx2]);
		}
		else if (cmd == "Clear")
		{
			for (size_t i = 0; i < nobles.size(); i++)
			{
				nobles[i] = nullptr;
				delete nobles[i];
			}
			nobles.clear();
			for (size_t i = 0; i < warriors.size(); i++)
			{
				warriors[i] = nullptr;
				delete warriors[i];
			}
			warriors.clear();
		}
	}
}

