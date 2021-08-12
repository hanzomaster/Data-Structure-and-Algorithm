#include <iostream>
#include <cmath>

using namespace std;

class Fraction {
private:
	int a;
	int b;

public:
	Fraction(int a, int b);
	friend ostream &operator<<(ostream &out, const Fraction &a);
	Fraction operator+(const Fraction &f) const;
	Fraction operator-(const Fraction &f) const;
	Fraction operator*(const Fraction &f) const;
	Fraction operator/(const Fraction &f) const;
	void simplify();
	bool operator>(const Fraction &f) const;
	bool operator<(const Fraction &f) const;
};
Fraction::Fraction(int a = 1, int b = 1) : a(a), b(b){};

void Fraction::simplify() {
	int m, n, r;
	n = abs(b);
	m = abs(a);
	while (r = m % n) {
		m = n;
		n = r;
	}
	b /= n;
	a /= n;
	if (b < 0) {
		b = -b;
		a = -a;
	}
}

ostream &operator<<(ostream &os, const Fraction &a) {
	os << a.a << '/' << a.b;
	return os;
}

Fraction Fraction::operator+(const Fraction &f) const {
	Fraction t;
	t.a = a * f.b + f.a * b;
	t.b = b * f.b;
	t.simplify();
	return t;
}

Fraction Fraction::operator-(const Fraction &f) const {
	Fraction t;
	t.a = a * f.b - f.a * b;
	t.b = b * f.b;
	t.simplify();
	return t;
}

Fraction Fraction::operator*(const Fraction &f) const {
	Fraction t;
	t.a = a * f.a;
	t.b = b * f.b;
	t.simplify();
	return t;
}

Fraction Fraction::operator/(const Fraction &f) const {
	Fraction t;
	if (!f.a) return *this;
	t.a = a * f.b;
	t.b = b * f.a;
	t.simplify();
	return t;
}

bool Fraction::operator>(const Fraction &f) const {
	int this_a, c_a, common_b;
	this_a = a * f.b;
	c_a = f.a * b;
	common_b = b * f.b;
	if ((this_a - c_a) * common_b > 0) return true;
	return false;
}

bool Fraction::operator<(const Fraction &f) const {
	int this_a, c_a, common_b;
	this_a = a * f.b;
	c_a = f.a * b;
	common_b = b * f.b;
	if ((this_a - c_a) * common_b < 0) return true;
	return false;
}

int main() {
	Fraction x(1, 3), y(1, 3);
	x = x + y;
	cout << x;
}
