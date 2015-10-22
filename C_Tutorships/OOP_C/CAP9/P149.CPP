#include "iostream.h"

class A {
	int x;
public:
	A(int i=0) { x= i; }
	A F() {	return *this; }
	int G() { return x; }
};

main() {
	A b(3),c(88);
	c = b.F();
	cout << c.G() << endl;
	cout << b.G() << endl;
}

