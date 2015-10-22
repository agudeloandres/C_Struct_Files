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
};

A operator+ (A &b, A &c) {
	A t;
	t.x = b.x + c.x;
	t.y = b.y + c.y;
	return t;
}

main() {
	A b(1,2),c(3,4),d;
	int j;
	d = b + c;
	cout << d.F(&j) << endl;
	cout << j << endl;
}