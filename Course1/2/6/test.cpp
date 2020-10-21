#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "reverse.cpp"

int main(int argc, char **argv) {
	vector<int> v = {1, 2, 3, 4, 5, 6, 7};

	Reverse(v);

	for (int i : v)
		cout << i << endl;
	return  (0);
}