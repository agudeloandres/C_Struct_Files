#include "iostream.h"

class A {
	int x;
public:
	A(int i) { x = i; }
	int F() { return x; }
};

class B : public A {
	int x;
public:
	B(int i) : A(i+4) { x = i; }
	int F() { return x; }
};

class C : public A {
	int x;
public:
	C(int i)  : A(i+3) { x = i; }
	int F() { return x; }
};

class D : virtual public B, virtual public C {
	int x;
public:
	D(int i)  : B(i+1), C(i+2), { x = i; }
	int F() { return x; }
};

main() {
	D s(3);
	cout << s.F() << endl;
	cout << s.A::F() << endl;
	cout << s.B::F() << endl;
	cout << s.C::F() << endl;
}
