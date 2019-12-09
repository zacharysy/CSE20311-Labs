// Zachary Sy
// Othello prototype 

#include <vector>
#include <string>
using namespace std;

const int BOARD_SIZE = 8;
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';

enum State{ empty, p1, p2 };

class Board{
	public:
		Board();
		~Board();
		
		bool anyValidMoves(int player);
		bool addPiece(int y, int x, int player);
		bool isFilled();
		void display(bool done = false);
		vector<int> tally();
		
		int getTurn();
		void setErrorMessage(string message);
		void incrementTurn();
		
		// Helper Functions
		bool flippable(int prow, int pcol, int row, int col, int player);
		bool isValid(int row, int col, int player, bool isMove=true);
		
		
	private:
		vector< vector<int> > cells; // cells[x][y]
		int turn;
		string errorMessage = "";
};