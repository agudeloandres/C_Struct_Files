#include "iostream.h"
#include "stdlib.h"

class A {
public:
	virtual void F() {}
};

class B : public A {
public:
	void F() { cout << "Clase B\n"; }
};

class C : public A {
public:
	void F() { cout << "Clase C\n"; }
};

class D : public A {
public:
	void F() { cout << "Clase D\n"; }
};

main() {
	A *p;
	B x;
	C y;
	D z;
	int i;
	cout << "De numero de 0 a 2\n";
	cin >> i;
	switch (i) {
		case 0 : p = &x; break;
		case 1 : p = &y; break;
		case 2 : p = &z; break;
	}
	p->F();
}

