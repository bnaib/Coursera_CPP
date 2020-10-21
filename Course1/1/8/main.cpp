#include <iostream>
#include <string>
using namespace std;

int main() {
	int	i[2];

	cin >> i[0] >> i[1];
	while (i[0] % i[1] != 0 && i[1] % i[0] != 0) {
		if (i[0] > i[1])
			i[0] = i[0] % i[1];
		else
			i[1] = i[1] % i[0];
	}
	cout << ((i[0] < i[1]) ? i[0] : i[1]); 
	return (0);
}