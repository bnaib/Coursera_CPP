#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void RemoveDuplicates(vector<T>& elements) {
  sort(begin(elements), end(elements));
  elements.resize(
    unique(elements.begin(), elements.end()) - elements.begin());
}
