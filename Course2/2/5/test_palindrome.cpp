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

bool IsPalindrom(const string& str) {
  // Вы можете вставлять сюда различные реализации функции,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
	size_t	endi = str.size();
	size_t	starti = 0;

	if (endi-- < 2)
		return (true);
	while (endi >= starti) {
		if (str[endi] != str[starti])
			return (false);
		endi--;
		starti++;
	}
	return (true);
}

void Test1() {
	AssertEqual(IsPalindrom(""), true, "\\0");
	AssertEqual(IsPalindrom("h"), true, "h");
	AssertEqual(IsPalindrom("pp"), true, "pp");
	AssertEqual(IsPalindrom("ba"), false, "ba");
	AssertEqual(IsPalindrom("qwerewq"), true, "qwerewq");
	AssertEqual(IsPalindrom("qwerevq"), false, "qwerevq");
	AssertEqual(IsPalindrom("asdffdsa"), true, "asdffdsa");
	AssertEqual(IsPalindrom("bsdffds"), false, "bsdffds");
	AssertEqual(IsPalindrom("sdffdsz"), false, "sdffdsz");
	AssertEqual(IsPalindrom("asa zxz"), false, "asa zxz");
}

void Test2() {
	AssertEqual(IsPalindrom(" a"), false, "_a");
	AssertEqual(IsPalindrom("a "), false, "a_");
	AssertEqual(IsPalindrom(" a "), true, "_a_");
}

int main() {
  TestRunner runner;
  // добавьте сюда свои тесты
  runner.RunTest(Test1, "Test1");
  runner.RunTest(Test2, "Test2");
  return 0;
}
