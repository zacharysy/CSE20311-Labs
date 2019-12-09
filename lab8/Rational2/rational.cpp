// Zachary Sy
// Rational Class

#include <iostream>
#include <cmath>
#include <algorithm>
#include "rational.h"

using namespace std;

// Constructors & Destructors
Rational::Rational(){
	// Default to 1
	setRational(1,1);
}


Rational::Rational(int a, int b){
	setRational(a,b);
}

Rational::~Rational(void){
}


// Getters and Setters
int Rational::getNumer(){
	return numer;
}

int Rational::getDenom(){
	return denom;
}

void Rational::setNumer(int a){
	numer = a;
	reduce();
}

void Rational::setDenom(int b){
	denom = b;
	reduce();
}

void Rational::setRational(int numer, int denom){
	(*this).numer = numer;
	(*this).denom = denom;
	
	reduce();
}

// Reduce
void Rational::reduce(){
	int common = __gcd(numer,denom);
	
	numer /= common;
	denom /= common;

	// Fix signs
	if(denom < 0){
		numer *= -1;
		denom *= -1;
	}
}

// Operator Overloads
Rational Rational::operator+(Rational ratio){
	int newNumer = (numer * ratio.denom) + (ratio.numer * denom);
	int newDenom = denom*ratio.denom;	
	
	return Rational(newNumer,newDenom);	
}

Rational Rational::operator-(Rational ratio){
	int newNumer = (numer * ratio.denom) - (ratio.numer * denom);
	int newDenom = denom*ratio.denom;

	return Rational(newNumer,newDenom);	
}

Rational Rational::operator*(Rational ratio){
	return Rational(numer * ratio.numer, denom * ratio.denom);
}

Rational Rational::operator/(Rational ratio){
	return Rational(numer * ratio.denom, denom * ratio.numer);
}


ostream& operator<<(ostream& os, const Rational& ratio){
	os << ratio.numer << "/" << ratio.denom;
	return os;
}

istream& operator>>(istream& stream, Rational& ratio){
	stream >> ratio.numer >> ratio.denom;
	ratio.reduce();
	
	return stream;
}
