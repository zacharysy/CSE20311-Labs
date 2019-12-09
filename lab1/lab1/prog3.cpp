// Zachary Sy
// Formula Calculator

#include <iostream>
using namespace std;

int gcd(int, int);

int main(){
    //Calculate The Greatest Common Divisor of two numbers
    int a; // First Number
    int b;

    cout << "\n GCD Calculator\n\n";

    cout << "a: ";
    cin >> a;

    cout << "b: ";
    cin >> b;

    cout << "\n";

    cout << "\nThe GCD of " << a << " and " << b << " is " << gcd(a,b) << "\n\n";
    return 0;
}

int gcd(int a, int b){
    if(b == 0){
        return a;
    }else if(a == 0){
        return b;
    }

    if(a>b){
        int q = a/b; // Quotient Part
        int rem = a%b; // Remainder Part
	
		// Formatting for Euclidean algorithm
        cout << a << "=" << q << "(" << b << ")+" << rem << endl;
        return gcd(b,rem);
    }else{
        int q = b/a;
        int rem = b%a;

        cout << b << "=" << q << "(" << a << ")+" << rem << endl;
        return gcd(a,rem);
    }
}
