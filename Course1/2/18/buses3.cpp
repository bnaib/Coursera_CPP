#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

set<string>	read_stops() {
	set<string>		s;
	int				n;
	string			str;

	cin >> n;
	while (n-- > 0) {
		cin >> str;
		s.insert(str);
	}
	return (s);
}

int main(){
	map<set<string>, int>	m;
	int						n;
	set<string>				s;
	int						i = 0;
	vector<string>			out;

	cin >> n;
	while (n-- > 0) {
		s = read_stops();
		if (m.count(s) == 0) {
			m[s] = ++i;
			out.push_back("New bus " + to_string(i));
		} else
			out.push_back("Already exists for " + to_string(m[s]));
	}
	for (const string& s : out)
		cout << s << endl;
	return (0);
}