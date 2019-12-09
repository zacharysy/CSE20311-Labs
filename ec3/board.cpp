// Zachary Sy
// Othelle board class 

#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
#include <cstdlib>
using namespace std;

#include "board.h"

Board::Board(){
	cells = vector<vector<int> >(BOARD_SIZE, vector<int>(BOARD_SIZE,0));
	
	// Initialize the middle
	cells[BOARD_SIZE/2][BOARD_SIZE/2] = p1;
	cells[(BOARD_SIZE/2)-1][BOARD_SIZE/2] = p2;
	cells[(BOARD_SIZE/2)-1][(BOARD_SIZE/2)-1] = p1;
	cells[(BOARD_SIZE/2)][(BOARD_SIZE/2)-1] = p2;
	
	turn = 1;
}

Board::~Board(){
}

int Board::getTurn(){
	return turn;
}

void Board::incrementTurn(){
	turn++;
}

void Board::setErrorMessage(string message){
	errorMessage = message;
}

bool Board::addPiece(int y, int x, int player){
	if(x < BOARD_SIZE && x >= 0 && y < BOARD_SIZE && y >= 0){		
		if(isValid(x,y,player)){	
			turn++;
			return true;
		}
	}else{
		errorMessage = "Invalid Move: Coordinates out of bounds\n";
	}
	
	return false;
	
}

bool Board::isValid(int row, int col, int player, bool isMove){	
	// Check if cell is empty
	if(cells[row][col] != empty){
		if(isMove){
			errorMessage = "Invalid Move: There is a piece already there\n";		
		}
		
		return false;
	}
	
	cells[row][col] = player;
			
	// Check if cell is adjacent
	bool isAdjacent = false;
	
	for(int aRow = row-1; aRow <= row+1; aRow++){
		if(aRow < 0 || aRow >= BOARD_SIZE) continue;
		
		for(int aCol = col-1; aCol <= col+1; aCol++){	
			if(aCol < 0 || aCol >= BOARD_SIZE || (aCol == col && aRow == row)) continue;
			
			if(cells[aRow][aCol] != empty){
				isAdjacent = true;
				goto out;
			}
		}
	}
	
	out:
	if(!isAdjacent){
		cells[row][col] = empty;
		
		if(isMove){
			errorMessage = "Invalid Move: No adjacent pieces\n";
		}
		
		return false;
	}
	
	// Check if cell flips
	int flips = 0;
	
	for(int aRow = row-1; aRow <= row+1; aRow++){
		if(aRow < 0 || aRow >= BOARD_SIZE) continue;
		
		for(int aCol = col-1; aCol <= col+1; aCol++){	
			if(aCol < 0 || aCol >= BOARD_SIZE || (aCol == col && aRow == row)) continue;
			
			if(cells[aRow][aCol] != empty && cells[aRow][aCol] != player){
				if(flippable(row,col,aRow,aCol,player)){
					flips++;
					
					if(isMove){
						int offsetR = aRow-row;	
						int offsetC = aCol-col;
						int currR = aRow;
						int currC = aCol;
	
						while(cells[currR][currC] != player){
							cells[currR][currC] = player;
							currR += offsetR;
							currC += offsetC;
						}
					}
				}
			}
		}
	}
	
	if(flips == 0){
		cells[row][col] = empty;
		
		if(isMove){
			errorMessage = "Invalid Move: No pieces were captured\n";
		}
		
		return false;
	}
	
	return true;
}

// Row and column of the piece to flip and player who is flipping to
bool Board::flippable(int prow, int pcol, int row, int col, int player){		
	int opponent;
	
	if(player == p1){
		opponent = p2;
	}else{
		opponent = p1;
	}
	
	int offsetR = row-prow;	
	int offsetC = col-pcol;

	
	int currR = row;
	int currC = col;
	
	while(cells[currR][currC] == opponent){
		currR += offsetR;
		currC += offsetC;
		
		if(currC < 0 || currC >= BOARD_SIZE || currR < 0 || currR >= BOARD_SIZE) return false;	
	}
	
	if(cells[currR][currC] == player){
		return true;
	}
	
	return false;	
}

bool Board::anyValidMoves(int player){	
	for(int row = 0; row < cells.size(); row++){
		for(int col = 0; col < cells[row].size(); col++){
			if(cells[row][col] == empty){
				if(isValid(row,col,player,false)){
					cells[row][col] = empty;
					return true;
				}else{
					cells[row][col] = empty;
				}
			}
		}
	}	
	
	return false;
}

bool Board::isFilled(){	
	int emptyCount = 0;
	
	for(int row = 0; row < cells.size(); row++){
		for(int col = 0; col < cells[row].size(); col++){
			if(cells[row][col] == empty){
				emptyCount++;
			}
		}
	}
	
	if(emptyCount == 0){
		return true;
	}
	
	if(!anyValidMoves(p1) && !anyValidMoves(p2)){
		return true;
	}
	
	return false;
}

vector<int> Board::tally(){
	vector<int> tally = {0,0,0};
	
	for(int row = 0; row < cells.size(); row++){
		for(int col = 0; col < cells[row].size(); col++){
			if(cells[row][col] == p1){
				tally[p1]++;
			}else if(cells[row][col] == p2){
				tally[p2]++;
			}
		}
	}
	return tally;
}

void Board::display(bool done){
	system("clear");
	// header
	
	vector<int> tally = (*this).tally();
	
	cout << "Turn " << turn << endl;
	cout << PLAYER1 << ": "  << tally[p1] << " " << PLAYER2 << ": " << tally[p2] << endl;
	cout << endl << " ";	
		
	for(int i = 0; i < BOARD_SIZE; i++){
		cout << " " << i;
	}
	cout << endl;
	
	int rowNum = 0;
	
	for(vector<int> row: cells){
		cout << rowNum << " ";
		rowNum++;
		
		for(int cell: row){
			switch(cell){
				case empty:
					cout << ".";
					break;
				case p1:
					cout << PLAYER1;
					break;
				case p2:
					cout << PLAYER2;
					break;
				default:
					cout << "how did you get here?????" << endl;
			}
			cout << " ";
		}
		cout << endl;
	}

	if(!done){	
		// "Console"
		cout << endl;
		
		if(errorMessage != ""){
			cout << errorMessage;
			errorMessage = "";
		}
	
		cout << errorMessage;
	
		if(turn%2){
			cout << "P1 (" << PLAYER1 << ") ";
		}else{
			cout << "P2 (" << PLAYER2 << ") ";
		}
		
		cout << "> ";
	}
	

}