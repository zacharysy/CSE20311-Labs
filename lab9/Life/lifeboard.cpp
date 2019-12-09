// Zachary Sy
// Lifeboard class 

#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
#include <cstdlib>
using namespace std;

#include "lifeboard.h"

const int SIDE = 40;

Lifeboard::Lifeboard(){
	cells = vector<vector<bool> >(SIDE, vector<bool>(SIDE,false));
	generation = 1;
}

Lifeboard::~Lifeboard(){
}

void Lifeboard::addCell(int x, int y){
	if(x < SIDE && x >= 0 && y < SIDE && y >= 0){
		cells[x][y] = true;
	}else{
		cout << "Invalid coordinates" << endl;
	}
	
}

void Lifeboard::removeCell(int x, int y){
	if(x < SIDE && x >= 0 && y < SIDE && y >= 0){
		cells[x][y] = false;
	}else{
		cout << "Invalid coordinates" << endl;
	}
}

void Lifeboard::advance(){
	vector<int> deadOrAlive;
	vector<vector<bool>> newCells;
	
	newCells = cells;
	generation++;
	
	for(int row = 0; row < cells.size(); row++){
		for(int col = 0; col < cells[row].size(); col++){
			deadOrAlive = checkAdjacents(row,col); // 0 is dead, 1 is alive
			
			if(cells[row][col]){ // Alive
				// Death
				if(deadOrAlive[1] < 2 || deadOrAlive[1] > 3){ 
					newCells[row][col] = false;
				}
			}else{ // Dead
				if(deadOrAlive[1] == 3){
					newCells[row][col] = true;
				}
			}
			
			
		}

	}	
	cells = newCells;
}

vector<int> Lifeboard::checkAdjacents(int row, int col){	
	int alive = 0;
	int dead = 0;
	
	for(int aRow = row-1; aRow <= row+1; aRow++){
		if(aRow < 0 || aRow >= SIDE) continue;
		
		for(int aCol = col-1; aCol <= col+1; aCol++){	
			if(aCol < 0 || aCol >= SIDE || (aCol == col && aRow == row)) continue;
			
			if(cells[aRow][aCol]){
				alive++;
			}else{
				dead++;
			}				
		}
	}
	
	vector<int> deadOrAlive;
	deadOrAlive.push_back(dead);
	deadOrAlive.push_back(alive);
	
	return deadOrAlive;
}

void Lifeboard::display(){
	system("clear");
	// header
	cout << "Generation: " << generation << endl;
	for(int i = 0; i <= SIDE; i++){
		cout << "-";
	}
	cout << endl;
	
	for(vector<bool> row: cells){
		cout << "|";
		for(bool cell: row){
			if(cell){
				cout << "X";
			}else{
				cout << " ";
			}
		}
		cout << "|" << endl;
	}
	
	// footer
	for(int i = 0; i <= SIDE; i++){
		cout << "-";
	}
	cout << endl;
}