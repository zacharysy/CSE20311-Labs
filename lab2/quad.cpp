// Zachary Sy
// computes the roots of a quadratic equation
#include <iostream>
using namespace std;
#include <cmath>

int main(){
	double a, b, c, disc;
	double x1, x2;

	cout << "Enter the coefficients (a,b,c) of a quadratic equation: ";
	cin >> a >> b >> c;
	
  // ... rest of program goes here
    cout << "root 1: " << (-b+sqrt(pow(b,2)-(4*a*c)))/(2*a) << endl;
    cout << "root 2: " << (-b-sqrt(pow(b,2)-(4*a*c)))/(2*a) << endl;
  

  return 0;
}
