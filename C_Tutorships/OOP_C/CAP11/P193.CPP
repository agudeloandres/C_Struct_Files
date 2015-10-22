#include "iostream.h"

class A {
	int i;
public:
	A (int ii=0) { i = ii; }
	A (A &b) {
		cout << "Copiador" << endl;
		i = b.i;
		cout << "i=" << i << endl;
	}
	int F() { return i; }
	A operator+(A b);
	A &operator= (A &b) {
		i = b.i;
		return *this;
	}
	~A() { cout << "Destruyendo" << endl; }
};
A A::operator+(A b) {
	A t;
	t.i = i + b.i;
	return t;
}

main() {
	A b(3),c(4), d;
	d = b + c;
	cout << d.F() << endl;
}


