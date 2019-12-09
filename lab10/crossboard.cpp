// Zachary Sy
// board class 

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>
#include <chrono>
#include <string>
#include <unistd.h>
#include <cstdlib>
using namespace std;

#include "crossboard.h"

Crossboard::Crossboard(){
	cells = vector<vector<char> >(SIDE, vector<char>(SIDE,empty));
	words = {};
}

Crossboard::Crossboard(vector<string> words){
	cells = vector<vector<char> >(SIDE, vector<char>(SIDE,empty));
	init(words);
}

void Crossboard::init(vector<string> words){
	vector<string> validWords;
	
	// Validating
	for(string word:words){
		if(validWords.size() >= 20){
			cout << "Error: Max capacity of words reached" << endl;
			break;
		}
		
		// A letter
		if(word.size() < 2){
			cout << "Invalid Word: '"<< word<< "' is just a single letter" << endl;
			continue;
		}
		
		if(word.size() > 15){
			cout << "Invalid Word: '"<< word<< "' is too long" << endl;
			continue;
		}
		
		// Contains illegal characters
		for(char& letter:word){
			if(!isalpha(letter)){
				cout << "Invalid Word: '"<< word << "' contains illegal characters" << endl;
				goto nope;
			}
			
			letter = toupper(letter);
		}

		validWords.push_back(word);	
		
		nope:;
	}
	
	sort(validWords.begin(),validWords.end(),compare);
	
	Error err = orderWords(validWords);
	cout << err.message << endl;
}

bool compare(string word1, string word2){
	if(word1.size() == word2.size()){
		return word1 < word2;
	}
	
	return word1.size() < word2.size();
}

Crossboard::~Crossboard(){
}

Error Crossboard::orderWords(vector<string> words){
	Error err = Error();
	err.success = false;
	
	// Put in the first word
	string longest = words.back();
	
	int col = SIDE/4;
	while(!err.success){
		err = addWord(longest,SIDE/2,col,across);
		col = col/2;
	}
	
	words.pop_back();
		
	// Put in the next words	
	while(words.size() > 0){
		err.success = false;
		int offset = -1;
		
		string word = words.back();
		words.pop_back();
		
					
		// Can this word even go anywhere
		bool found = false;
		
		for(char letter: word){
			for(vector<char> column: cells){
				if(find(column.begin(),column.end(),letter) != column.end()){
					found = true;
				}
			}
		}
		
		if(!found){
			cout << "Could not place " << word << endl;
			continue;
		}
		
		while(!err.success){
			err = attemptWord(word,offset);
			offset++;
			
			// Gotta rearrange
			if(offset > SIDE*SIDE){
				if((*this).words.size() == 1){
					string murder = words.back();
					words.pop_back();
					
					cout << "Could not place " << murder << endl;
					word = words.back();
					words.pop_back();
					offset = -1;
					
				}else{
					Word lastWord = (*this).words.back();
					Error what = removeWord(lastWord.row,lastWord.col,lastWord.pos);
				
					offset = lastWord.offset+1;
				
					words.push_back(word);
					word = lastWord.word;
				}	

			}
		}		
		
	}
	
	return err;
}

Error Crossboard::attemptWord(string word, int offset){
	Error err = Error();
	vector<int> coords = fitInBoard(word,offset);

	if(coords[0] == -1){
		err.error("No place to put word");
		return err;
	}

	Position position = (Position) coords[3];

	if(position == across){
		coords[1] = coords[1]-coords[2];
	}else{
		coords[0] = coords[0]-coords[2];
	}

	err = addWord(word,coords[0],coords[1],position, offset);
	
	return err;
}

vector<int> Crossboard::fitInBoard(string word, int ignore){
	vector<int> coords= {-1,-1, -1,-1}; // row and column of match, index in word, and position
	
	int match = 0;
	
	for(int row = 0; row < (int) cells.size(); row++){
		for(int col = 0; col < (int) cells[row].size(); col++){
			for(int letter = 0; letter < (int) word.size(); letter++){
				if(word[letter] == cells[row][col]){
					vector<Word> inWord = wordsAt(row,col);
					match++;
					if(match > ignore){		
						coords[0] = row;
						coords[1] = col;
						coords[2] = letter;
					
						if(inWord[0].pos == across){
							coords[3] = down;
						}else{
							coords[3] = across;						
						}
						
						goto out;
					}
				}	
			}
			
		}
	}		
	
	out:; 
	
	return coords;

}

