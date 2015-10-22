#include "iostream.h"
class B {
	int y;
public:
	B(int j) { y = j; }
	int F() { return y; }
	void suma() { y *= 2; }
};
class A {
	int x;
	B *p;
public:
	A(int i=0) {
		x = i;
		p = new B(i);
	}
	B *operator->() { return p; }
};
main() {
	A c(5);
	c->suma();
	cout << c->F() << endl;
}
