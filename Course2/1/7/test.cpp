#include <iostream>
#include <map>

using namespace std;

#include "element_reference.cpp"

int main() {
	map<int, string> m = {{0, "value"}};
	string& item = GetRefStrict(m, 0);
	item = "newvalue";
	cout << m[0] << endl;
	item = GetRefStrict(m, 2);
	return (0);
}