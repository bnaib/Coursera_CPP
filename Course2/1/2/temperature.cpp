#include <iostream>
#include <vector>
using namespace std;

vector<size_t> get_bifer_am(vector<int32_t>& v) {
	int64_t			am = 0;
	vector<size_t>	r;
	size_t			i = 0;

	for (auto el : v)
		am += el;
	am /= static_cast<int64_t>(v.size());
	for (auto el : v) {
		if (el > am)
			r.push_back(i);
		i++;
	}
	return (r);
}

int main() {
	vector<int32_t>	v;
	vector<size_t>	r;
	int32_t			n;
	int32_t			i;
	bool			f = true;


	cin >> n;
	while (n-- > 0) {
		cin >> i;
		v.push_back(i);
	}
	r = get_bifer_am(v);
	cout << r.size() << endl;
	for (auto k : r) {
		if (f)
			f = false;
		else
			cout << " ";
		cout << k;
	}
	return (0);
}
