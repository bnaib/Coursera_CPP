#include <iostream>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

set<int>::const_iterator FindNearestElement(
    const set<int>& numbers,
    int border) {
  const auto it = numbers.lower_bound(border);
  if (it == numbers.begin())
    return (it);
  if (it == numbers.end())
    return (prev(it));
  return ((border - *prev(it) > *it - border) ? it : prev(it));
}
