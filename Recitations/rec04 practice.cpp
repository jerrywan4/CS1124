/*
Programmer: Jerry Wan
rec04 practice
*/

#include <iostream>
#include <string>

using namespace std;


int main(){
	int x;  
	x = 10;  
	cout << "x = " << x << endl;
	int* p;  
	p = &x;  
	cout << "p = " << p << endl;
	*p = -2763;  
	cout << "p points to where " << *p << " is stored\n";  
	cout << "*p now contains " << *p << endl;  
	cout << "x now contains " << x << endl;
	int y(13);      
	cout << "y contains " << y << endl;      
	p = &y;      
	cout << "p now points to where " << *p << " is stored\n";      
	cout << "*p now contains " << *p << endl;      
	*p = 980;      
	cout << "p points to where " << *p << " is stored\n";      
	cout << "*p now contains " << *p << endl;      
	cout << "y now contains " << y << endl;
	int* q;      
	q = p;      
	cout << "q points to where " << *q << " is stored\n";      
	cout << "*q contains " << *q << endl;
	double d(33.44);      
	double* pD(&d);      
	*pD = *p;      
	*pD = 73.2343;      
	*p  = *pD;      
	*q  = *p;      
	//pD  = p;
	//p   = pD;
	int joe( 24 );  
	const int sal( 19 );    
	int*  pI;  
	pI = &joe;  
	*pI = 234;  //changes value of joe
	//pI = &sal;  
	*pI = 7623;    
	const int *pcI;
	pcI = &joe;  
	//*pcI = 234;  //cannot change the VALUE of what a pointer to a const int is, but you can change what the pointer is pointing at
	pcI = &sal;  //assigns pcI to point at Sal
	//*pcI = 7623; //cannot change value, only what it is pointing at    

	//int* const cpI;
	int* const cpI(&joe);
	//int* const cpI(&sal); //cannot define twice
	//  cpI = &joe;  //address cannot be changed, only value
	*cpI = 234;  
	//  cpI = &sal;  
	*cpI = 7623;    

	//const int* const cpcI;
	cout << joe << endl;
	const int* const cpcI(&joe);
	cout << *cpcI << endl;
	joe = 25;
	cout << *cpcI << endl;
	//const int* const cpcI(&sal); //cannot define twice
	//  cpcI = &joe;  
	// *cpcI = 234;  
	//  cpcI = &sal;  
	// *cpcI = 7623; 
}