// Zachary Sy
// mysayings but with lists


#include <iostream>
#include <fstream>
using namespace std;
#include <string>
#include <list>

// Startup 
list<string> startup(string filepath);

//Menu
bool menu(list<string> &sayings);

//Options
void dispAll(list<string> sayings); // Display All
void addSaying(list<string> &sayings); // Add a saying
void findSaying(list<string> sayings); // Search for a saying
void saveSayings(list<string> sayings); // Save the sayings
void deleteSaying(list<string> &sayings); // Delete a sayings

int main() {
	list<string> sayings;
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

list<string> startup(string path){
	ifstream file (path);
	string line;
	list<string> sayings;
	
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

bool menu(list<string> &sayings){
	int choice;
	
	// The options
	cout << "1. Display All Sayings" << endl;
	cout << "2. Enter a New Saying" << endl;
	cout << "3. Search For Sayings" << endl;
	cout << "4. Save All Sayings" << endl;
	cout << "5. Delete a Saying" << endl;
	cout << "6. Quit The Program" << endl << endl;
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
			deleteSaying(sayings);
			break;
		case 6:
			return 0;
	}
	
	return 1;
}

void dispAll(list<string> sayings){	
	for(auto i = sayings.begin(); i != sayings.end(); i++){
		cout << distance(sayings.begin(),i) <<  ": " << *i << endl;
	}
	
	cout << endl;
}

void addSaying(list<string> &sayings){
	string newSaying;
	
	cout << "Enter New Saying: ";
	cin.ignore();
	getline(cin, newSaying);
	
	sayings.push_back(newSaying);
}

void findSaying(list<string> sayings){
	string searchTerm;
	list<string> filtered;
	
	cout << "Enter Search: ";
	cin >> searchTerm;
	
	// Checks if the search term is in the string
	for(auto i = sayings.begin(); i != sayings.end(); i++){
		if((*i).find(searchTerm) != string::npos){
			cout << *i << endl;
		}
	}
	
	cout << endl;
}

void saveSayings(list<string> sayings){
	ofstream file;
	string path;
	
	cout << "Enter Save Location: ";
	cin.ignore();
	getline(cin, path);
	
	file.open(path);
	
	if(file.is_open()){
		// Appends each line to a line in the text file
		for(auto i = sayings.begin(); i != sayings.end(); i++){
			file << *i << endl;
		}
		
		cout << "Successfully saved sayings to " << path << endl << endl;
		file.close();
	}else{
		cout << "File Cannot Be Saved" << endl;
	}	
}

void deleteSaying(list<string> &sayings){
	int num;
	dispAll(sayings);
	
	cout << endl << endl << "Enter Number To Delete: ";
	cin >> num;
	
	list<string>::iterator it = sayings.begin();
	advance(it, num);
	sayings.erase(it);
}