#include <iostream>
#include <string>
using namespace std;

int main() {
	string 	str;
	int		i = 0;
	int		f = 0;

	cin >> str;
	for (auto s : str) {
		if (s == 'f' && ++f == 2) {
			cout << i;
			return (0);
		}
		i++;
	}
	if (f == 1)
		cout << -1;
	else
		cout << -2;
	return (0);
}