#include <iostream>
#include <vector>
using namespace std;

vector<int> get_bifer_am(vector<int>& v) {
	int			am = 0;
	vector<int>	r;
	int			i = 0;

	for (int el : v)
		am += el;
	am /= v.size();
	for (int el : v) {
		if (el > am)
			r.push_back(i);
		i++;
	}
	return (r);
}

int main() {
	vector<int> v[2];
	int			n;
	int			i;
	bool		f = true;


	cin >> n;
	while (n-- > 0) {
		cin >> i;
		v[0].push_back(i);
	}
	v[1] = get_bifer_am(v[0]);
	cout << v[1].size() << endl;
	for (int k : v[1]) {
		if (f)
			f = false;
		else
			cout << " ";
		cout << k;
	}
	return (0);
}