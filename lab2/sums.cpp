// Zachary Sy
// computes some sums
#include <iostream>
using namespace std;
#include <cmath>

int main(){
	int sumSq = 0;
	double sumRt = 0;
	
	for(int i=0; i <= 10; i++){
		sumSq += pow(i,2);
		sumRt += sqrt(i);
	}
	
	cout << "Sum of Squares: " << sumSq << "\nSum of Square Roots: " << sumRt << endl;
	
	return 0;
}