Error Crossboard::addWord(string word, int row, int col, Position pos, int offset){
	Error err;
		
	for(Word dict: words){
		if(word == dict.word){
			err.error("Word already in dictionary");
			return err;
		}
	}
	
	Word newWord;
	newWord.word = word;
	newWord.row = row;
	newWord.col = col;
	newWord.pos = pos;
	newWord.offset = offset;

	err = placeWord(newWord);

	if(err.success){
		if(words.size() < 20){
			words.push_back(newWord);
		}else{
			err.error("Max capacity of words reached");
		}
	}

	
	return err;

}

Error Crossboard::placeWord(Word wordContainer){
	Error err;
	int offsetR = 0;
	int offsetC = 0;
	
	vector<Word> overlapping = {};

	string word = wordContainer.word; 
	int row = wordContainer.row;
	int col = wordContainer.col; 
	Position pos = wordContainer.pos;

	// Check validity
	if(row < SIDE && row >= 0 && col < SIDE && col >= 0){
		switch(pos){
			case down:
				if(row + word.size() <= SIDE){
					offsetR = 1;
				}else{
					err.error("Word too long");
					return err;
				}
				break;
			case across:
				if(col + word.size() <= SIDE){
					offsetC = 1;
				}else{
					err.error("Word too long");
					return err;
				}
				break;
			default:
				err.error("get out");
				return err;
		}
	}else{
		err.error("Invalid coordinates");
		return err;
	}
	
	// Check if overlaps
	for(int i = 0; i < (int) word.size(); i++){
		int offRow = row+(offsetR*i);
		int offCol = col+(offsetC*i);
	
		if(cells[offRow][offCol] == empty || cells[offRow][offCol] == word[i]){
			if(cells[offRow][offCol] == word[i]){
				for(Word adjWord:wordsAt(offRow,offCol)){
					if(adjWord.pos == pos){
						err.error("Invalid Location: Makes a long letter");
						return err;
					}
					
					overlapping.push_back(adjWord);
				}				

			}
			continue;
		}else{
			err.error("Letter overlap");
			return err;
		}
	}
	
	
	// Check if it's adjacent to something
	for(int i = 0; i < (int) word.size(); i++){
		int offRow = row+(offsetR*i);
		int offCol = col+(offsetC*i);
		
		for(int aRow = offRow-1; aRow <= offRow+1; aRow++){
			if(aRow < 0 || aRow >= SIDE) continue;
	
			for(int aCol = col-1; aCol <= offCol+1; aCol++){	
				if(aCol < 0 || aCol >= SIDE || (aCol == offCol && aRow == offRow)) continue;
				
				if(cells[aRow][aCol] != empty){	
					for(Word adjWord:wordsAt(aRow,aCol)){
						
						if(find(overlapping.begin(),overlapping.end(),adjWord) == overlapping.end()){
							err.error("Letter overlap");
							return err;
						}
					}
				}				
			}
		}
	}
	
	for(int i = 0; i < (int) word.size(); i++){
		int offRow = row+(offsetR*i);
		int offCol = col+(offsetC*i);
		
		cells[offRow][offCol] = word[i];
	}

	return err;
}

Error Crossboard::removeWord(int row, int col, Position pos){
	vector<Word> killWords = wordsAt(row,col);
	Word killWord;
	Error err;
	
	for(Word word:killWords){
		if(word.pos == pos){
			killWord = word;
		}
	}
	
	if(killWords.size() == 0){
		err.error("No words at location");
		return err;
	}

	
	if(killWord.pos == across){
		for(int offset = 0; offset < (int) killWord.word.size(); offset++){
			if(killWord.row - 1 < 0){
				if(killWord.row + 1 >= SIDE){
					cells[killWord.row][killWord.col+offset] = empty;
				}else{
					if(cells[killWord.row+1][killWord.col+offset] == empty){
						cells[killWord.row][killWord.col+offset] = empty;
					}
				}
			}else{
				if(cells[killWord.row-1][killWord.col+offset] == empty){
					if(killWord.row + 1 >= SIDE){
						cells[killWord.row][killWord.col+offset] = empty;
					}else{
						if(cells[killWord.row+1][killWord.col+offset] == empty){
							cells[killWord.row][killWord.col+offset] = empty;
						}
					}
				}
			}
		}
	}else{
		for(int offset = 0; offset < (int) killWord.word.size(); offset++){
			if(killWord.col - 1 < 0){
				if(killWord.col + 1 > SIDE){
					cells[killWord.row+offset][killWord.col] = empty;
				}
			}else{
				if(cells[killWord.row+offset][killWord.col-1] == empty){
					if(killWord.col + 1 > SIDE){
						cells[killWord.row+offset][killWord.col] = empty;
					}else{
						if(cells[killWord.row+offset][killWord.col+1] == empty){
							cells[killWord.row+offset][killWord.col] = empty;
						}
					}
				}
			}
		}	
	}
	
	for(auto i = words.begin(); i<words.end(); i++){
		if(*i == killWord){
			words.erase(i);
		}
	}

	return err;
}

