// Zachary Sy
// Sieve of Eratosthenes

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

void init(vector<int>&);
void sieve(vector<int>&, int);
void disp(vector<int>);
bool isPandigital(int);

int main(){
	// Largest pandigital number is 987654321
	// But using divisibility rule for 3, any 9 and 8 digit pandigital number is divisible by 3
	// So a pandigital prime would be less than or equal to 7654321
	int maxNum = 7654321;
	
	vector<int> primes(maxNum,1);	

	init(primes);

	// From largest prime number, test if pandigital until one in found
	for(auto i = primes.end()-1; i > primes.begin(); i--){
		// *i is 0 so not a prime
		if(*i == 0) continue;
		
		// distance(i,primes.begin()) is the number
		int prime = distance(primes.begin(),i);
		
		if(isPandigital(prime)){
			cout << "The Largest Pandigital Prime is " <<  prime << endl;
			break;
		}
	}
		
}

// Sieve
void init(vector<int>& primes){	
	//Initializing
	primes[0] = 0;
	primes[1] = 0;
	
	// Sieving
	for(int i = 2; i <= sqrt(primes.size()); i++){
		if(primes[i]){
			sieve(primes, i);
		}
	}
}


//Killing the multiples of target by multiplying by j
void sieve(vector<int> &arr, int target){
	int j = 2;
	while(target*j < arr.size()){
		arr[target*j] = 0;
		j++;	
	}	
	
}

bool isPandigital(int num){
	int numDigits = ceil(log10(num)); // n: the number of digits
	vector<int> digits; // digits of the number
	vector<bool> isInDigit(10,false); // Keep track of which digit is in the number
	
	// Number is not pandigital if it contains numbers greater than n or 0
	isInDigit[0] = true;
	for(int i = numDigits+1; i < isInDigit.size(); i++){
		isInDigit[i] = true;
	}
	
	// Separate digits and put it in a vector
	while(num > 0) {
	    digits.push_back(num%10);
    	num = num / 10;
	}
	
	// Check the digits are not repeated
	for(auto i = digits.begin(); i != digits.end(); i++){
		if(isInDigit[*i]){
			return false;
		}else{
			isInDigit[*i] = true;
		}	
	}
	
	return true;
}