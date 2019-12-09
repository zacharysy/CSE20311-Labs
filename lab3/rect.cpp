#include <iostream>
#include <iomanip>
using namespace std;

// function prototypes go here ...
float find_perim(float, float);
float find_area(float, float);
void display(float, float);

int main()
{
  float len, wid;
  float perim, area;

  cout << "enter the length: ";
  cin >> len;
  cout << "enter the width: ";
  cin >> wid;

  perim = find_perim(len, wid);  // call the find_perim function
  area = find_area(len, wid);    // call the find_area function

  display(perim, area);          // call the display function

  return 0;
}

// function definitions go here ...

float find_perim(float len, float wid){
	return 2*len+2*wid;
}

float find_area(float len, float wid){
	return len*wid;
}

void display(float perim, float area){
	cout << setw(11) << "Perimeter: " << setw(2) << perim << endl;
	cout << setw(11) << "Area: " << setw(2) << area << endl;
}