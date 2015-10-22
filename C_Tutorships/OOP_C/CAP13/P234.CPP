#include "iostream.h"

class A {
	int x;
public:
	A(int i) : x(i) { cout << "Construye A\n"; }
	int F() { return x; }
	~A() { cout << "Destruye A\n"; }
};

class B {
	int y;
public:
	B(int i) : y(i) { cout << "Construye B\n"; }
	int G() { return y; }
	~B() { cout << "Destruye B\n"; }
};

class C : public A, private B {
	int z;
public:
	C(int i, int j) : A(i), B(j), z(i+j) { cout << "Construye C\n"; }
	int I() { return G(); }
	int H() { return z; }
	~C() { cout << "Destruye C\n"; }
};

main() {
	C s(1,2);
	cout << s.F() << endl;
	cout << s.I() << endl;
	cout << s.H() << endl;
}
