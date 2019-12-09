// Zachary Sy
// Sieve of Eratosthenes

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int arrSize = 1000;

void init(int*);
void sieve(int*, int);
void disp(int*);



int main(){
	int arr[arrSize];	

	//Initializing
	init(arr);
	
	// Sieving
	// Sieve only needs to check for numbers less than square root of size
	int maxNum = ceil(sqrt(arrSize));
	
	for(int i = 0; i <= maxNum; i++){
		if(arr[i]){
			sieve(arr, i);
		}
	}
	
	disp(arr);
	
}

// Create Array with default values
void init(int* arr){	
	arr[0] = 0;
	arr[1] = 0;
	
	for(int i = 2; i < arrSize; i++){
		arr[i] = 1;
	}
}


//Killing the multiples of target by multiplying by j
void sieve(int* arr, int target){
	int j = 2;
	while(target*j < arrSize){
		arr[target*j] = 0;
		j++;	
	}	
	
}

// Formats and displays
void disp(int *arr){
	int count = 1;
	
	for(int i = 0; i < arrSize; i++){
		if(arr[i]){
			cout << setw(4);
			if(count%10 == 0){
				//Make a newline so column count is 10
				cout << arr[i]*i << endl;
			}else{
				cout << arr[i]*i << setw(2);
			}
			
			count++;
		}
	}
	cout << endl << endl;
	
}