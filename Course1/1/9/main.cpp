#include <iostream>
#include <vector>
using namespace std;

int main() {
	int			i;
	vector<int> v;

	cin >> i;
	if (i == 0) {
		cout << 0;
		return (0);
	}
	while (i > 0) {
		v.insert(v.begin(), i & 1);
		i >>= 1;
	}
	for (auto k : v)
		cout << k; 
	return (0);
}