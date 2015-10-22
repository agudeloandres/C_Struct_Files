#include "iostream.h"

class A {
	int x;
public:
	A(int i=0) : x(i) {}
	int F() { return x; }
};

class B : private A {
	int y;
public:
	B(int i=0) : A (i+2), y(i) {}
	int G() { return F() + y; }
};

main() {
	B c(5);
	cout << c.G() << endl;
}
