#include "iostream.h"
#include "stdlib.h"

class A {
	int secreto;
public:
	A(int i=0) : secreto(i) { cout << "A\n"; }
	int F() { return secreto; }
	~A() { cout << "Destruye A\n"; }
};

class B : private A {
public:
	B(int i=0) : A (i) { cout << "B\n";  }
	int G() { return F(); }
	~B() { cout << "Destruye B\n"; }
};

class C : private B {
public:
	C(int i=0) : B (i) { cout << "C\n"; }
	int H() { return G(); }
	~C() { cout << "Destruye C\n"; }
};

class D : private C {
public:
	D(int i=0) : C (i) { cout << "D\n"; }
	int I() { return H(); }
	~D() { cout << "Destruye D\n"; }
};

main() {
	D a( random(32000) );
	cout << a.I() << endl;
}
