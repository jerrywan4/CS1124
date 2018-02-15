/*
Programmer: Jerry Wan
rec01.cpp
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void openFile(ifstream&);

void displayLines(ifstream& ifs, string line, int lineCounter);

void displayWords(ifstream& ifs, string word, int wordCounter);

void displayChars(ifstream& ifs, char oneChar, int charCounter);

int main(){
	ifstream ifs("jabberwocky.txt");
	if (!ifs){
		cerr << "Error code 489! Could not open file!" <<endl;
		exit(489);
	}
	string line, word;
	char oneChar;
	int lineCounter = 0, wordCounter = 0, charCounter = 0;
	displayLines(ifs, line, lineCounter);
	ifs.close();
	ifs.open("jabberwocky.txt");
	displayWords(ifs, word, wordCounter);
	ifs.close();
	ifs.open("jabberwocky.txt");
	displayChars(ifs, oneChar, charCounter);
}

void displayLines(ifstream& ifs, string line, int lineCounter){
	while (getline(ifs,line)){
		cout << line << endl;
		lineCounter++;
	}
	cout << "Number of lines: " << lineCounter << endl; 
}

void displayWords(ifstream& ifs, string word, int wordCounter){
	while (ifs >> word){
		wordCounter++;
	}
	cout << "Number of words: " << wordCounter << endl;
}

void displayChars(ifstream& ifs, char oneChar, int charCounter){
	ifs >> noskipws;
	while (ifs >> oneChar){
		charCounter++;
	}
	cout << "Number of characters: " << charCounter << endl;
}
