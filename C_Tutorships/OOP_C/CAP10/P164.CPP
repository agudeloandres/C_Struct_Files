#include "iostream.h"

class A {
	int x,y;
public:
	A(int i=0,int j=0) { x = i; y = j; }
	int F(int *p) {
		*p = y;
		return x;
	}
	friend A operator+(A &, A &);
	friend A operator-(A &, A &);
	friend A operator*(A &, A &);
	friend A operator/(A &, A &);
	friend A operator%(A &, A &);
};

A operator+ (A &b, A &c) {
	A t;
	t.x = b.x + c.x;
	t.y = b.y + c.y;
	return t;
}

A operator- (A &b, A &c) {
	A t;
	t.x = b.x - c.x;
	t.y = b.y - c.y;
	return t;
}

A operator* (A &b, A &c) {
	A t;
	t.x = b.x * c.x;
	t.y = b.y * c.y;
	return t;
}

A operator/ (A &b, A &c) {
	A t;
	t.x = b.x / c.x;
	t.y = b.y / c.y;
	return t;
}

A operator% (A &b, A &c) {
	A t;
	t.x = b.x % c.x;
	t.y = b.y % c.y;
	return t;
}

main() {
	A b(1,2),c(3,4),d;
	int j;
	d = b + c;
	b = c - d;
	c = b * d;
	d = c / b;
	A e(3,5);
	d = c % e;
	cout << d.F(&j) << endl;
	cout << j << endl;
	cout << b.F(&j) << endl;
	cout << j << endl;
	cout << c.F(&j) << endl;
	cout << j << endl;
	cout << e.F(&j) << endl;
	cout << j << endl;
	c = c + b;
	cout << c.F(&j) << endl;
	cout << j << endl;
	cout << (e + d).F(&j) << endl;
	cout << j << endl;
}

