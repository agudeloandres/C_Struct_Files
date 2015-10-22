#include "iostream.h"

class Y {
	int x;
public:
	Y() {}
	Y(int i) : x(i) {}
	int F() { return x; }
	void G(int i) { x = i; }
};

class X {
	Y a;
	int i;
public:
	X(int z): i(z-1) {
		a.G(z);
	}
	int G(int *p) {
		*p = i;
		return a.F();
	}
};

main() {
	cout << "De entero..." << endl;
	int i,j;
	cin >> i;
	X b(i+3);
	i = b.G(&j);
	cout << i << endl;
	cout << j << endl;
}
