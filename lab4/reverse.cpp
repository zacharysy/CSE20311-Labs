// Zachary Sy
// Reverse

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


int main(){
	int arr[5];
	double ans;
			
	for(int i = 0; i < 5; i++){
		cout << i+1 << "th Number: ";
		cin >> arr[i];
	}
	
	cout << endl;
	
	for(int i = 4; i >= 0; i--){
		cout << arr[i] << endl;  
	}
	
}

