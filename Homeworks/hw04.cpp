/*
hw04.cpp
Programmer: Jerry Wan
We will model a game of medieval times. Our world is filled with nobles and warriors. 
Nobles don't have much to do except do battle with each other. 
Warriors don't have much to do except hire out to a noble and fight in his behalf. 
Of course the nobles are pretty wimpy themselves and will lose if they don't have warriors to defend them.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//Warrior class
class Warrior {
public:
	Warrior (const string& aName, double strength) : 
	wName(aName), strength(strength) 
	{}

	string getwName() const {
		return wName;
	}

	double getStr() const {
		return strength;
	}

	void setStr(double ratio) {
		strength = strength*ratio;
	}

private:
	string wName;
	double strength;
};

//Noble class
class Noble {
public:
	Noble (const string& aName) : 
	nName(aName) 
	{}

	double getArmyStr() const {
		double totalStrength = 0; 
		for (size_t i = 0; i  < army.size(); i++) {
			totalStrength += army[i]->getStr();
		}
		return totalStrength;
	}

	void setArmyStr(double ratio) {
		for (size_t i = 0; i  < army.size(); i++) {
			army[i]->setStr(ratio);
		}
	}

	string getNName() const {
		return nName;
	}

	void hire(Warrior& aWarrior) {
		army.push_back(&aWarrior);
	}

	void display() const {
		cout << nName << " has an army of " << army.size() <<endl;
		for (size_t i = 0; i < army.size(); i++) { 
			cout << "        " << army[i]->getwName() << ": " << army[i]->getStr() << endl;
		}
	}

	void fire(const Warrior& aWarrior) {
		cout << aWarrior.getwName() << ", you are fired! -- " << nName << endl;
		for (size_t i = 0; i < army.size(); i++) {
			if (army[i]->getwName() == aWarrior.getwName()) {
				while (i+1 < army.size()) {
					army[i] = army[i+1];
					i++;
				}
				army.pop_back();
			}
		}
	}

	void battle (Noble& opponent) {
		cout << nName << " battles " << opponent.getNName() << endl;
		if (this->getArmyStr() == 0 && opponent.getArmyStr() == 0) {
			cout << "Oh, NO! They're both dead! Yuck!" << endl;		
		} 
		else if (this->getArmyStr() != 0 && opponent.getArmyStr() != 0) {
			if (this->getArmyStr() > opponent.getArmyStr()) {
				this->setArmyStr(opponent.getArmyStr()/this->getArmyStr());
				opponent.setArmyStr(0);
				cout << nName << " defeats " << opponent.getNName() << endl;
			} else if (this->getArmyStr() < opponent.getArmyStr()) { 
				this->setArmyStr(this->getArmyStr()/opponent.getArmyStr());
				opponent.setArmyStr(0);				
				cout << opponent.getNName() << " defeats " << nName << endl;
			} else {
				this->setArmyStr(0);
				opponent.setArmyStr(0);
				cout << "Mutual Annihilation: " << nName << " and " << opponent.getNName() << " die at each other's hands" << endl;
			}
		} 
		else {
			if (this->getArmyStr() == 0) {
				cout << "He's dead, " << opponent.getNName() << endl;
			} 
			else {
				cout << "He's dead, " << nName << endl;
			}
		}
 	}

private:
	string nName;
	vector<Warrior*> army;
};

int main() {
	Noble art("King Arthur");
	Noble lance("Lancelot du Lac");
	Noble jim("Jim");
	Noble linus("Linus Torvalds");
	Noble billie("Bill Gates");

	Warrior cheetah("Tarzan", 10);
	Warrior wizard("Merlin", 15);
	Warrior theGovernator("Conan", 12);
	Warrior nimoy("Spock", 15);
	Warrior lawless("Xena", 20);
	Warrior mrGreen("Hulk", 8);
	Warrior dylan("Hercules", 3);

	jim.hire(nimoy);
	lance.hire(theGovernator);
	art.hire(wizard);
	lance.hire(dylan);
	linus.hire(lawless);
	billie.hire(mrGreen);
	art.hire(cheetah);

	jim.display();
	lance.display();
	art.display();
	linus.display();
	billie.display();

	art.fire(cheetah);
	art.display();

	art.battle(lance);
	jim.battle(lance);
	linus.battle(billie);
	billie.battle(lance);
	
	return 0;
}