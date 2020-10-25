#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    const string& prefix) {
  string p = prefix;
  if (prev(p.end()) != p.end())
    (*prev(p.end()))++;
  return (pair<RandomIt, RandomIt>(
    lower_bound(range_begin, range_end, prefix),
    lower_bound(range_begin, range_end, p)
  ));
}
