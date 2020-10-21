#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "reversed.cpp"

int main(int argc, char **argv) {
	vector<int> v = {1, 2, 3};

	vector<int> r = Reversed(v);

	for (int i : r)
		cout << i << endl;
	return  (0);
}