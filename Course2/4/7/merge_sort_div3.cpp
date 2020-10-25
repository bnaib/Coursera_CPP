#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
  if (range_end - range_begin < 3) {
    sort(range_begin, range_end);
    return ;
  }
  vector<typename RandomIt::value_type> v(range_begin, range_end);
  RandomIt sep1 = v.begin() + v.size() / 3;
  RandomIt sep2 = sep1 + v.size() / 3;
  MergeSort(v.begin(), sep1);
  MergeSort(sep1, sep2);
  MergeSort(sep2, v.end());
  vector<typename RandomIt::value_type> v1_2;
  merge(
    v.begin(), sep1,
    sep1, sep2,
    back_inserter(v1_2)
  );
  merge(
    v1_2.begin(), v1_2.end(),
    sep2, v.end(),
    range_begin
  );
}
