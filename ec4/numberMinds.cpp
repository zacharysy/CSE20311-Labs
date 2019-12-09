#include <iostream>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <cstdlib>
#include <thread>
using namespace std;

void update(vector<vector<int> >& numbers, vector<int>& corrects, vector<vector<bool >>& correctness, vector<int> rightNum, bool displaying = true);
void display(vector<vector<int> >& numbers, vector<int>& corrects, vector<vector<bool >>& correctness, vector<int> rightNum);
void killZeros(vector<vector<int> >& numbers, vector<int>& corrects, vector<vector<bool >>& correctness, vector<int> rightNum);
void killCorrects(vector<vector<int> >& numbers, vector<int>& corrects, vector<vector<bool >>& correctness, vector<int> rightNum);
void updateCorrects(vector<vector<int> >& numbers, vector<int>& corrects, vector<vector<bool >>& correctness, vector<int> rightNum);
bool isValid(vector<vector<int> >& numbers, vector<int>& corrects, vector<vector<bool >>& correctness, vector<int> rightNum);
bool isIncomplete(vector<vector<int> >& numbers, vector<int>& corrects, vector<vector<bool >>& correctness, vector<int> rightNum);
void descend(vector<vector<int> > numbers, vector<int> corrects, vector<vector<bool >> correctness, vector<int> rightNum);
bool compare(vector<int> n1, vector<int> n2);

/*
vector<vector<int> > numbers = {
{5,6,1,6,1,8,5,6,5,0,5,1,8,2,9,3},
{3,8,4,7,4,3,9,6,4,7,2,9,3,0,4,7},
{5,8,5,5,4,6,2,9,4,0,8,1,0,5,8,7},
{9,7,4,2,8,5,5,5,0,7,0,6,8,3,5,3},
{4,2,9,6,8,4,9,6,4,3,6,0,7,5,4,3},
{3,1,7,4,2,4,8,4,3,9,4,6,5,8,5,8},
{4,5,1,3,5,5,9,0,9,4,1,4,6,1,1,7},
{7,8,9,0,9,7,1,5,4,8,9,0,8,0,6,7},
{8,1,5,7,3,5,6,3,4,4,1,1,8,4,8,3},
{2,6,1,5,2,5,0,7,4,4,3,8,6,8,9,9},
{8,6,9,0,0,9,5,8,5,1,5,2,6,2,5,4},
{6,3,7,5,7,1,1,9,1,5,0,7,7,0,5,0},
{6,9,1,3,8,5,9,1,7,3,1,2,1,3,6,0},
{6,4,4,2,8,8,9,0,5,5,0,4,2,7,6,8},
{2,3,2,1,3,8,6,1,0,4,3,0,3,8,4,5},
{2,3,2,6,5,0,9,4,7,1,2,7,1,4,4,8},
{5,2,5,1,5,8,3,3,7,9,6,4,4,3,2,2},
{1,7,4,8,2,7,0,4,7,6,7,5,8,2,7,6},
{4,8,9,5,7,2,2,6,5,2,1,9,0,3,0,6},
{3,0,4,1,6,3,1,1,1,7,2,2,4,6,3,5},
{1,8,4,1,2,3,6,4,5,4,3,2,4,5,8,9},
{2,6,5,9,8,6,2,6,3,7,3,1,6,8,6,7}
};
*/

vector<vector<int> > numbers = {{9,0,3,4,2}, {7,0,7,9,4}, {3,9,4,5,8}, {3,4,1,0,9}, {5,1,5,4,5}, {1,2,5,3,1}};
int rowLength = numbers.size();
int colLength = numbers[0].size();

vector<int> blank(colLength,-1);
vector<int> rightNum(colLength,-1);

//vector<int> corrects = {2,1,3,3,3,1,2,3,1,2,3,1,1,2,0,2,2,3,1,3,3,2};
vector<int> corrects = {2,0,2,1,2,1};
vector<vector<bool> > correctness(rowLength, vector<bool>(colLength,true));
	
vector<thread*> threads;

int main(){
	
	// Sort By Number of Corrects
	
	for(int i = 0; i < (int) corrects.size(); i++){
		numbers[i].push_back(corrects[i]);
	}
	
	sort(numbers.begin(),numbers.end(),compare);
	
	for(int i = 0; i < (int) corrects.size(); i++){
		corrects[i] = numbers[i].back();
		numbers[i].pop_back();
	}
	
	update(numbers, corrects, correctness, rightNum);
		
	
	for(int row = 0; row < rowLength; row++){
		vector<int> tryNum;

		vector<int> tempCorrects = corrects;
		vector<vector<bool> > tempCorrectness = correctness;
		vector<int> tempNum = blank;
		
		if(correctness[row][0]){			
			tempNum[0] = numbers[row][0];
			descend(numbers, tempCorrects, tempCorrectness, tempNum);
		}
	}
	

	while(1){};
	
}

bool compare(vector<int> n1, vector<int> n2){	
	if(n1.back() == n2.back()){
		return n1.front() < n2.front();
	}
	
	return n1.back() < n2.back();
}

