// Zachary Sy
// simple driver to test the Rational class
#include <iostream>
using namespace std;
#include "rational.h"

int main()
{
  Rational a(5,6), b(3,7), c, s, d, m, k, z;

  cout << "*** display a and b ***\n";
  a.print();
  b.print();
  cout << "*** display c ***\n";
  c.print();  // recall that c was instantiated with the default constructor

  // 'mathematically' add a and b
  cout << "*** compute s as the math sum of a and b, and display s ***\n";
  s = a.add(b);
  s.print();
  
	// 'mathematically' subtract a and b
  cout << "*** compute d as the math difference of a and b, and display d ***\n";
  d = a.subtract(b);
  d.print();
  
  // 'mathematically' multiply a and b
  cout << "*** compute m as the math product of a and b, and display m ***\n";
  m = a.multiply(b);
  m.print();
  
    // 'mathematically' divide a and b
  cout << "*** compute k as the math divide of a and b, and display k ***\n";
  k = a.divide(b);
  k.print();
  
	// change the denom of a to the numer of b
  cout << "*** sets the denominator of a to the numerator of b, and displays a  and b ***\n";
  a.setNumer(b.getNumer());
  cout << "a: ";
  a.print();
  cout << "b: ";
  b.print();
  
  return 0;
}

