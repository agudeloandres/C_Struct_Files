#include "iostream.h"

class A {
	int x;
public:
	A() { x = 8; }
	int F() { return x; }
};

main() {
	A b;
	cout << b.F() << endl;
}
