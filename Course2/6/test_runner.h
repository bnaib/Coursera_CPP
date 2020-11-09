#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>

class TestRunner {
  private:
    int fail_count = 0;
  public:
    template <typename F>
    void RunTest(F f, const std::string& test_name);

    ~TestRunner();
};

template <typename F>
void TestRunner::RunTest(F f, const std::string& test_name)
{
  try {
    f();
    std::cerr << "PASSED: " << test_name << std::endl;
  } catch (const std::runtime_error & e) {
    ++fail_count;
    std::cerr << "FAIL: " << test_name << e.what() << std::endl;
  }
}

template <typename T>
std::ostream& operator << (std::ostream& os, const std::set<T>& s)
{
  os << "{";
  bool first = true;
  for (const auto& x : s)
  {
    if (!first)
      os << ", ";
    first = false;
    os << x;
  }
  return os << "}";
}

template <typename Key, typename Value>
std::ostream& operator << (std::ostream& os, const std::map<Key, Value>& map)
{
  os << "{";
  bool first = true;
  for (const auto& el : map) {
    if (!first)
      os << ", ";
    first = false;
    os << el.first << ": " << el.second;
  }
  return os << "}";
}

template <typename T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& s)
{
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first)
      os << ", ";
    first = false;
    os << x;
  }
  return os << "}";
}

void Assert(bool b, const std::string& hint);

template<typename T, typename U>
void AssertEqual(const T& t, const U& u, const std::string& hint)
{
  if (t != u) {
    std::ostringstream os;
    os << " Assertion failed: " << std::endl;
    os << t << " != " << u << " hint: " << hint;
    throw std::runtime_error(os.str());
  }
}
