/*
 Jerry Wan
 */

#include "Rational.h"

namespace CS1124 {
    
    Rational::Rational(){}
    Rational::Rational( int num ) : numerator(num), denominator( 1 ) {}
    
    void Rational::setNumber( int& aNumerator, int& aDenominator ){
        numerator = aNumerator;
        denominator = aDenominator;
    }
    
    int Rational::getNumerator(){
        return numerator;
    }
    
    int Rational::getDenominator(){
        return denominator;
    }
    
    
    ostream& operator<<(ostream& os, Rational& number){
        cout << number.getNumerator() << "/" << number.getDenominator() << endl;
        return os;
    }
    
    istream& operator>>(istream& is, Rational& number){
        int anumerator, adenominator;
        char slash;
        is >> anumerator >> slash >> adenominator;
        number.setNumber(anumerator, adenominator);
        return is;
    }
    
    
    Rational& Rational::operator+=( Rational& r1 ){
        numerator = numerator + r1.numerator;
        denominator = denominator + r1.denominator;
        return *this;
    }
    
    Rational operator+( Rational& r1, Rational& r2 ){
        Rational final;
        int num = r1.getNumerator() + r2.getNumerator();
        int denom = r1.getDenominator() + r2.getDenominator();
        final.setNumber(num, denom);
        return final;
    }
    
    //Pre increment and Decrement
    
    Rational& Rational::operator++ () {
        numerator = numerator + denominator;
        return *this;
    }
    
    Rational& Rational::operator--() {
        numerator = numerator - denominator;
        return *this;
    }
    
    //Post increment and Decrement
    
    Rational Rational::operator++ (int) {
        Rational temp(*this);
        ++(*this);
        return temp;
    }
    
    Rational Rational::operator--(int) {
        Rational temp(*this);
        numerator = numerator - denominator;
        return temp;
    }
    
    
    int greatestCommonDivisor(int x, int y) {
        while (y != 0) {
            int temp = x % y;
            x = y;
            y = temp;
        }
        return x;
    }
    
    bool operator==( Rational& r1, Rational& r2 ){
        int val1 = greatestCommonDivisor(r1.getNumerator(), r1.getDenominator());
        int val2 = greatestCommonDivisor(r2.getNumerator(), r2.getDenominator());
        return val1 == val2;
    }
    
    bool operator!=( Rational& r1, Rational& r2 ){
        int val1 = greatestCommonDivisor(r1.getNumerator(), r1.getDenominator());
        int val2 = greatestCommonDivisor(r2.getNumerator(), r2.getDenominator());
        return val1 != val2;
    }
    
}
