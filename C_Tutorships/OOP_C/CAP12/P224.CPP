#include "iostream.h"

class A {
	int x;
public:
	A(int i=0) { x = i;}
	void operator<< (int i) {
		x = x << i;
	}
	int F() { return x; }
};

class B : public A {
public:
	B(int i=0) : A (i) {}
};

main() {
	B c(10);
	c << 1;
	cout << c.F() << endl;
}
