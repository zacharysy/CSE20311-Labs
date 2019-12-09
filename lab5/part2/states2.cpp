// Zachary Sy
// Strings 2


#include <iostream>
using namespace std;
#include <string>
#include <vector>
 
int main() 
{
  string line1;
  string line2 = "notre dame fighting irish";
  vector<string> states = {"Indiana", "Michigan", "Ohio", "Illinois", "Iowa"};

  cout << "enter a line: ";
  getline(cin,line1);  

  cout << "the first line is: " << line1 << endl;
  cout << "the second line is: " << line2 << endl;

  // display the states; recall that states[i] is a C string (array of char)
  cout << "the states are:" << endl;
  for (auto i = states.begin(); i < states.end(); i++)
    cout << " - " << *i << endl;

  // since we need to access each character here, we need nested for loops
  cout << "displaying the states with a space between letters:" << endl;
  for (auto i = states.begin(); i < states.end(); i++) {
    cout << " - ";
    for (auto j = (*i).begin(); j < (*i).end(); j++)
      cout << *j << " ";
    cout << endl;
  }

  return 0;
}