#include <iostream>
using namespace std;

int main() {
	double n, a, b, x, y;

	cin >> n >> a >> b >> x >> y;
	cout << ((n > b) ? n - n * y / 100 :
		((n > a) ? n - n * x / 100 : n));
	return (0);
}