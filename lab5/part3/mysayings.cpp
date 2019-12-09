// Zachary Sy
// UNIX Fortune, but in C++


#include <iostream>
#include <fstream>
using namespace std;
#include <string>
#include <vector>

// Startup 
vector<string> startup(string filepath);

//Menu
bool menu(vector<string> &sayings);

//Options
void dispAll(vector<string> sayings); // Display All
void addSaying(vector<string> &sayings); // Add a saying
void findSaying(vector<string> sayings); // Search for a saying
void saveSayings(vector<string> sayings); // Save the sayings

int main() {
	vector<string> sayings;
	string input;
	
	// Ask For Startup File
	while(sayings.size() == 0){
		cout << "Enter Startup Filepath: "; 
		getline(cin,input);
		sayings = startup(input);
	}
	
	// Main Menu
	while(menu(sayings)) continue;
	
	return 0;
}

vector<string> startup(string path){
	ifstream file (path);
	string line;
	vector<string> sayings;
	
	// Push all the lines in the file
	if(file.is_open()){
		while(getline(file,line)){
			sayings.push_back(line);
		}	
		
		file.close();
		
	}else{
		// Doing some error handling here
		cout << "No Startup File Found" << endl << endl;
	}
	
	return sayings;

}

bool menu(vector<string> &sayings){
	int choice;
	
	// The options
	cout << "1. Display All Sayings" << endl;
	cout << "2. Enter a New Saying" << endl;
	cout << "3. Search For Sayings" << endl;
	cout << "4. Save All Sayings" << endl;
	cout << "5. Quit The Program" << endl << endl;
	cout << "Enter Choice: ";
	
	cin >> choice;
	
	switch(choice){
		case 1:
			dispAll(sayings);
			break;
		case 2:
			addSaying(sayings);
			break;
		case 3:
			findSaying(sayings);
			break;
		case 4:
			saveSayings(sayings);
			break;
		case 5:
			return 0;
	}
	
	return 1;
}

void dispAll(vector<string> sayings){	
	for(auto i = sayings.begin(); i < sayings.end(); i++){
		cout << *i << endl;
	}
	
	cout << endl;
}

void addSaying(vector<string> &sayings){
	string newSaying;
	
	cout << "Enter New Saying: ";
	cin.ignore();
	getline(cin, newSaying);
	
	sayings.push_back(newSaying);
}

void findSaying(vector<string> sayings){
	string searchTerm;
	vector<string> filtered;
	
	cout << "Enter Search: ";
	cin >> searchTerm;
	
	// Checks if the search term is in the string
	for(auto i = sayings.begin(); i < sayings.end(); i++){
		if((*i).find(searchTerm) != string::npos){
			cout << *i << endl;
		}
	}
	
	cout << endl;
}

void saveSayings(vector<string> sayings){
	ofstream file;
	string path;
	
	cout << "Enter Save Location: ";
	cin.ignore();
	getline(cin, path);
	
	file.open(path);
	
	if(file.is_open()){
		// Appends each line to a line in the text file
		for(auto i = sayings.begin(); i < sayings.end(); i++){
			file << *i << endl;
		}
		
		cout << "Successfully saved sayings to " << path << endl << endl;
		file.close();
	}else{
		cout << "File Cannot Be Saved" << endl;
	}	
}