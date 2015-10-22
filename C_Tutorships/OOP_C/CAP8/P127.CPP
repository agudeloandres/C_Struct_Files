#include "iostream.h"

class A {
	int x;
public:
	A(int i = 0) { x  = i; }
	int F() { return x; }
};

main() {
	A b;
	A c(3);
	cout << b.F() << endl;
	cout << c.F() << endl;
}