vector<Word> Crossboard::wordsAt(int row, int col){
	vector<Word> wordAtPosition;
	int startRow = -1;
	int startCol = -1;
	
	// Try if it's down
	int offsetR = 0;

	while(cells[row - offsetR][col] != empty){
		offsetR++;
		
		if(row-offsetR < 0){
			break;
		}
		
		if(row - offsetR == 0){
			if(cells[row-offsetR][col] != empty){
				offsetR++;
			}
			
			break;
		}
	}

	offsetR--;

	startRow = row - offsetR;
	startCol = col;
	
	for(Word word:words){
		if(word.row == startRow && word.col == startCol && word.pos == down){
			wordAtPosition.push_back(word);
			break;
		}
	}
	
	// Try if it's across
	startRow = -1;
	startCol = -1;
	int offsetC = 0;
	
	while(cells[row][col-offsetC] != empty){
		offsetC++;
		
		if(col-offsetC < 0){
			break;
		}
		
		if(col - offsetC == 0){
			if(cells[row][col-offsetC] != empty){
				offsetC++;
			}
			break;
		}
	}
	
	offsetC--;
	
	startRow = row;
	startCol = col - offsetC;	
	
	for(Word word:words){
		if(word.row == startRow && word.col == startCol && word.pos == across){
			wordAtPosition.push_back(word);
			break;
		}
	}

	return wordAtPosition;
}

void Crossboard::displaySolution(string filename){
	ostream* output;
	ofstream ofs;	
	
	if(filename != ""){
		ofs.open(filename);
		output = &ofs;
	}else{
		output = &cout;
	}
	
	(*output) << "Solution: " << endl;
	// header
	for(int i = 0; i <= SIDE; i++){
		(*output) << "-";
	}
	(*output) << endl;
	
	for(vector<char> row: cells){
		(*output) << "|";
		for(char cell: row){
			(*output) << cell;
		}
		(*output) << "|" << endl;
	}
	
	// footer
	for(int i = 0; i <= SIDE; i++){
		(*output) << "-";
	}
	(*output) << endl << endl;
}

void Crossboard::displayPuzzle(string filename){
	ostream* output;
	ofstream ofs;	
	
	if(filename != ""){
		ofs.open(filename,ios_base::app);
		output = &ofs;
	}else{
		output = &cout;
	}
	
	// header
	(*output) << "Crossword puzzle: " << endl;
	for(int i = 0; i <= SIDE; i++){
		(*output) << "-";
	}
	(*output) << endl;
	
	for(vector<char> row: cells){
		(*output) << "|";
		for(char cell: row){
			if(cell == '.'){
				(*output) << '#';
			}else if(isalpha(cell)){
				(*output) << " ";
			}else{
				(*output) << "How did you get here????";
			}
		}
		(*output) << "|" << endl;
	}
	
	// footer
	for(int i = 0; i <= SIDE; i++){
		(*output) << "-";
	}
	(*output) << endl << endl;
}

void Crossboard::displayClues(string filename){
	ostream* output;
	ofstream ofs;	
	
	if(filename != ""){
		ofs.open(filename,ios_base::app);
		output = &ofs;
	}else{
		output = &cout;
	}
	
	// header
	(*output) << "Clues: " << endl << endl;
	
	for(Word word:words){
		(*output) << setw(2) << word.col << "," << setw(2) << word.row << left << setw(6);
		
		switch(word.pos){
			case across:
				(*output) << " Across ";
				break;
			case down:
				(*output) << " Down   ";
				break;
			default:
				cout << "This is bad";
		}
	
		string shuffled = word.word;
		while(shuffled == word.word){
			unsigned seed = chrono::system_clock::now().time_since_epoch().count();
			shuffle(shuffled.begin(),shuffled.end(),default_random_engine(seed));
		}
		
		(*output) << right << shuffled << endl;
	}
	
	(*output) << endl;
}

void Crossboard::display(string filename){
	displaySolution(filename);
	displayPuzzle(filename);
	displayClues(filename);
}