#include "iostream.h"

class A {
	int x;
public:
	A(int i=0) { x = i;}
	A &operator= (A b) {
		x = b.x;
		return *this;
	}
	int F() { return x; }
};

class C : public A {
	float z;
public:
	C(float a,int i) : A(i), z(a) {}
	float G() { return z; }
};

main() {
	C a(3.1,4),c(-1.25,2);
	c = a;
	cout << c.G() << ' ' << c.F() << endl;
}

