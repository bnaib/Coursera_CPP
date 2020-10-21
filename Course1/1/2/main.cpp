#include <iostream>
#include <string>
using namespace std;

int main()
{
	string	s[3];
	int		k = 0;

	for (int i = 0; i < 3; i++)
		cin >> s[i];
	for (int i = 1; i < 3; i++) {
		if (s[i] < s[k])
			k = i;
	}
	cout << s[k];
	return (0);
}