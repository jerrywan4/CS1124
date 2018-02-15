/*
hw03.cpp
Programmer: Jerry Wan
We will expand our Warrior a little. Each Warrior will have a weapon. He is "born" with it, i.e. the weapon is created together with the warrior. 
It can only be accessed by him. It provides him with his strength. 
In battle, weapons lose their edge and weaken. When a Warrior's weapon loses all of its strength, the Warrior himself dies.
*/

#include <iostream>
#include <fstream> 
#include <string> 
#include <vector>

using namespace std;

//Define Weapon class, which is called in Warrior
class Weapon {
public: 
	Weapon(const string& weaponName, int aStrength) : name(weaponName), strength(aStrength) {}

	//Getters
	int getStrength() const {
		return strength;
	}
	string getWeaponName() const {
		return name; 
	}

	//Setters
	void setStrength(int newStrength) {
		strength = newStrength;
	}

private: 
	string name;
	int strength; 
};


//Define Warrior class
class Warrior {
public:
	Warrior(const string& warriorName, Weapon& aWeapon) : name(warriorName), weapon(aWeapon) {} 

	//Getters
	string getWarriorName() const {
		return name;
	}
	string getWeaponName() const {
		return weapon.getWeaponName(); //delegate getWeaponName to class Weapon
	}
	int getStrength() const {
		return weapon.getStrength(); //delegate getStrength to class Weapon
	}

	//Setters
	void setStrength(int newStrength) {
		weapon.setStrength(newStrength);
	}

	//Battle method
	void battle(Warrior& anotherWarrior) { 
		//if both are already dead
		if (weapon.getStrength() == 0 && anotherWarrior.getStrength() == 0) {
			cout << "Oh, NO! They're both dead! Yuck!" << endl;		
		} 
		//if none is dead
		else if (weapon.getStrength() != 0 && anotherWarrior.getStrength() != 0) {
			if (weapon.getStrength() > anotherWarrior.getStrength()) {
				//updates the strength after the battle & print out result
				weapon.setStrength(weapon.getStrength()-anotherWarrior.getStrength());
				anotherWarrior.setStrength(0);
				cout << name << " defeats " << anotherWarrior.getWarriorName() << endl;
			} else if (weapon.getStrength() < anotherWarrior.getStrength()) {
				//updates the strength after the battle & print out result
				anotherWarrior.setStrength(anotherWarrior.getStrength()-weapon.getStrength());
				weapon.setStrength(0);
				cout << anotherWarrior.getWarriorName() << " defeats " << name << endl;
			} else { // if both are of equal strength
				//updates the strength after the battle & print out result
				weapon.setStrength(0);
				anotherWarrior.setStrength(0);
				cout << "Mutual Annihilation: " << name << " and " << anotherWarrior.getWarriorName() << " die at each other's hands" << endl;
			}
		} 
		//if either is already dead
		else {
			if (weapon.getStrength() == 0) {
				cout << "He's dead, " << anotherWarrior.getWarriorName() << endl;
			} 
			else {
				cout << "He's dead, " << name << endl;
			}
		}
	}

private:
	string name;
	Weapon weapon;
};

//Function prototypes
void createWarrior(ifstream& gameStream, vector<Warrior>& warriors);
void getStatus(const vector<Warrior>& warriors);

//main
int main() {
	//open the file and check for errors
	ifstream gameStream;
	gameStream.open("warriors.txt");
	if (!gameStream) {
		cerr << "Could not open file!" << endl;
		exit(1);
	}

	string command;
	vector<Warrior> warriors; 
	//reading the commands
	while (gameStream >> command) {
		if (command == "Warrior") {
			createWarrior(gameStream, warriors);
		}
		else if (command == "Status") {
			cout << "==========" << endl;
			getStatus(warriors);
		}
		else if (command == "Battle") {	
			cout << "==========" << endl;
			//read the warriors involved in the battle & print out 
			string firstWarrior; 
			string secondWarrior;
			gameStream >> firstWarrior;
			gameStream >> secondWarrior; 
			cout << firstWarrior << " battles " << secondWarrior << endl;
			//find the index of the specified warrior
			int firstWarriorIndex, secondWarriorIndex;
			for (size_t i = 0; i < warriors.size(); i++) {
				if (warriors[i].getWarriorName() == firstWarrior) {
					firstWarriorIndex = i; 
				} 
				if (warriors[i].getWarriorName() == secondWarrior) {
					secondWarriorIndex = i;
				}
			}
			//invoke battle method
			warriors[firstWarriorIndex].battle(warriors[secondWarriorIndex]);
		}
	}
	
	gameStream.close();
	return 0; 
}

//create new warrior
void createWarrior(ifstream& gameStream, vector<Warrior>& warriors) {
	string warriorName; 
	string weaponName;
	int strength;
	//read the warrior's name, weapon's name, and strength
	gameStream >> warriorName;  
	gameStream >> weaponName;  
	gameStream >> strength;
	Weapon newWeapon(weaponName, strength); //initialize a new weapon
	Warrior newWarrior(warriorName, newWeapon); //initialize a warrior with the new weapon just created
	warriors.push_back(newWarrior);
}

//display the status of the warriors
void getStatus(const vector<Warrior>& warriors) {
	cout << "There are: " << warriors.size() << " warriors" << endl;
	for (size_t i = 0; i < warriors.size(); i++) {
		cout << "Warrior: " << warriors[i].getWarriorName() << ", weapon: " << warriors[i].getWeaponName() 
			<< ", " << warriors[i].getStrength() << endl;
	}
}