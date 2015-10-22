#include "iostream.h"

class A {
	int x;
public:
	A(int i=0) : x(i) {}
	A (A &b) { x = b.x; }
	int F() { return x; }
};

main() {
	A b(2);
	A c = b;
	A d (c);
	cout << b.F() << endl;
	cout << c.F() << endl;
	cout << d.F() << endl;
}
