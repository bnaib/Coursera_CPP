#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	double		line;
	ifstream	input("input.txt");

	if (input) {
		cout << fixed << setprecision(3);
		while (!input.eof()) {
			input >> line;
			cout << line << endl;
		}
	}
	return (0);
}