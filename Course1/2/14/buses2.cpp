#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string>	read_stops() {
	vector<string>	v;
	int				n;
	string			str;

	cin >> n;
	while (n-- > 0) {
		cin >> str;
		v.push_back(str);
	}
	return (v);
}

int main(){
	map<vector<string>, int>	m;
	int							n;
	vector<string>				v;
	int							i = 0;
	vector<string>				out;

	cin >> n;
	while (n-- > 0) {
		v = read_stops();
		if (m.count(v) == 0) {
			m[v] = ++i;
			out.push_back("New bus " + to_string(i));
		} else
			out.push_back("Already exists for " + to_string(m[v]));
	}
	for (const string& s : out)
		cout << s << endl;
	return (0);
}