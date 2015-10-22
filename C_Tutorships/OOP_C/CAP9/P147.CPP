#include "iostream.h"

class A {
	int x;
public:
	A(int i = 0) : x(i) {}
	int F() { return this->x; }
	void G() { this->x++; }
};

main() {
	A b(4);
	cout << b.F() << endl;
	b.G();
	cout << b.F() << endl;
}
