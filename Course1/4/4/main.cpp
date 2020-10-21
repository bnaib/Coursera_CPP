#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string		line;
	ifstream	input("input.txt");

	if (input) {
		while (getline(input, line))
			cout << line << endl;
	}
	return (0);
}