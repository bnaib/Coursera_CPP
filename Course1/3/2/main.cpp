#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string	str_tolower(string str) {
	for (auto& c : str)
		c = tolower(c);
	return (str);
}

int main() {
	int				n;
	string			val;
	vector<string>	v;
	bool			first = true;

	cin >> n;
	while (n-- > 0) {
		cin >> val;
		v.push_back(val);
	}
	sort(begin(v), end(v), [](string x1, string x2){
		return (str_tolower(x1) < str_tolower(x2));});
	for (const auto& el : v) {
		if (first)
			first = false;
		else
			cout << " ";
		cout << el;
	}
	return (0);
}