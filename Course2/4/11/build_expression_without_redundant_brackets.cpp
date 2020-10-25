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
  int             brackets = 0;
  bool            add_brackets = false;

  cin >> number >> n;
  numbers.push_back(number);
  while (n-- > 0) {
    cin >> action >> number;
    actions.push_back(action);
    if (action == "+" || action == "-")
      add_brackets = true;
    else if (add_brackets) {
      add_brackets = false;
      brackets++;
    }
    numbers.push_back(number);
  }
  n = brackets;
  while (n-- > 0)
    cout << "(";
  cout << numbers.front();
  numbers.pop_front();
  add_brackets = false;
  while (!numbers.empty()) {
    if (actions.front() == "+" || actions.front() == "-")
      add_brackets = true;
    else if (add_brackets) {
      add_brackets = false;
      cout << ")";
      brackets--;
    }
    cout << " " << actions.front() << " " << numbers.front();
    actions.pop_front();
    numbers.pop_front();
  }
  cout << endl;
  return (0);
}
