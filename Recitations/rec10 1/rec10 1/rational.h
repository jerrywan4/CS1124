/*
 Jerry Wan
 */

#ifndef __rec10__Rational__
#define __rec10__Rational__
#include <iostream>

using namespace std;
namespace CS1124 {
    
    class Rational{
    public:
        Rational();
        Rational(int num);
        void setNumber( int& anumerator, int& adenominator );
        int getNumerator();
        int getDenominator();
        friend ostream& operator<<( ostream& os, Rational& number );
        friend istream& operator>>( istream& is, Rational& number );
        Rational& operator+=( Rational& r1 );
        
        Rational& operator++();
        Rational operator++(int);
        Rational& operator--();
        Rational operator--(int);
    private:
        int numerator;
        int denominator;
    };
    Rational operator+( Rational& r1, Rational& r2 );
    int greatestCommonDivisor( int& anumerator, int& adenominator );
    bool operator==( Rational r1, Rational r2 );
    bool operator!=( Rational r1, Rational r2 );
}


#endif /* defined(__rec10__Rational__) */
