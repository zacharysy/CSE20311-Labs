// Zachary Sy
// Mortgage Calculator

#include <iostream>
using namespace std;
#include <cmath>
#include <limits>
#include <iomanip>

int main(){
	float principal, interestRate, monthlyPayment, paid;
    int month = 0;
	
	// Error Handling
	string errorMsg = "Error: Bad Input";
	
	cout << "Principal: ";
	cin >> principal;		
	
	while(principal <= 0){
		principal = 1;
		cout << errorMsg << endl;
		cout << "Principal: ";
		cin >> principal;	
	}
	
	cout << "Interest Rate: ";
	cin >> interestRate;	
	
	while(interestRate < 0){	
		interestRate = 1;
		cout << errorMsg << endl;
		cout << "Interest Rate: ";
		cin >> interestRate;
	}
	
	cout << "Desired Monthly Payment: ";
	cin >> monthlyPayment;	
	
	while(monthlyPayment <= 0){
		monthlyPayment = 1;
		cout << errorMsg << endl;
		cout << "Desired Monthly Payment: ";
		cin >> monthlyPayment;	
	}
	
	// Headers
    cout << setw(4) << "Month  " << "Payment     " << "Interest" << "  Balance" << endl;	
    
	while(principal > 0){
    	// month number
    	month++;
		cout << month << setw(4);
		
		// Amount Being Paid This Month
		float paying = 0;
		// Interest For The month
    	float interest = (interestRate/12.0)*principal;
    	
		// monthly payment
		if(principal + interest - monthlyPayment > 0){
			cout << fixed << std::setprecision(2)   << "$" << setw(4) << monthlyPayment << setw(6);
			paid += monthlyPayment;
			paying += monthlyPayment;
		}else{
			cout << fixed << std::setprecision(2)  << "$" << setw(4) <<  principal + interest << setw(6);
			paid += principal + interest;
			paying += principal + interest;
		}
				
		// Display Interest
		cout << fixed << std::setprecision(2) << "$" << setw(6) << interest << setw(4);
		
		// Balance
		if(interest > paying){
			cout << "\n\nError: Monthly Payment Too Small" << endl;
			break;
		}
		
		principal = (principal + interest - paying);
		cout  << "$" << setw(9) << principal << endl;
		
		// Done Paying Mortgage
		if(principal == 0){
			int years = month/12;
			int months = (month-years*12);
	
			cout << "\n\nYou Paid A Total Of $" << paid << " over " << years << " years and " << months << " months." << endl;
		}	
	}
	
	return 0;
}
