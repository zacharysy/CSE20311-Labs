// Zachary Sy
// Lifeboard prototype 

#include <vector>
using namespace std;

class Lifeboard{
	public:
		Lifeboard();
		~Lifeboard();
		
		void addCell(int x, int y);
		void removeCell(int x, int y);
		void advance();
		void display();
		
		// Helper Functions
		vector<int> checkAdjacents(int row, int col);
		
		
	private:
		vector< vector<bool> > cells; // cells[x][y]
		int generation;
};