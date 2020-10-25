#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
  if (range_end - range_begin < 2)
    return ;
  vector<typename RandomIt::value_type> v(range_begin, range_end);
  RandomIt sep = v.begin() + v.size() / 2;
  MergeSort(v.begin(), sep);
  MergeSort(sep, v.end());
  merge(
    v.begin(), sep,
    sep, v.end(),
    range_begin
  );
}
