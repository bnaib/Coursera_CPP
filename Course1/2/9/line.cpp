#include <iostream>
#include <vector>
using namespace std;


int main() {
	int				q;
	vector<bool>	v;
	string			str;
	int				i;
	vector<int>		r;

	cin >> q;
	while (q-- > 0) {
		cin >> str;
		if (str == "WORRY_COUNT") {
			i = 0;
			for (bool b : v) {
				if (b)
					i++;
			}
			r.push_back(i);
			continue ;
		}
		cin >> i;
		if (str == "WORRY")
			v[i] = true;
		if (str == "QUIET")
			v[i] = false;
		if (str == "COME")
			v.resize(v.size() + i, false);
	}

	for (int k : r)
		cout << k << endl;
	return (0);
}

