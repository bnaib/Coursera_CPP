#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int				n;
	int				val;
	vector<int>		v;
	bool			first = true;

	cin >> n;
	while (n-- > 0) {
		cin >> val;
		v.push_back(val);
	}
	sort(begin(v), end(v), [](int x1, int x2){return (abs(x1) < abs(x2));});
	for (const auto& el : v) {
		if (first)
			first = false;
		else
			cout << " ";
		cout << el;
	}
	return (0);
}