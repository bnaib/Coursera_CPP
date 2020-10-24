#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printState(const vector<int>& v) {
  for (const auto& el : v)
    cout << el << " ";
  cout << endl;
}

int main() {
  int i, i_max;
  vector<int> v;
  vector<vector<int>> vv;

  cin >> i_max;
  i = 0;
  while (++i <= i_max)
    v.push_back(i);
  vv.push_back(v);
  while (next_permutation(v.begin(), v.end()))
    vv.push_back(v);
  auto k = vv.end();
  while (k-- != vv.begin()) {
    printState(*k);
  }
  return (0);
}