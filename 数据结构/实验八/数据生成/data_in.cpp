#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>

using namespace std;

string trans(int);

int main() {
	ofstream output;
	int x;
	cin >> x;
	srand((unsigned)time(NULL));
	output.open("data.txt", ios::trunc);
	
	for(int i = 0; i < x; ++i) {
		output << rand() << ' ';
	}
		
	return 0;
}
