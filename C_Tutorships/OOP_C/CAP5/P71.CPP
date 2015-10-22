#include "iostream.h"

class B;

class A {
	int x;
public:
	A(int i) : x(i) {}
	friend int F(A,B);
};

class B {
	int y;
public:
	B(int i) : y(i) {}
	friend int F(A,B);
};

int F( A b, B c) {
	return b.x + c.y;
}

main() {
	A d(10);
	B c(11);
	cout << F(d,c) << endl;
}

