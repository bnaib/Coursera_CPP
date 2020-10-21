#include <iostream>
using namespace std;

int main() {
	int	i[2];

	cin >> i[0] >> i[1];
	if (i[1] == 0)
		cout << "Impossible";
	else
		cout << i[0] / i[1];
	return (0);
}