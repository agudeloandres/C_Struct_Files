#include "iostream.h"

class A {
	int i;
public:
	A (int j = 0) {i = j; }
	int F() { return i; }
	friend class B;
};

class B {
	int j;
public:
	B(int i=0) { j = i; }
	int F(A &a) { return a.i; }
	int F(A a) { return a.i; }
};

main() {
	A b,c(10);
	B d,e(20);
	cout << b.F() << endl;
	cout << c.F() << endl;
	cout << d.F(b) << endl;
	cout << e.F(c) << endl;
}
