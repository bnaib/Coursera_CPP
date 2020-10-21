#include <vector>

vector<int> Reversed(const vector<int>& v) {
	vector<int> r;
	
	for (int i : v)
		r.insert(r.begin(), i);
	return (r);
}