#include <iostream>
#include <vector>
#include <map>

using namespace std;

#include "sqr_all.cpp"

// Пример вызова функции
int main() {
	vector<int> v = {1, 2, 3};
	cout << "vector:";
	for (int x : Sqr(v)) {
	cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = {
	{4, {2, 2}},
	{7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
	cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}
	return (0);
}