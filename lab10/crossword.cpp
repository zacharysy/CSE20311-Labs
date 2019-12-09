// Zachary Sy
// crossword main

#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <fstream>

#include "crossboard.h"

using namespace std;

void import(string filename, Crossboard&);
void prompt(Crossboard&);

int main(int argc, char *argv[]){
	Crossboard board = Crossboard();
	
	cout << "Anagram Crossword Puzzle Generator\n----------------------------------" << endl;
	
	if(argc == 1){
		prompt(board);
	}else if(argc == 2){
		import(argv[1], board);
	}else if(argc == 3){
		import(argv[1], board);
		board.display(argv[2]);
	}else{
		cout << "Incorrect Number of Arguments" << endl;
		return 1;
	}

	board.display();
	
	return 0;
}

void import(string filename, Crossboard& board){
	ifstream file(filename);
	string word;
	vector<string> words;
	
	if(file.is_open()){
		while(file >> word){
			words.push_back(word);
		}
	}else{
		cout << "Invalid Filename" << endl;
		return;
	}
	
	if(words.size() > 0){
		board.init(words);
	}
}

void prompt(Crossboard& board){
	string word = "";
	vector<string> words;

	cout << endl << "Enter a list of words:" << endl;
	
	int counter = 0;
	
	while(word != "." && counter < 20){
		cin >> word;
		words.push_back(word);		
		counter++;
	}
	words.pop_back();
		
	if(counter == 20){
		cout << "Max capacity reached" << endl << endl;
	}
	


	if(words.size() > 0){
		board.init(words);
	}
}