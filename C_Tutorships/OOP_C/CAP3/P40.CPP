#include "iostream.h"

class A {
	int *p;
public:
	A(int i) { p = new int (i); }
	int *F() { return p; }
	~A() { delete p; }
};

class B {
	A y;
	int *q;
public:
	B(int x) : y (x) { 		// Inicializa el objeto y...
		q = new int (x+2);
	}
	int *G() { return y.F(); }
	int *H() { return q; }
	~B() {
		cout << "destruyendo...\n";
		delete q;
	}
};

main() {
	B a(10),b(20),c(30);
	cout << *a.G() + *a.H() << endl;
	cout << *b.G() + *b.H() << endl;
	cout << *c.G() + *c.H() << endl;
}
