// Zachary Sy
// Rational Class

#include <iostream>
#include <cmath>
#include "rational.h"

using namespace std;

// Default to 1
Rational::Rational(){
	numer = 1;
	denom = 1;
}


Rational::Rational(int a, int b){
	numer = a;
	denom = b;
}

Rational::~Rational(void){
}


int Rational::getNumer(){
	return numer;
}

int Rational::getDenom(){
	return denom;
}

void Rational::setNumer(int a){
	numer = a;
}

void Rational::setDenom(int b){
	denom = b;
}

void Rational::print(){
	cout << numer << "/" << denom << endl;
}

Rational Rational::add(Rational ratio){
	int newNumer = (numer * ratio.denom) + (ratio.numer * denom);
	int newDenom = denom*ratio.denom;
	
	// Assume I don't have to reduce to lowest fraction
	return Rational(newNumer,newDenom);	
}

Rational Rational::subtract(Rational ratio){
	int newNumer = (numer * ratio.denom) - (ratio.numer * denom);
	int newDenom = denom*ratio.denom;
	
	return Rational(newNumer,newDenom);	
}

Rational Rational::multiply(Rational ratio){
	return Rational(numer * ratio.numer, denom * ratio.denom);
}

Rational Rational::divide(Rational ratio){
	return Rational(numer * ratio.denom, denom * ratio.numer);
}

