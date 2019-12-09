// Zachary Sy
// Multiplication Table

#include <iostream>
using namespace std;
#include <cmath>
#include <iomanip>

int main(){
	int sizeX;
	int sizeY;
	
	cout << "X: ";
	cin >> sizeX;	
    cout << "Y: ";
	cin >> sizeY;	

	for(int y=0; y <= sizeY; y++){
		for(int x=0; x <= sizeX; x++){
			if(x == 0 && y == 0){
				cout << setw(4) << "*" << setw(4);
			}else if(x == 0){
				// The Left Header
				cout << setw(4) << y << setw(4);
			}else if(y == 0){
				// The Right Header
				if(x == sizeX){
					// Going to the next line
					cout << setw(4) << x << "\n";
				}else{
					cout << setw(4) << x << setw(4);
				}
			}else if(x == sizeX){
				// Going to the next line
				cout << setw(4) << x*y << "\n";
			}else{
				cout << setw(4) << x*y << setw(4);
			}
		}
	}
	
	return 0;
}
