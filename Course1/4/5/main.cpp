#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string		line;
	ifstream	input("input.txt");
	ofstream	output("output.txt");

	if (input) {
		while (getline(input, line))
			output << line << endl;
	}
	return (0);
}