#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
using namespace std;

struct BestInfo{
	bool exact = false;
	int size = 10000;
	vector<int> path;
};

void findStamps(vector<int> stampValues ,int amount);
void import(string filename, vector<int>& stampValues, vector<int>& parcels);
void stamping(vector<int> stamps, int amount, vector<int> bestStamps,vector<vector<int>>&, int& best);

BestInfo analyze(vector<vector<int>> paths, int amount);

int main(){
	vector<int> stampValues;
	vector<int> parcels;
	string filename = "data.dat";
	
	// Import data from file
	import(filename, stampValues, parcels);	
	
	// Use same algorithm for each stamp
	for(int parcel:parcels){
		findStamps(stampValues, parcel);
	}
	
	return 0;
}

void import(string filename, vector<int>& stampValues, vector<int>& parcels){
	ifstream file(filename);
	string stampString;
	
	getline(file, stampString);
	stringstream stream (stampString);
	
	while(stream.good()){
		string val;
		getline(stream, val, ' ');
		stampValues.push_back(stoi(val));
	}
	
	cout << endl;
	
	string parcel;
	while(getline(file,parcel)){
		parcels.push_back(stoi(parcel));
	}	
	
	sort(stampValues.begin(), stampValues.end());
	
	cout << "STAMP VALUES ";
	for(int i:stampValues){
		cout << i << " ";
	}
	
	cout << endl << endl;
}

void findStamps(vector<int> stamps ,int amount){
	vector<vector<int>> possible;
	vector<int> bestStamps;
	
	BestInfo best;
	int bestCount = 10000000;

	// Check solutions that start with each value in the stampValue array
	while(stamps.size() > 0){
		bestStamps.push_back(stamps.back()); // initial stamp
		stamping(stamps, amount, bestStamps, possible, bestCount);
		
		best = analyze(possible, amount);
		
		// If a path of stamps are already found, then only looking for better ones
		if(best.exact){
			bestCount = best.size;
			possible = {};
			possible.push_back(best.path);
		}
		
		// Reset
		stamps.pop_back();
		bestStamps = {};
	}
		
	// Displaying results
	sort(best.path.begin(),best.path.end());
	reverse(best.path.begin(),best.path.end());
	
	cout << "AMOUNT " << amount << endl;
	cout << "STAMPS USED ";
	for(int num:best.path){
		cout << num << " ";
	}
	
	cout << endl << endl;
}

void stamping(vector<int> stamps, int amount, vector<int> bestStamps, vector<vector<int>>& possible, int& best){	
	int tempAmount = amount;
	vector<int> tempStamps = bestStamps;
	
	// Base Case	
	if(amount - stamps.back() <= 0 && amount - stamps.back() >= -stamps[0]+1){
		possible.push_back(bestStamps);
		best = bestStamps.size();
		return;
	}
	
	// Too big, don't check
	if(bestStamps.size() > best | amount - stamps.back() <= 0){
		return;
	}
	
	// Keep going
	for(auto i = stamps.end()-1; i >= stamps.begin(); i--){
		tempAmount -= *i;
		tempStamps.push_back(*i);
		
		stamping(stamps, tempAmount, tempStamps, possible, best);
		
		
		tempAmount = amount;
		tempStamps = bestStamps;
	}
}

BestInfo analyze(vector<vector<int>> paths, int amount){
	bool exact = false;
	int bestSize = 10000;
	vector<int> bestPath;
	
	for(vector<int> path: paths){
		int sum = 0;
		
		for(int num:path){
			sum += num;
		}
		
		//Priority to the paths that give exact amounts
		if(sum == amount){
			if(!exact){
				// This path is the first exact one
				bestSize = path.size();
				bestPath = path;
				exact = true;
			}else{
				// Check if it's better than the current exact path
				if(path.size() <= bestSize){
					bestSize = path.size();
					bestPath = path;
				}
			}	
		}else if(!exact){
			//If there still isn't an exact amount
			
			// Check if it's better than the current path
			if(path.size() <= bestSize){
				bestSize = path.size();
				bestPath = path;
			}
		}
	
	}
	
	BestInfo best;
	best.exact = exact;
	best.size = bestSize;
	best.path = bestPath;
	return best;

}
