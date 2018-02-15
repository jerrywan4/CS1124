/*
Programmer: Jerry Wan
hw01.cpp
*/

#include <string>
#include <fstream>
#include <iostream>
#include <vector> 

using namespace std;

char decryptCharacter(char originalLetter, int amount);

void decryptString(vector<string>& encryptedMessage, int amount);

void displayEncryptedLF(ifs, vector<string>& messageFL, vector<string>& lfMessage); 

int main()
{
	ifstream ifs("encrypted.txt");
	int numberChange;
	string 


}

char decryptCharacter(char originalLetter, int amount)
{
	if (originalLetter < 123 && originalLetter > 96) 
	{
		char newLetter = originalLetter - amount; 
		if (newLetter < 96) 
		{
			newLetter += (123 - 97); 
		}
		return newLetter;
	}
	return originalLetter;
}
void decryptString(vector<string>& encryptedMessage, int amount)
{
	char newChar;
	for (size_t i = 0; i < encryptedMessage.size(); ++i)
	{
		for (size_t j = 0; j	< encryptedMessage[i].size(); ++j)
		{
			newChar = decryptCharacter(encryptedMessage[i][j], amount);
			encryptedMessage[i][j] = newChar;
		}
	}
}