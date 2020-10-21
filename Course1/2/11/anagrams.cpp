#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


map<char, int>	BuildCharCounters(const string& str) {
	map<char, int> m;

	for (char c : str)
		++m[c];
	return (m);
}

int		main() {
	vector<string>	out;
	int				n;
	string			str[2];

	cin >> n;
	while(n-- > 0) {
		cin >> str[0] >> str[1];
		out.push_back(
			BuildCharCounters(str[0]) == BuildCharCounters(str[1]) ?
			"YES" : "NO"
		);
	}
	for (string s : out)
		cout << s << endl;
	return (0);
}