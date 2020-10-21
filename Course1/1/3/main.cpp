#include <iostream>
using namespace std;

int main() {
	double a, b, c, x1, x2, d;

	cin >> a >> b >> c;

	if (a == 0) {
		if (b != 0)
			cout << -c / b;
	} else {
		d = b * b - 4 * a * c;
		if (d >= 0)
		{
			d = sqrt(d);
			x1 = (-b + d) / (2 * a);
			x2 = (-b - d) / (2 * a);
			cout << x1;
			if (x1 != x2)
				cout << " " << x2;
		}
	}
	return (0);
}