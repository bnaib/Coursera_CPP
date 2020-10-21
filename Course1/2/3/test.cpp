#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "PalindromFilter.cpp"

int main(int argc, char **argv) {
	vector<string> v = {"weew", "bro", "code"};
	vector<string> r = PalindromFilter(v, 4);

	for (string s : r)
		cout << s << endl;
	return  (0);
}