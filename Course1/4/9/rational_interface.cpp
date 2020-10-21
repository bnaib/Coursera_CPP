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

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}
