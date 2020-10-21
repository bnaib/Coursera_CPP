#include <vector>

void Reverse(vector<int>& v) {
	size_t	s;
	size_t	c;

	s = v.size();
	if ((c = v.size() / 2) == 0)
		return ;
	s--;
	for (size_t i = 0; i < c; i++)
		swap(v[i], v[s - i]);
}