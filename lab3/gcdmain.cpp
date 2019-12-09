// Zachary Sy
// Calculates the GCD

#include <iostream>
using namespace std;

int getgcd(int, int);

int main(){
    int a,b; // Inputs

    cout << "First Integer: ";
    cin >> a;

    cout << "Second Integer: ";
    cin >> b;

    cout << "\nThe GCD of " << a << " and " << b << " is " << getgcd(a,b) << "\n\n";
    return 0;
}

int getgcd(int a, int b){
	while(a != 0 & b != 0){
		if(a>b){
			int q = a/b; // Quotient Part
			int rem = a%b; // Remainder Part
			
			a = b;
			b = rem;
		}else{
			int q = b/a; // Quotient Part
			int rem = b%a; // Remainder Part

			a = a;
			b = rem;
		}
	}
	
	if(b == 0){
        return a;
    }else if(a == 0){
        return b;
    }
}
