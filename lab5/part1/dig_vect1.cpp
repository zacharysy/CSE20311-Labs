// Zachary Sy
// Vectors 1

#include <iostream>
#include <vector>
using namespace std;

void find_freqs(vector<int>, vector<int> &);
void results(vector<int>);

int main(){
  // array with random digits                  
  vector<int> digits = {4,3,6,5,7,8,9,4,6,3,1,3,5,7,6,3,6, 5,6,7,0,2,9,7,1,3,2,1,6,7,4,6,2,8,1,4,5,6,0,2,7,6,4,5,6,8,3,5,7,1,5};
  vector<int> freq(10);    // array to tally the frequency of digits

  find_freqs(digits, freq); // compute digits' frequencies
  results(freq);  // display frequencies for each digit

  return 0;
}

void find_freqs(vector<int> a, vector<int> &freq){
	for(int i = 0; i < a.size(); i++){
		freq.at(a.at(i))++;
	}
}

void results(vector<int> freq){	
  for(int n = 0; n < freq.size(); n++) 
    cout <<  "digit " << n << " occurs " << freq.at(n) << " times" << endl;
}