#include <iostream>
#include <string>
#include <set>
using namespace std;

int		main() {
	set<string>		s;
	int				n;
	string			str;

	cin >> n;
	while (n-- > 0) {
		cin >> str;
		s.insert(str);
	}
	cout << s.size();
	return (0);
}