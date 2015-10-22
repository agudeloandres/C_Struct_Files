#include "iostream.h"

class A {
	int x,y,z;
public:
	A(int i=0, int j=0, int k=0) {
		x = i;
		y = j;
		z = k;
	}
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

