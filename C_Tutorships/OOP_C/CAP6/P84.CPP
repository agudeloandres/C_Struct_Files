#include "iostream.h"

class A {
	int *p;
public:
	A() { p =  new int; }
	int *G() { return p; }
	void F(A &);
	~A() {
		cout << "Destruyendo...\n";
		delete p;
	}
};

void A::F(A &c) {
	(*c.p)++;
}

main() {
	A b;
	int *q = b.G();
	*q = 10;
	b.F(b);
	cout << *b.G() << endl;
}


