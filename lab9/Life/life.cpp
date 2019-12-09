// Zachary Sy
// Life main

#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <fstream>

#include "lifeboard.h"

using namespace std;

void import(string filename, Lifeboard&);
bool ask(Lifeboard&);
int command(Lifeboard& board, char move, bool manual=true, int x=-1, int y=-1);
void forever(Lifeboard&);

int main(int argc, char *argv[]){	
	Lifeboard board = Lifeboard();
	
	board.display();
	
	if(argc == 2){
		// Batch Mode
		import(argv[1], board);
	}else if(argc == 1){
		// Interactive Mode
		while(ask(board)) continue;
	}else{
		cout << "ERROR: Too Many Arguments" << endl;
		return 1;
	}
	
	return 0;
}

void import(string filename, Lifeboard& board){
	ifstream file(filename);
	char move;
	int x = 100;
	int y = 100;
	
	if(file.is_open()){
		while(file){
			file >> move;
		
			if(move == 'a' || move == 'r'){
				file >> x >> y;
			}
		
			command(board, move, false, x ,y);
		}
	}else{
		cout << "Invalid Filename" << endl;
	}
}

bool ask(Lifeboard& board){
	char move;
	cout << "a: add cell; r: remove cell" << endl;
	cout << "n: advance; p: continuous play; q: quit" << endl << endl;
	cout << "> ";
	cin >> move;
	
	int success = command(board, move);
	switch(success){
		case 0:
		case 1:
			return success;
		case 2: //Error
			cout << "ERROR: Unknown Command" << endl;
			return true;
	}
}
int command(Lifeboard& board, char move, bool manual, int x, int y){
	switch(move){
		case 'a':
			if(manual){
				cout << "Enter x,y coordinates: ";
				cin >> x >> y;			
			}

			board.addCell(x,y);
			break;
		case 'r':
			if(manual){
				cout << "Enter x,y coordinates: ";
				cin >> x >> y;			
			}
			board.removeCell(x,y);
			break;
		case 'n':
			board.advance();
			break;
		case 'p':
			forever(board);
			break;
		case 'q':
			return 0;
		default:
			return 2;
	}
	
	board.display();
	
	return 1;

}

void forever(Lifeboard& board){
	while(true){
		board.display();
		usleep(15000);
		board.advance();
		usleep(15000);
	}
}