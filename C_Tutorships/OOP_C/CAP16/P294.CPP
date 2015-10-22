#include "iostream.h"
#include "iomanip.h"

class A {
	int i,j;
public:
	int m;
	A(int k, int ele) { i = k; j = ele; }
	int F() { return i+j+m; }
	void leer(int *p,int *q) { *p = i; *q = j; }
};

ostream &operator<<(ostream &s, A &b) {
	int i,j;
	b.leer(&i,&j);
	cout << setw(4) << i << setw(4) << j << setw(4);
	s << setw(4) << b.m << endl;
	return s;
}

main() {
	A x(1,2);
	x.m = 3;
	cout << x;
}
