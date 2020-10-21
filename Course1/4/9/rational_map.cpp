#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;


class Rational {
public:
    Rational() {
		this->numerator = 0;
		this->denominator = 1;
    }

    Rational(int numerator, int denominator) {
		this->numerator = numerator;
		this->denominator = denominator;
		Norm();
    }

    int Numerator() const {
        return (this->sign ? -this->numerator : this->numerator);
    }

    int Denominator() const {
        return (this->denominator);
    }

private:
	int		numerator;
	int		denominator;
	char	sign;
	int		GreatestCommonFactor(int a, int b) const{
		while (a > 0 && b > 0) {
			if (a > b)
				a %= b;
			else
				b %= a;
		}
		return (a + b);
	}
	void	Norm() {
		int		gcf;

		if (this->sign = this->numerator < 0)
			this->numerator *= -1;
		this->sign ^= this->denominator < 0;
		if (this->denominator < 0)
			this->denominator *= -1;
		gcf = GreatestCommonFactor(this->numerator, this->denominator);
		this->numerator /= gcf;
		this->denominator /= gcf;
	}
};

bool		operator ==(const Rational& r1, const Rational& r2) {
	return (r1.Numerator() == r2.Numerator() &&
		r1.Denominator() == r2.Denominator());
}

Rational	operator +(const Rational& r1, const Rational& r2) {
	return (Rational(
		r1.Numerator() * r2.Denominator() + r2.Numerator() * r1.Denominator(),
		r1.Denominator() * r2.Denominator()
	));
}

Rational	operator -(const Rational& r1, const Rational& r2) {
	return (Rational(
		r1.Numerator() * r2.Denominator() - r2.Numerator() * r1.Denominator(),
		r1.Denominator() * r2.Denominator()
	));
}

Rational	operator *(const Rational& r1, const Rational& r2) {
	return (Rational(
		r1.Numerator() * r2.Numerator(),
		r1.Denominator() * r2.Denominator()
	));
}

Rational	operator /(const Rational& r1, const Rational& r2) {
	return (Rational(
		r1.Numerator() * r2.Denominator(),
		r1.Denominator() * r2.Numerator()
	));
}

istream&	operator >>(istream& stream, Rational& r) {
	int 	numerator;
	int		denominator;
	char	c;
	
	if (!(stream >> numerator))
		return (stream);
	if (!(stream >> c) || c != '/')
		return (stream);
	if (!(stream >> denominator))
		return (stream);
	r = Rational(numerator, denominator);
	return (stream);
}

ostream&	operator <<(ostream& stream, const Rational& r) {
	stream << r.Numerator() << "/" << r.Denominator();
	return (stream);
}

bool		operator <(const Rational& r1, const Rational& r2) {
	if (r1.Denominator() == 0 || r2.Denominator() == 0)
		return (r1.Denominator() == 0 && r2.Denominator() == 0);
	
	return (
		(double)(r1.Numerator()) / r1.Denominator() <
		(double)(r2.Numerator()) / r2.Denominator()
	);
}

bool		operator >(const Rational& r1, const Rational& r2) {
	if (r1.Denominator() == 0 || r2.Denominator() == 0)
		return (r1.Denominator() == 0 && r2.Denominator() == 0);
	
	return (
		(double)(r1.Numerator()) / r1.Denominator() >
		(double)(r2.Numerator()) / r2.Denominator()
	);
}

bool		operator <=(const Rational& r1, const Rational& r2) {
	if (r1.Denominator() == 0 || r2.Denominator() == 0)
		return (r1.Denominator() == 0 && r2.Denominator() == 0);
	
	return (
		(double)(r1.Numerator()) / r1.Denominator() <=
		(double)(r2.Numerator()) / r2.Denominator()
	);
}

bool		operator >=(const Rational& r1, const Rational& r2) {
	if (r1.Denominator() == 0 || r2.Denominator() == 0)
		return (r1.Denominator() == 0 && r2.Denominator() == 0);
	
	return (
		(double)(r1.Numerator()) / r1.Denominator() >=
		(double)(r2.Numerator()) / r2.Denominator()
	);
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
