#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

int GetDistinctRealRootCount(double a, double b, double c) {
  // Вы можете вставлять сюда различные реализации функции,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
	if (a == 0)
		return (b != 0);
	double d = b * b - 4 * a * c;
	if (d > 0)
		return (2);
	return (d == 0);
}

void TestNoRoots() {
	AssertEqual(GetDistinctRealRootCount(1, 0, 1), 0, "x^2 + 1 = 0");
	AssertEqual(GetDistinctRealRootCount(1, 0, 2), 0, "x^2 + 2 = 0");
	AssertEqual(GetDistinctRealRootCount(2, 0, 1), 0, "2 * x^2 + 1 = 0");

	AssertEqual(GetDistinctRealRootCount(1, 2, 3), 0, "1 * x^2 + 2 * x + 3 = 0");
	AssertEqual(GetDistinctRealRootCount(3, 2, 1), 0, "3 * x^2 + 2 * x + 1 = 0");

	AssertEqual(GetDistinctRealRootCount(-30, -10, -1), 0,
		"-30 * x^2 - 10 * x - 1 = 0");
}

void TestOneRoot() {
	AssertEqual(GetDistinctRealRootCount(1, 0, 0), 1, "x^2 = 0");
	AssertEqual(GetDistinctRealRootCount(-101, 0, 0), 1, "-101 * x^2 = 0");

	AssertEqual(GetDistinctRealRootCount(0, 1, 0), 1, "1 * x = 0");
	AssertEqual(GetDistinctRealRootCount(0, -202, 0), 1, "-202 * x = 0");

	AssertEqual(GetDistinctRealRootCount(0, -999, 888), 1,
		"-999 * x + 888 = 0");
	AssertEqual(GetDistinctRealRootCount(0, 777, -666), 1,
		"777 * x - 666 = 0");
}

void TestZZC() {
	AssertEqual(GetDistinctRealRootCount(0, 0, 123), 0, "123 = 0");
	AssertEqual(GetDistinctRealRootCount(0, 0, -123), 0, "-123 = 0");
}

int main() {
  TestRunner runner;
  // добавьте сюда свои тесты
	runner.RunTest(TestNoRoots, "TestNoRoots");
	runner.RunTest(TestOneRoot, "TestOneRoot");
	runner.RunTest(TestZZC, "TestZZC");
  return 0;
}
