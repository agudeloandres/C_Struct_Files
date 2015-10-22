#include "iostream.h"

class A {
	int x,y,z;
public:
	A() { x = y = z = 0; }
	A(int i) { x = i; y = z = 0; }
	A(int i,int j) { x = i; y = j; z = 0; }
	A(int i,int j,int k) { x = i; y = j; z = k; }
	int F() { return x; }
	int G() { return y; }
	int H() { return z; }
};

main() {
	A b;
	A c(1);
	A d (1,2);
	A e (1,2,3);
	cout << e.F() << endl;
	cout << d.G() << endl;
	cout << c.H() << endl;
	cout << b.H() << endl;
}

