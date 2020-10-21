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

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
