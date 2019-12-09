// Zachary Sy
// Circle Class

#include <iostream>
#include <math.h>
#include "circle.h"
using namespace std;

// If no Radius is given, I just set it to 0
Circle::Circle(void){
	radius = 0;
}

Circle::Circle(float rad){
	radius = rad;
}

// Deconstruct
Circle::~Circle(void){
}


float Circle::getRadius(){
	return radius;
}

void Circle::setRadius(float rad){
	radius = rad;
}

float Circle::circumference(void){
	return M_PI * 2 * radius;
}

float Circle::area(void){
	return M_PI * pow(radius,2);
}

void Circle::info(void){
	cout << "  radius: " << radius << endl;
	cout << "  circumference: " << circumference() << endl;
	cout << "  area: " << area() << endl;
}



