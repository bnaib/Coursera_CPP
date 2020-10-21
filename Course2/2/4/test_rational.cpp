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

// class Rational {
// public:
//     Rational() {
// 		this->numerator = 0;
// 		this->denominator = 1;
//     }

//     Rational(int numerator, int denominator) {
// 		if (denominator == 0)
// 			throw invalid_argument("Division by zero");
// 		this->numerator = numerator;
// 		this->denominator = denominator;
// 		Norm();
//     }

//     int Numerator() const {
//         return (this->sign ? -this->numerator : this->numerator);
//     }

//     int Denominator() const {
//         return (this->denominator);
//     }

// private:
// 	int		numerator;
// 	int		denominator;
// 	char	sign;
// 	int		GreatestCommonFactor(int a, int b) const{
// 		while (a > 0 && b > 0) {
// 			if (a > b)
// 				a %= b;
// 			else
// 				b %= a;
// 		}
// 		return (a + b);
// 	}
// 	void	Norm() {
// 		int		gcf;

// 		if (this->sign = this->numerator < 0)
// 			this->numerator *= -1;
// 		this->sign ^= this->denominator < 0;
// 		if (this->denominator < 0)
// 			this->denominator *= -1;
// 		gcf = GreatestCommonFactor(this->numerator, this->denominator);
// 		this->numerator /= gcf;
// 		this->denominator /= gcf;
// 	}
// };

void TestDefault() {
	Rational	r;

	AssertEqual(r.Numerator(), 0, "Default construst Numerator");
	AssertEqual(r.Denominator(), 1, "Default construst Denominator");
}

// void TestDivisionByZero() {
// 	try
// 	{
// 		Rational	r(1, 0);
// 	}
// 	catch(const std::invalid_argument& e)
// 	{
// 		return ;
// 	}
// 	AssertEqual("", "Division by zero", "Division by zero");
// }

void TestPQMin() {
	Rational	r1(8, 2);
	AssertEqual(r1.Numerator(), 4, "8/2 Numerator");
	AssertEqual(r1.Denominator(), 1, "8/2 Denominator");

	Rational	r2(120, 42);
	AssertEqual(r2.Numerator(), 20, "120/42 Numerator");
	AssertEqual(r2.Denominator(), 7, "120/42 Denominator");
}

void TestSign() {
	Rational	r1(-100, 30);
	AssertEqual(r1.Numerator(), -10, "-100/30 Numerator");
	AssertEqual(r1.Denominator(), 3, "-100/30 Denominator");

	Rational	r2(200, -150);
	AssertEqual(r2.Numerator(), -4, "200/-150 Numerator");
	AssertEqual(r2.Denominator(), 3, "200/-150 Denominator");

	Rational	r3(-999, -666);
	AssertEqual(r3.Numerator(), 3, "-999/-666 Numerator");
	AssertEqual(r3.Denominator(), 2, "-999/-666 Denominator");
}

void TestZero() {
	Rational	r1(0, 999);
	AssertEqual(r1.Numerator(), 0, "0/999 Numerator");
	AssertEqual(r1.Denominator(), 1, "0/999 Denominator");

	Rational	r2(0, -777);
	AssertEqual(r2.Numerator(), 0, "0/-777 Numerator");
	AssertEqual(r2.Denominator(), 1, "0/-777 Denominator");
}

int main() {
	TestRunner runner;
	// добавьте сюда свои тесты
	runner.RunTest(TestDefault, "TestDefault");
	// runner.RunTest(TestDivisionByZero, "TestDivisionByZero");
	runner.RunTest(TestPQMin, "TestPQMin");
	runner.RunTest(TestSign, "TestSign");
	runner.RunTest(TestZero, "TestZero");
	return 0;
}
