// Zachary Sy
// Football Stats

#include <iostream>
using namespace std;

// Prototypes
bool ask();
void recordForYear(int year);
void ndLost();
void ndWon();
void lossWithCount(int n);
void winsWithCount(int n);
void diffWithCount(int n);


// Constants
const int wins[] = 
 { 6, 8, 6, 8, 5, 5, 6, 6, 8, 7, 4,
   6, 7, 7, 6, 7, 8, 6, 3, 9, 9, 10,
   8, 9, 10, 7, 9, 7, 5, 9, 10, 6, 6,
   3, 6, 7, 6, 6, 8, 7, 7, 8, 7, 9,
   8, 7, 8, 9, 9, 10, 4, 7, 7, 9, 9,
   8, 2, 7, 6, 5, 2, 5, 5, 2, 9, 7,
   9, 8, 7, 8, 10, 8, 8, 11, 10, 8, 9,
   11, 9, 7, 9, 5, 6, 7, 7, 5, 5, 8,
   12, 12, 9, 10, 10, 11, 6, 9, 8, 7, 9,
   5, 9, 5, 10, 5, 6, 9, 10, 3, 7, 6,
   8, 8, 12, 9, 8, 10, 4, 10, 12 };

const int losses[] = 
 { 3, 1, 2, 0, 3, 4, 1, 0, 1, 0, 1,
   0, 0, 0, 2, 1, 1, 1, 1, 0, 0, 1,
   1, 1, 0, 2, 1, 1, 4, 0, 0, 2, 2,
   5, 3, 1, 2, 2, 1, 2, 2, 0, 2, 1,
   2, 2, 0, 0, 0, 0, 4, 2, 2, 0, 1,
   2, 8, 3, 4, 5, 8, 5, 5, 7, 1, 2,
   0, 2, 2, 2, 1, 2, 3, 0, 2, 3, 3,
   1, 3, 4, 2, 6, 4, 5, 5, 6, 6, 4,
   0, 1, 3, 3, 1, 1, 5, 3, 3, 6, 3,
   7, 3, 6, 3, 7, 6, 3, 3, 9, 6, 6,
   5, 5, 1, 4, 5, 3, 8, 3, 1 };

const int startYear = 1900;
const int endYear = startYear + (sizeof(wins)/sizeof(wins[0]));

int main(){
	while(ask()) continue;
	
	return 0;
}

bool ask(){
	int choice;

	cout << "1: display the record for a given year." << endl;
	cout << "2: display years with more losses." << endl;
	cout << "3: display years with more wins." << endl;
	cout << "4: display years with at least \"n\" losses." << endl;
	cout << "5: display years with at least \"n\" wins." << endl;
	cout << "6: display years where the difference between wins and losses is \"n\"" << endl;
	cout << "7: exit" << endl << endl;

	cout << "Enter your choice: ";
	cin >> choice;	
	
	int year;
	int n;
	
	switch(choice){
		case 1:
			cout << "Enter the year: ";
			cin >> year;
			
			recordForYear(year);
			
			break;
		case 2:
			ndLost();
			break;
		case 3:
			ndWon();
			break;
		case 4:

			cout << "Enter minimum number of losses: ";
			cin >> n;
			
			lossWithCount(n);
			
			break;
		case 5:
			cout << "Enter minimum number of wins: ";
			cin >> n;
			
			winsWithCount(n);
			
			break;
		case 6:
			cout << "Enter win-loss difference: ";
			cin >> n;
			
			diffWithCount(n);
			break;
		case 7:
			return false;
		default:
			cout << "Invalid choice";
			break;
	}
	
	cout << endl;
	
	return true;
	
}

// display the record for a given year; 
void recordForYear(int year){
	cout << "Wins: " << wins[year-startYear] << ", Losses: " << losses[year-startYear] << endl;
}
// display years with more losses; 
void ndLost(){
	cout << "Years that ND Lost: ";
	
	for(int i = startYear; i <= endYear; i++){
		if(wins[i-startYear]<losses[i-startYear]){
			cout << i << " ";
		}
	}
	
	cout << endl;
}

// display years with more wins.
void ndWon(){
	cout << "Years that ND Won: ";
	
	for(int i = startYear; i <= endYear; i++){
		if(wins[i-startYear]>losses[i-startYear]){
			cout << i << " ";
		}
	}
	
	cout << endl;
}

// display years with at least n losses;
void lossWithCount(int n){
	cout << "Years with at least " << n << " losses: ";
	
	for(int i = startYear; i <= endYear; i++){
		if(losses[i-startYear]>=n){
			cout << i << " ";
		}
	}
	
	cout << endl;
}

// display years with at least n wins; 
void winsWithCount(int n){
	cout << "Years with at least " << n << " wins: ";
	
	for(int i = startYear; i <= endYear; i++){
		if(wins[i-startYear]>=n){
			cout << i << " ";
		}
	}
	
	cout << endl;
}

// display years where the difference between wins and losses is n
void diffWithCount(int n){
	cout << "Years with a win-loss difference of " << n << ": ";
	
	for(int i = startYear; i <= endYear; i++){
		if((wins[i-startYear]-losses[i-startYear]) == n){
			cout << i << " ";
		}
	}
	
	cout << endl;
}
































