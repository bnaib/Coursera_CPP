#include <iostream>
#include <exception>
using namespace std;

class Rational {
public:
    Rational() {
		this->numerator = 0;
		this->denominator = 1;
    }

    Rational(int numerator, int denominator) {
		if (denominator == 0)
			throw invalid_argument("Division by zero");
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
	if (r2.Numerator() == 0)
		throw domain_error("Division by zero");
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

void		CheckAndIgnore(char c) {
	if (cin.peek() != c)
		throw exception();
	cin.ignore(1);
}

Rational	LoadRational() {
	int			a, b;
	Rational	r;

	cin >> a;
	CheckAndIgnore('/');
	cin >> b;
	return (Rational(a, b));
}

char		LoadD() {
	char	d;

	CheckAndIgnore(' ');
	cin >> d;
	CheckAndIgnore(' ');
	return (d);
}

int	main() {
	Rational	r1, r2;
	char		d;
	try {
		r1 = LoadRational();
		d = LoadD();
		r2 = LoadRational();
	} catch (exception&) {
		cout << "Invalid argument" << endl;
		return (0);
	}
	try {
		if (d == '+')
			cout << r1 + r2 << endl;
		else if (d == '-')
			cout << r1 - r2 << endl;
		else if (d == '*')
			cout << r1 * r2 << endl;
		else if (d == '/')
			cout << r1 / r2 << endl;
		else
			cout << "Invalid argument" << endl;
	} catch (domain_error&) {
		cout << "Division by zero" << endl;
	}
	return (0);
}