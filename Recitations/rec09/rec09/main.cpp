/*
Jerry Wan
Rec 9*/

#include <iostream>
#include <string>
#include "Directory.h"

using namespace std;
using namespace emp;



int main()
{
    Position boss("Boss", 3141.59);
    Position pointy_hair("Pointy Hair", 271.83);
    Position techie("Techie", 14142.13);
    Position peon("Peonissimo", 34.79);


    Directory d;
    d.add("Marilyn", 123, 4567, boss);
    cout << d << endl;

    Directory d2(d); // what function is being used??
    d2.add("Gallagher", 111, 2222, techie);
    d2.add("Carmack", 314, 1592, techie);
    cout << d2 << endl;

    Directory d3;
    d3 = d2;

    cout << "cout << d3\n";
    cout << d3;
    cout << "cout << d3[\"Gallagher\"]\n";
    cout << d3["Gallagher"];
}

