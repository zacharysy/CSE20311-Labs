#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
	int a,b;
	
	switch(argc){
		case 3: // Two numbers given
			a = atoi(argv[1]);
			b = atoi(argv[2]);
			break;
		case 2:
			cout << "ERROR: Too Few Arguments" << endl;
			return 1;
			break;
		case 1:
			cout << "Please Enter Two Numbers: ";
			cin >> a >> b;
			cout << endl;
			break;
		default:
			cout << "ERROR: Too Many Arguments" << endl;
			return 2;
			
	}
	
	cout << a << " + " << b << " = " << a + b << endl;
	
	
	return 0;

}