#include <string>
#include <set>
#include <map>
using std::set;
using std::map;
using std::string;


set<string> BuildMapValuesSet(const map<int, string>& m) {
	set<string>		s;

	for (const auto& el : m)
		s.insert(el.second);
	return (s);
}