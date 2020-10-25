#include <iostream>
#include <deque>
#include <utility>

using namespace std;

int main() {
  deque<double>  numbers;
  deque<string>  actions;
  double          number;
  string          action;
  int             n;

  cin >> number >> n;
  numbers.push_back(number);
  while (n-- > 0) {
    cin >> action >> number;
    actions.push_back(action);
    numbers.push_back(number);
  }
  n = numbers.size();
  while (--n > 0)
    cout << "(";
  cout << numbers.front();
  numbers.pop_front();
  while (!numbers.empty()) {
    cout << ") " << actions.front() << " " << numbers.front();
    actions.pop_front();
    numbers.pop_front();
  }
  cout << endl;
  return (0);
}
