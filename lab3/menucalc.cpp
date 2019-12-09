// Zachary Sy
// Just A Calculator

#include <iostream>
#include <iomanip>
using namespace std;

bool ask();
double add(double, double); 
double sub(double, double); 
double mult(double, double); 
double div(double, double); 


int main(){
	
	while(ask()) continue;
	
	return 0;
}

bool ask(){
	int choice;
	cout << "What would you like to do?\n 1 for addition\n 2 for subtraction\n 3 for multiplication\n 4 for division\n 5 to exit" << endl;

	cout << "Enter your choice: ";
	cin >> choice;	
	
	// If input is not a number, exit because that shouldn't happen
	if(cin.fail()){
		cout << endl;
		return false;
	}
	
	// Check if exit
	if(choice == 5){
		cout << "Good bye!" << endl;
		return false;
	}else if(choice > 5 || choice <= 0){
		//If number is not in the choices, just prompt again
		cout << endl;
		cout << choice << " is an invalid choice" << endl << endl;
		return true;
	}

	// Getting the numbers
	double a,b;
	
	cout << "Enter two numbers: ";
	cin >> a;
	cin >> b;
	
	cout << "Inputs: " << a << ", " << b << endl;
	cout << setprecision(5);
	
	// Determine which operation to perform
	switch(choice){
		case 1: // Add
			cout << "(" << a << ") + (" << b << ") = " << add(a,b);
			break;
		case 2: // Sub
			cout << "(" << a << ") - (" << b << ") = " << sub(a,b);
			break;
		case 3: // Mult
			cout << "(" << a << ") * (" << b << ") = " << mult(a,b);
			break;
		case 4: // Div
			if(b != 0){
				cout << "(" << a << ") / (" << b << ") = " << div(a,b);
			}else{
				cout << "Cannot divide by zero!";
			}
			break;
	}
	
	cout << endl << endl; 
	
	// Makes an infinite loop until exit is chosen
	return true;
};

// How these functions work are obvious and the function names are descriptive so I assume no comment is necessary

double add(double a, double b){
	return a + b;
}; 

double sub(double a, double b){
	return a - b; 
}; 

double mult(double a, double b){
	return a * b; 
}; 

double div(double a, double b){
	return a / b; 
}; 
