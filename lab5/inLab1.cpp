#include <iostream>
using namespace std;

void find_freqs(int [], int [], int);
void results(int [], int);

int main(){
  // array with random digits
  int digits[] = {4,3,6,5,7,8,9,4,6,3,1,3,5,7,6,3,6,
                  5,6,7,0,2,9,7,1,3,2,1,6,7,4,6,2,8,
                  1,4,5,6,0,2,7,6,4,5,6,8,3,5,7,1,5};
  int size = sizeof(digits)/sizeof(int);   // find the array's size
  int freq[10] = {0};    // array to tally the frequency of digits

  find_freqs(digits, freq, size); // compute digits' frequencies
  results(freq, 10);  // display frequencies for each digit

  return 0;
}

void find_freqs(int a[], int freq[], int sz){
	for(int i = 0; i < sz; i++){
		freq[a[i]]++;
	}
}

void results(int freq[], int s)
{
  for (int n = 0; n < s; n++) 
    cout <<  "digit " << n << " occurs " << freq[n] << " times" << endl;
}