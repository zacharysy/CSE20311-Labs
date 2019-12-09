// Zachary Sy
// Football Score Formula

#include <iostream>
using namespace std;

int main(){
    int td; // touchdowns
    int ep; // extra points
    int fg; // field goals
    int sf; // safeties

    cout << "Number of Touchdowns: ";
    cin >> td;

    cout << "Number of Extra Points: ";
    cin >> ep;

    cout << "Number of Field Goals: ";
    cin >> fg;

    cout << "Number of Safeties: ";
    cin >> sf;

    cout << "\nTotal Points: " << (6*td+ep+3*fg+2*sf) << endl;
}
