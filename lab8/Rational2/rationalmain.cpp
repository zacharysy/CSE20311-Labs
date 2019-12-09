// Zachary Sy
// simple driver to test the Rational class
#include <iostream>
using namespace std;
#include "rational.h"

int main()
{
  Rational a(5,6), b(3,7), c, s, d, m, k, z;

  cout << "Set the numerator and denominator value of c: ";
  cin >> c;
  
  cout << "*** display a and b ***\n";
  cout << a << endl;
  cout << b << endl;
  cout << "*** display c ***\n";
  cout << c << endl;  // recall that c was instantiated with the default constructor
  
  // 'mathematically' add a and b
  cout << "*** compute s as the math sum of a and b, and display s ***\n";
  s = a + b;
  cout << s << endl;
  
	// 'mathematically' subtract a and b
  cout << "*** compute d as the math difference of b and a, and display d ***\n";
  d = b-a;
  cout << d << endl;
  
  // 'mathematically' multiply a and b
  cout << "*** compute m as the math product of a and b, and display m ***\n";
  m = a*b;
  cout << m << endl;
  
    // 'mathematically' divide a and b
  cout << "*** compute k as the math divide of a and b, and display k ***\n";
  k = a/b;
  cout << k << endl;
  
	// change the denom of a to the numer of b
  cout << "*** sets the denominator of a to the numerator of b, and displays a  and b ***\n";
  a.setNumer(b.getNumer());
  cout << "a: ";
  cout << a << endl;
  cout << "b: ";
  cout << b << endl;
  
  return 0;
}

