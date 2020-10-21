#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


int main() {
	int			x, y;
	string		s;
	ifstream	input("input.txt");

	input >> y >> x;
	input.ignore(1);
	while (y-- > 0) {
		for (int i = 0; i < x; i++) {
			if (i)
				cout << " ";
			if (i == x - 1)
				getline(input, s);
			else
				getline(input, s, ',');
			cout << setw(10) << s;
		}
		if (y)
			cout << endl;
	}
	return (0);
}