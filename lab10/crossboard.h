// Zachary Sy
// board prototype 

#include <vector>
#include <string>
#include <fstream>
using namespace std;

const int SIDE = 15;
enum Position{down, across, none};
const char empty = '.';

struct Error{
	bool success = true;
	string message = "";
	
	void error(string message){
		(*this).success = false;
		(*this).message = message;
	}
};

struct Word{
	string word;
	int row = -1;
	int col = -1;
	Position pos = none;
	int offset = -1;
		
	bool operator==(Word w){
		return word == w.word;
	}

};

bool compare(string word1, string word2);

class Crossboard{
	public:
		Crossboard();
		Crossboard(vector<string> words);
		~Crossboard();
		
		void init(vector<string> words);

		Error attemptWord(string word, int offset);		
		vector<int> fitInBoard(string word, int ignore);
		Error orderWords(vector<string>);
		Error addWord(string word, int row, int col, Position pos=none, int offset=-1);
		Error removeWord(int row, int col, Position pos);
		Error placeWord(Word);

		
		void displaySolution(string filename = "");
		void displayPuzzle(string filename = "");
		void displayClues(string filename = "");
		
		void display(string filename = "");
		
		// Helper Functions
		vector<Word> wordsAt(int row, int col);

		
	private:
		vector< vector<char> > cells; // cells[row][col]
		vector<Word> words;
};