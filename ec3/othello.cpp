// Zachary Sy
// Life main

#include <iostream>
#include <vector>
#include <string>

#include "board.h"

using namespace std;

/*
void import(string filename, Lifeboard&);
bool ask(Lifeboard&);
int command(Lifeboard& board, char move, bool manual=true, int x=-1, int y=-1);
void forever(Lifeboard&);
*/

int main(int argc, char *argv[]){	
	Board board = Board();
	int col,row,player;
	string none; 
	
	while(!board.isFilled()){
		if(board.getTurn() % 2){
			player = p1;
		}else{
			player = p2;
		}
	
		if(!board.anyValidMoves(player)){
			board.setErrorMessage("No Valid Moves, Lose a Turn (press enter to continue)\n");	
			board.display();
			
			getline(cin,none);
			cin.ignore();			

			board.incrementTurn();
			continue;
		}
		
		board.display();
		cin >> col >> row;
		board.addPiece(col,row,player);		
		
	}

	board.display(true);
	
	vector<int> tally = board.tally();

	cout << endl << "No More Moves" << endl;
	cout << endl;
	
	if(tally[p1] == tally[p2]){
		cout << "It's a Tie!" << endl;
		return 0;
	}
	
	if(tally[p1] > tally[p2]){
		cout << "Player 1 ";
	}else{
		cout << "Player 2 ";
	}
	
	cout << " Wins!" << endl;

	return 0;
}