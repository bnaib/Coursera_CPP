#include <iostream>
#include <vector>
using namespace std;


int		main(void) {
	uint64_t		r;
	uint16_t		w, h ,d;
	uint32_t		n;
	uint64_t		sum = 0;

	cin >> n >> r;
	while (n-- > 0) {
		cin >> w >> h >> d;
		sum += r * w * h * d;
	}
	cout << sum << endl;
	return (0);
}
