#include "iostream.h"

class A {
	int *p;
public:
	A() { p =  new int; }
	int *G() { return p; }
	void F(A);
	~A() {
		cout << "Destruyendo...\n";
		delete p;
	}
};

void A::F(A c) { // Lo destruye al final del programa
	(*c.p)++;
}

main() {
	A b,m;
	int *q = b.G();
	*q = 10;
	m.F(b);
	cout << *b.G() << endl;
	cout << "------\n";
}