void descend(vector<vector<int> > numbers, vector<int> corrects, vector<vector<bool >> correctness, vector<int> rightNum){

	if(!isIncomplete(numbers,corrects,correctness,rightNum)){
		for(int num: rightNum){
			cout << num << " ";
		}
		cout << endl;
		exit(0);
	}
			
	int col = -1;
	
	for(int digit = 0; digit < (int) rightNum.size(); digit++){
		if(rightNum[digit] != -1){
			col = digit;
		}
	}
	
	if(col == (int) rightNum.size()-1){
		return;
	}
	
	if(!isValid(numbers,corrects,correctness, rightNum)){
		rightNum[col] = -1;
		return;
	}
	
	col++;
	
	for(int row = 0; row < rowLength; row++){		
		if(correctness[row][col]){
			vector<vector<int> > tempNumbers = numbers;
			vector<int> tempCorrects = corrects;
			vector<vector<bool> > tempCorrectness = correctness;
			vector<int> tempNum = rightNum; 
			
			tempNum[col] = numbers[row][col];
			update(tempNumbers, tempCorrects, tempCorrectness,tempNum);
			descend(tempNumbers, tempCorrects, tempCorrectness,tempNum);
			
			for(int aRow = 0; aRow < rowLength; aRow++){
				if(numbers[aRow][col] == numbers[row][col]){
					correctness[aRow][col] = false;
				}
			}
			
			
		}
	}

}

void update(vector<vector<int> >& numbers, vector<int>& corrects, vector<vector<bool >>& correctness, vector<int> rightNum, bool displaying){
	killZeros(numbers, corrects, correctness, rightNum);
	updateCorrects(numbers, corrects, correctness, rightNum);
	killCorrects(numbers, corrects, correctness, rightNum);	
	killZeros(numbers, corrects, correctness, rightNum);
	
	if(displaying) display(numbers, corrects, correctness,rightNum);
}

bool isValid(vector<vector<int> >& numbers, vector<int>& corrects, vector<vector<bool >>& correctness, vector<int> rightNum){
	for(int row = 0; row < rowLength; row++){
		int tally = 0;
		
		for(int col = 0; col < colLength; col++){
			if(correctness[row][col]){
				tally++;
			}
		}
		
		if(tally < corrects[row]){
			return false;
		}
		
		if(corrects[row] < 0){
			return false;
		}
		
		// More right numbers in the places than allowed
		tally = 0;
		
		for(int col = 0; col < colLength; col++){
			if(rightNum[col] == numbers[row][col]){
				tally++;
			}
		}
		
		if(tally > corrects[row]){
			return false;
		}
		
	}
	
	return true;
}

bool isIncomplete(vector<vector<int> >& numbers, vector<int>& corrects, vector<vector<bool >>& correctness, vector<int> rightNum){
	for(int digit: rightNum){
		if(digit == -1){
			return true;
		}
	}
	
	//update(numbers, corrects, correctness, rightNum,false);
	
	if(!isValid(numbers, corrects, correctness,rightNum)) return true;
	
	return false;
}

// Kill rows that are all zero
void killZeros(vector<vector<int> >& numbers, vector<int>& corrects, vector<vector<bool >>& correctness, vector<int> rightNum){
	// int noneRow = distance(corrects.begin(),find(corrects.begin(),corrects.end(),0));
	
	for(int noneRow = 0; noneRow < (int) corrects.size(); noneRow++){
		if(corrects[noneRow] != 0) continue;
		
		// Kill numbers that are wrong
		for(int row = 0; row < rowLength; row++){
			for(int col = 0; col < colLength; col++){		
				// Number is in right position
				if(numbers[noneRow][col] == rightNum[col]) continue;
			
				int wrongVal = numbers[noneRow][col];
				
				if(numbers[row][col] == wrongVal){
					correctness[row][col] = false;
				}
			}
		}
		
	}

}

// Kill digits that are not the same as the right numbers
void killCorrects(vector<vector<int> >& numbers, vector<int>& corrects, vector<vector<bool >>& correctness, vector<int> rightNum){
	for(int col = 0; col < colLength; col++){
		if(rightNum[col] != -1){
			for(int row = 0; row < rowLength; row++){
				if(numbers[row][col] != rightNum[col]){
					correctness[row][col] = false;
				}
			}
		}
	}
}

// New tally
void updateCorrects(vector<vector<int> >& numbers, vector<int>& corrects, vector<vector<bool >>& correctness, vector<int> rightNum){
	for(int col = 0; col < colLength; col++){
		if(rightNum[col] != -1){
			for(int row = 0; row < rowLength; row++){
				if(numbers[row][col] != rightNum[col]){
					correctness[row][col] = false;
				}
			}
		}
	}


	for(int row = 0; row < rowLength; row++){
		int tally = 0;
		
		for(int col = 0; col < colLength; col++){
			if(correctness[row][col]){
				tally++;
			}
		}
		
		if(tally < corrects[row]){
			corrects[row] = -1;
		}
		
		// More right numbers in the places than allowed
		tally = 0;
		
		for(int col = 0; col < colLength; col++){
			if(rightNum[col] == numbers[row][col]){
				tally++;
			}
		}
		
		if(tally == corrects[row]){
			for(int col = 0; col < colLength; col++){
				if(numbers[row][col] != rightNum[col]){
					for(int otherRow = 0; otherRow < rowLength; otherRow++){
						if(numbers[otherRow][col] == numbers[row][col]){
							correctness[row][col] = false;							
						}
					}						
				}
			}
		}
		
	}
}


void display(vector<vector<int> >& numbers, vector<int>& corrects, vector<vector<bool >>& correctness, vector<int> rightNum){
	system("clear");
	int rowLength = numbers.size();
	int colLength = numbers[0].size();
	
	for(int digit:rightNum){
		if(digit > -1){
			cout << digit << " ";
		}else{
			cout << "_ ";
		}
	}
	
	cout << endl;
	
	for(int row = 0; row < rowLength; row++){
		for(int col = 0; col <= colLength; col++){
			if(col == colLength){
				cout << "\t" << corrects[row] << endl;
				continue;
			}
			
			if(correctness[row][col]){
				cout << numbers[row][col] << " ";
			}else{
				cout << "  ";			
			}
			
		}
	}
	
	cout << endl << endl;

}