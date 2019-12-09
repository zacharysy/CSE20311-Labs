// Zachary Sy
// Frequency analysis


#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

// Offset the letters
const int indexOffset = 65 - 1;

// Read and check text frequency
vector<int> freqCheck(string filepath);

// Get total chars
int sumFreq(vector<int> freq, int offset);

// Display
void dispFreq(vector<int> sayings); 


int main() {
	vector<int> freq;
	string input;
	
	// Analyze Text
	while(sumFreq(freq,0) == 0){
		cout << "Enter Text Filepath: "; 
		getline(cin,input);
		freq = freqCheck(input);
	}
	
	dispFreq(freq);
	
	return 0;
}

vector<int> freqCheck(string path){
	vector<int> freq(28,0);  // Index 0 is whitespace, index 27 is other characters
	ifstream file (path);
	char ch;
	int i;
	
	// Push all the lines in the file
	if(file.is_open()){
		while(file.get(ch)){
			if(isalpha(ch)){
				i = toupper(ch) - indexOffset;
				freq[i]++;
			}else if(isspace(ch)){
				freq[0]++;
			}else{
				freq[27]++;
			}
			
		}	
		
		file.close();
		
	}else{
		// Doing some error handling here
		cout << "No Startup File Found" << endl << endl;
	}
	
	return freq;

}

void dispFreq(vector<int> freq){	
	// Set offset to 1 so that whitespace and other chars are not included in count
	int letterCount = sumFreq(freq,1); 
	int sum = sumFreq(freq,0);

	// Prettier Formatting
	int width = log10(letterCount) + 1;
	
	// Reading off frequencies
	for(auto i = freq.begin()+1; i != freq.end()-1; i++){
		char letter = tolower(distance(freq.begin(),i) + indexOffset);
		
		cout << setw(3) << letter <<  ":" << setw(width) << *i;
		
		if(letter % 6 == 0){
			cout << endl;
		}
	}
	
	cout << endl;
	cout << "There were " << letterCount << " letters" << endl;
	cout << "There were " << sum << " total characters" << endl;
	cout << "There were " << freq[0] << " white space characters" << endl;
	cout << "Space Percentage: " << fixed << setprecision(1) << (freq[0]/(double) sum)*100 << "%" << endl;
}

int sumFreq(vector<int> freq, int offset){
	int sum = 0;
	
	for(auto i = freq.begin() + offset; i != freq.end() - offset; i++){
		sum += *i;
	}
	
	return sum;
}
