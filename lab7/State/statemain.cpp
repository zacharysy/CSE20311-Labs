// Zachary Sy
// Testing State

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "state.h"

using namespace std;

int main(){
	vector<State> states;
	string input;

	// Ask For CSV File
	while(states.size() == 0){
		cout << "Enter State Filepath: "; 
		getline(cin,input);
		states = startup(input);
	}
	
	// Main Menu
	while(menu(states)) continue;
	
	
	return 0;
}

vector<State> startup(string filepath){
	vector<State> states;
	ifstream file (filepath);
	string line;

	
	// Push all the lines in the file
	if(file.is_open()){
		while(getline(file,line)){
			//Create a State Class
			stringstream stream (line);
			vector<string> tempState;
			State state;
			
			while(stream.good()){
				// Put each cell from the CSV to a temporary vector
				string cell;
				getline(stream, cell, ',');
				tempState.push_back(cell);
			}
			
			state = State(tempState[0],tempState[1],tempState[2],stoi(tempState[3]),stoi(tempState[4]),stoi(tempState[5]));
			states.push_back(state);
		}	
	
		file.close();
	
	}else{
		// Doing some error handling here
		cout << "No Startup File Found" << endl << endl;
	}
	
	return states;
}

bool menu(vector<State> &states){
	int choice;
	
	// The options
	cout << "1. All States" << endl;
	cout << "2. Search For A State" << endl;
	cout << "3. Get State Information" << endl;
	cout << "4. State With The Most People" << endl;
	cout << "5. Oldest State" << endl;
	cout << "6. Quit The Program" << endl << endl;
	cout << "Enter Choice: ";
	
	cin >> choice;
	cout << endl;
	
	switch(choice){
		case 1:
			searchState(states, "");
			break;
		case 2:			
			{
			string keyword;
			cout << "Search (Case-Sensitive): ";

			cin.ignore();
			getline(cin, keyword);

			cout << endl;

			searchState(states, keyword);
			break;
			}
		case 3:
			{
			string abbv;
			
			cout << "Enter State Abbreviation (Case-Sensitive): ";

			cin.ignore();
			getline(cin, abbv);

			stateInfo(states, abbv);
			cout << endl;
			break;
			}
		case 4:
			mostPop(states);
			break;
		case 5:
			oldest(states);
			break;
		case 6:
			return 0;
			
	}
	
	return 1;
}

void searchState(vector<State> states,string keyword){
	vector<State> matches;
	keyword = keyword;
	
	for(auto i=states.begin(); i != states.end(); i++){
		// Check for matches in abbreviation
		string abbv = (*i).getAbbv();
		string name = (*i).getName();
	
		if(abbv.find(keyword) != string::npos){
			matches.push_back(*i);
		}else if(name.find(keyword) != string::npos){
			matches.push_back(*i);		
		}
	
	}
	
	
	for(auto i=matches.begin(); i != matches.end(); i++){
		(*i).info(true);
	}	
	
	cout << endl;
}

void stateInfo(vector<State> states,string abbv){
	State state;
	bool found;
	
	cout << endl;
	
	for(auto i=states.begin(); i != states.end(); i++){
		// Check for matches in abbreviation
		if(abbv == (*i).getAbbv()){
			state = *i;
			found = !found;
		}
	
	}

	if(found){
		state.info();
	}else{
		cout << "No State Found" << endl;
	}
	
	cout << endl;
}

void mostPop(vector<State> states){
	State maxState = states[0];

	for(auto i=states.begin()+1; i != states.end(); i++){
		if((*i).getPopulation() > maxState.getPopulation()){
			maxState = *i;
		}
	}
	
	
	cout << endl << "The State with the most people is " << maxState.getName() << " with " << maxState.getPopulation() << " people!" << endl << endl;
	
}

void oldest(vector<State> states){
	State oldState = states[0];

	for(auto i=states.begin()+1; i != states.end(); i++){
		if((*i).getFoundYear() > oldState.getFoundYear()){
			oldState = *i;
		}
	}
	
	
	cout << endl << "The oldest state is " << oldState.getName() << ", which was founded in " << oldState.getFoundYear() << "!" << endl << endl;
	
}

