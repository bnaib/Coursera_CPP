#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
using namespace std;

void	ADD(map<string, set<string>>& m) {
	string				str[2];

	cin >> str[0] >> str[1];
	m[str[0]].insert(str[1]);
	m[str[1]].insert(str[0]);
}

void	COUNT(map<string, set<string>>& m, vector<string>& out) {
	string	str;

	cin >> str;
	out.push_back(to_string(m[str].size()));
}

void	CHECK(map<string, set<string>>& m, vector<string>& out) {
	string	str[2];

	cin >> str[0] >> str[1];
	if (m.count(str[0]) == 0 || m[str[0]].count(str[1]) == 0)
		out.push_back("NO");
	else
		out.push_back("YES");
}

int main() {
	map<string, set<string>> m;
	int					n;
	string				str;
	vector<string>		out;

	cin >> n;
	while (n-- > 0) {
		cin >> str;
		if (str == "ADD")
			ADD(m);
		else if (str == "COUNT")
			COUNT(m, out);
		else
			CHECK(m, out);
	}
	for (const string& s : out)
		cout << s << endl;
	return (0);
}