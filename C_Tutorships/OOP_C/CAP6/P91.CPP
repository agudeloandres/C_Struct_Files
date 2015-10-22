#include "iostream.h"

class A {
	int x;
public:
	A(int i) : x(i) {}
	int F() { return x; }
	void G() { x--; }
	~A() {}
};

A b(3),c(8);

A &F(A &f) {
	f.G();
	return b;
}

main() {
	A &F(A &);
	F(c) = c;
	cout << b.F() << " " << c.F() << endl;
}
