#include "iostream.h"

class A {
	int x,y;
public:
	A(int i=0,int j=0) { x = i; y = j; }
	int F(int *p) {
		*p = y;
		return x;
	}
	A operator+(A &);
};

A A::operator+ (A &b) {
	A t;
	t.x = x + b.x;
	t.y = y + b.y;
	return t;
}

main() {
	A b(1,2),c(3,4),d;
	int j;
	d = b + c;
	cout << d.F(&j) << endl;
	cout << j << endl;
}
