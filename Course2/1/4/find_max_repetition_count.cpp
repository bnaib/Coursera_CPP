#include <map>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

bool	operator <(const Region& lhs, const Region& rhs) {
	return (tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
		tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population));
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
	map<Region, int>	repeats;
	int					result = 0;

	for (const auto& r : regions) {
		result = max(++repeats[r], result);
	}
	return (result);
}
