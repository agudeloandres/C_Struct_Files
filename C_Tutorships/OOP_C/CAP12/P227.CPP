#include "iostream.h"

class A {
protected:
	int x;
public:
	A(int i=0) : x(i) {}
};

class B : private A {
	int y;
public:
	B(int i=0): A(i) {
		x++;
		y = i;
	}
	int F(int *p) {
		*p = x;
		return y;
	}
};

main() {
	B a(2);
	int i;
	cout << a.F(&i) << endl;
	cout << i << endl;
}

