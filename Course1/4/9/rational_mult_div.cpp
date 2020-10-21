#include <iostream>
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

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
