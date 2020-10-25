#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PrintStats(vector<Person> persons) {
    auto females_end = partition(persons.begin(), persons.end(),
      [](const Person& p) { return p.gender == Gender::FEMALE; });
    auto employed_females_end = partition(persons.begin(), females_end,
      [](const Person& p) { return p.is_employed; });
    auto employed_males_end = partition(females_end, persons.end(),
      [](const Person& p) { return p.is_employed; });
    cout << "Median age = "
      << ComputeMedianAge(persons.begin(), persons.end())
      << endl
      << "Median age for females = "
      << ComputeMedianAge(persons.begin(), females_end)
      << endl
      << "Median age for males = "
      << ComputeMedianAge(females_end, persons.end())
      << endl
      << "Median age for employed females = "
      << ComputeMedianAge(persons.begin(),  employed_females_end)
      << endl
      << "Median age for unemployed females = "
      << ComputeMedianAge(employed_females_end, females_end)
      << endl
      << "Median age for employed males = "
      << ComputeMedianAge(females_end, employed_males_end)
      << endl
      << "Median age for unemployed males = "
      << ComputeMedianAge(employed_males_end, persons.end())
      << endl;
}
