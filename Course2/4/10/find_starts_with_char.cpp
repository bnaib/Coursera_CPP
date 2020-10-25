#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    char prefix) {
  string str1 = {prefix};
  string str2 = {prefix};
  if (prev(str2.end()) != str2.end())
    (*prev(str2.end()))++;
  return (pair<RandomIt, RandomIt>(
    lower_bound(range_begin, range_end, str1),
    lower_bound(range_begin, range_end, str2)
  ));
}
