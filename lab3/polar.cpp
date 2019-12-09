// Zachary Sy
// Converts Cartesian to Polar 

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double get_radius(double, double); 
double get_angle(double, double); 
void quadrant_info(double, double);

int main(){
	// Getting the input
    double x,y;
    
    cout << "X: ";
    cin >> x;
    
    cout << "Y: ";
    cin >> y;
    
    cout << endl;
    
    // Output
    cout << fixed << setprecision(2);
    cout << "r: " << get_radius(x,y) << endl;
    cout << "θ: " << get_angle(x,y) << endl;
    quadrant_info(x,y);

    return 0;
}

double get_radius(double x, double y){
	return sqrt(pow(x,2)+pow(y,2)); // Formula for distance in R^2 is sqrt(x^2 + y^2)
}

double get_angle(double x, double y){
	return atan2(y,x)*(180.0/3.1415); // Get angle between the points and convert to degrees 
}

void quadrant_info(double x, double y){
	// Probably an easier way to do this without a lot of else ifs but this was the fastest to type
	if(x == 0 && y == 0){
		cout << "Origin";
	}else if(x == 0){
		cout << "X-Axis";
	}else if(y == 0){
		cout << "Y-Axis";
	}else if(x > 0 && y > 0){
		cout << "Quadrant I";
	}else if(x < 0 && y > 0){
		cout << "Quadrant II";
	}else if(x < 0 && y < 0){
		cout << "Quadrant III";
	}else if(x > 0 && y < 0){
		cout << "Quadrant IV";
	}
	
	cout << endl;
}
