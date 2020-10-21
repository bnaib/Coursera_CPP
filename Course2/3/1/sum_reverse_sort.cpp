#include "sum_reverse_sort.h"
#include <algorithm>

int		Sum(int x, int y) {
	return (x + y);
}

string	Reverse(string s) {
	string r = s;

	reverse(r.begin(), r.end());
	return (r);
}

void	Sort(vector<int>& nums) {
	sort(begin(nums), end(nums), [](int x1, int x2){ return (x1 < x2); });
}
