#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
  vector<string> result;
  auto it_from = s.begin();
  auto it_to = s.end();

  while (it_from != s.end()) {
    it_to = find(it_from, s.end(), ' ');
    result.push_back(string(it_from, it_to));
    if (it_to != s.end())
      it_to++;
    it_from = it_to;
  }
  return (result);
}
