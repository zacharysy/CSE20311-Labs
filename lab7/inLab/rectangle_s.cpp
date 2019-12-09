// rectangle_s.cpp
#include <iostream>
using namespace std;

struct Rectangle {
  float length;
  float width;
};

float find_perim(Rectangle);
float find_area(Rectangle);
void display(float, float);

int main()
{
  Rectangle rect;

  cout << "enter the rectangle's length and width: ";
  cin >> rect.length >> rect.width;

  float perim = find_perim(rect);
  float area = find_area(rect);

  display(perim, area);

  return 0;
}

float find_perim(Rectangle rect){
  return 2.0*(rect.length + rect.width);
}

float find_area(Rectangle rect){
  return rect.length * rect.width;
}

void display(float p, float a)
{
  cout << "the perimeter is: " << p << endl;
  cout << "the area is: " << a << endl;
}

