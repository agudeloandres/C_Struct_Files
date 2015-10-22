#include "iostream.h"

class A {
	int x;
public:
	A() { x  = 0; }
	A(int i) { x = i; }
	int F() { return x; }
};

main() {
	A b;
	A c(3);
	cout << b.F() << endl;
	cout << c.F() << endl;
}
