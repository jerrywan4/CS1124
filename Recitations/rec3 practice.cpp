#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sandwich{
	int bread;
	int cheese;
	int tomatoes;
	double mayo;
	double mustard;
public:
	Sandwich(const int sliceBread = 2, int sliceCheese = 1, int slicetomato = 2, double someMayo = 1.0, double someMustard = 0.05)
	: bread(sliceBread), cheese(sliceCheese), tomatoes(slicetomato), mayo(someMayo), mustard(someMustard) {}

	void display() const{
		cout << "Bread: 2" << " Cheese: " << cheese << " Tomatoes: " << tomatoes << " Mayo: " << mayo << " Mustard: " << mustard << endl;
	}

	int getCheese(){return cheese;}

	int getTomatoes(){return tomatoes;}

	double getMayo(){return mayo;}

	double getMustard(){return mustard;}

	void setCheese(int newCheese){cheese = newCheese;}

	void setTomatoes(int newTomatoes){tomatoes = newTomatoes;}

	void setMayo(double newMayo){mayo = newMayo;}

	void setMustard(double newMustard){mustard = newMustard;}

};

class SandwichTruck{
	vector<Sandwich> sandwiches;
public:
	void insertSandwich(const Sandwich& aSandwich){
		sandwiches.push_back(aSandwich);
	}

	void checkBeforeLeaving(){
		for(const Sandwich& aSandwich : sandwiches){
			aSandwich.display();
		}
	}
};

int main(){
	SandwichTruck misterTruck;
	Sandwich s1;
	Sandwich s2;
	s2.setMustard(0);
	Sandwich s3(2);
	Sandwich s4;
	misterTruck.insertSandwich(s1);
	misterTruck.insertSandwich(s2);
	misterTruck.insertSandwich(s3);
	misterTruck.insertSandwich(s4);
	misterTruck.checkBeforeLeaving();
	cout << s2.getMustard() << endl;
}