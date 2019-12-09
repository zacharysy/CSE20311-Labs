#include <iostream>
#include <cmath>
#include "operfn.h"
using namespace std;

int main(){
  float x, y;

  cout << "enter two non-zero numbers: ";
  cin >> x >> y;

  cout << "their sum is " << add(x,y) << endl;
  cout << "their difference is " << fabs(subtract(x,y)) << endl;
  cout << "their product is " << multiply(x,y) << endl;

  return 0;
}