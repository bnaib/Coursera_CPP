#include <iostream>
using namespace std;

int main() {
	int 	i[2];
	bool	f = true;

	cin >> i[0] >> i[1];
	while (i[0] <= i[1]) {
		if (i[0] % 2 == 0) {
			if (f)
				f = false;
			else
				cout << " ";
			cout << i[0];
		}
		i[0]++;
	}
	return (0);
}