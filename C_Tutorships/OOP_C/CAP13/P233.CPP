#include "iostream.h"

class A {
	int x;
public:
	A(int i) : x(i) { }
	int F() { return x; }
};

class B {
	int y;
public:
	B(int i) : y(i) { }
	int G() { return y; }
};

class C : public A, private B {
	int z;
public:
	C(int i, int j) : A(i), B(j), z(i+j) { }
	int I() { return G(); }
	int H() { return z; }
};

main() {
	C s(1,2);
	cout << s.F() << endl;
	cout << s.I() << endl;
	cout << s.H() << endl;
}
