// Zachary Sy
// ASCII Art

#include <iostream>
using namespace std;
#include <cmath>
#include <limits>
#include <iomanip>

int main(){
	float minX = 0;
	float maxX = 20;
	float step = 0.1;
	
	// So the ASCII Graph fits the terminal window
	float scale = 5;
	
	// X & Y coordinates of the maximum and minimum
	float maxY = 0;
	float minY = 1000000000;
	float maxYX = 0;
	float minYX = 0;
	
	//Headers
	cout << "A plot of y=sin(5x)-sin(2x)+2 from x=" << minX << " to " << fixed << setprecision(1) << maxX << endl;
	cout << "X\tY" << endl;
	
	for(float x = minX; x <= maxX; x += step){
		// Calculating the plot
		float y = sin(5*x)-sin(2*x) + 2;
		
		// Labels
		cout << fixed << setprecision(2) << x << "\t"; 
		cout << fixed << setprecision(2) << y << "\t"; 
		
		// Get the max
		if(y > maxY){
			maxY = y;
			maxYX = x;
		}
		
		// Get the min
		if(y < minY){
			minY = y;
			minYX = x;
		}
		
		//ASCII graph
		for(int i = 0; i < y*scale; i++){
			cout << "#";
		}
		cout << endl;
		
	}
	
	cout << "\nThe maximum of " << maxY << " was at x=" << maxYX << endl;
	cout << "The minimum of " << minY << " was at x=" << minYX << endl;
	


	return 0;
}
