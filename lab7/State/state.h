// Zachary Sy
// State.h

using namespace std;

class State{
	public:
		State();
		State(string, string, string, int, int, int);
		~State();
		
		string getAbbv();
		string getName();
		string getCapital();
		int getPopulation();
		int getRepCount();
		int getFoundYear();
		
		void setAbbv(string);
		void setName(string);
		void setCapital(string);
		void setPopulation(int);
		void setRepCount(int); 
		void setFoundYear(int);
		
		void info(bool concise = false);
	private:
		string abbv;
		string name;
		string capital;
		int pop;
		int foundYear;
		int repCount;
};

// Startup 
vector<State> startup(string);

//Menu
bool menu(vector<State> &states);

//Options
void searchState(vector<State> states, string keyword);
void stateInfo(vector<State> states,string abbv);
void mostPop(vector<State> states);
void oldest(vector<State> states);