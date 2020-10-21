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

// class Person {
// 	private:
// 		map<int, string>	first_name;
// 		map<int, string>	last_name;
// 	public:
// 	void ChangeFirstName(int year, const string& first_name) {
// 		this->first_name[year] = first_name;
// 	}
// 	void ChangeLastName(int year, const string& last_name) {
// 		this->last_name[year] = last_name;
// 	}
// 	string GetFullName(int year) {
// 		string	first_name;
// 		string	last_name;
// 		int 	state = 0;

// 		for (const auto& el : this->first_name) {
// 			if (el.first > year)
// 				break;
// 			state |= 2;
// 			first_name = el.second;
// 		}
// 		for (const auto& el : this->last_name) {
// 			if (el.first > year)
// 				break;
// 			state |= 1;
// 			last_name = el.second;
// 		}
// 		if (state == 0)
// 			return ("Incognito");
// 		if (state == 1)
// 			return (last_name + " with unknown first name");
// 		if (state == 2)
// 			return (first_name + " with unknown last name");
// 		return (first_name + " " + last_name);
// 	}
// };

void	Test1() {
	Person		p;

	p.ChangeFirstName(2010, "TestFirstName");
	p.ChangeLastName(2015, "TestLastName");

	AssertEqual(p.GetFullName(1999), "Incognito");
	AssertEqual(p.GetFullName(2009), "Incognito");
	AssertEqual(p.GetFullName(2010), "TestFirstName with unknown last name");
	AssertEqual(p.GetFullName(2011), "TestFirstName with unknown last name");
	AssertEqual(p.GetFullName(2015), "TestFirstName TestLastName");
	AssertEqual(p.GetFullName(2016), "TestFirstName TestLastName");

	p.ChangeFirstName(2017, "TFN");
	AssertEqual(p.GetFullName(2016), "TestFirstName TestLastName");
	AssertEqual(p.GetFullName(2017), "TFN TestLastName");
	AssertEqual(p.GetFullName(2018), "TFN TestLastName");

	p.ChangeLastName(2016, "TLN");
	AssertEqual(p.GetFullName(2015), "TestFirstName TestLastName");
	AssertEqual(p.GetFullName(2016), "TestFirstName TLN");
	AssertEqual(p.GetFullName(2018), "TFN TLN");
}

void Test2() {
	Person		p;

	p.ChangeLastName(1750, "TLN");
	p.ChangeFirstName(1900, "TFN");

	AssertEqual(p.GetFullName(1700), "Incognito");
	AssertEqual(p.GetFullName(1701), "Incognito");
	AssertEqual(p.GetFullName(1749), "Incognito");
	AssertEqual(p.GetFullName(1750), "TLN with unknown first name");
	AssertEqual(p.GetFullName(1751), "TLN with unknown first name");
	AssertEqual(p.GetFullName(1899), "TLN with unknown first name");
	AssertEqual(p.GetFullName(1900), "TFN TLN");
	AssertEqual(p.GetFullName(1901), "TFN TLN");
	AssertEqual(p.GetFullName(1950), "TFN TLN");
}

int main() {
  TestRunner runner;
  // добавьте сюда свои тесты
  runner.RunTest(Test1, "Test1");
  runner.RunTest(Test2, "Test2");
  return 0;
}
