#include "iostream.h"
#include "iomanip.h"

class A {
	int i,j;
public:
	int m;
	A(int k, int ele) { i = k; j = ele; }
	friend ostream &operator<<(ostream &s, A b);
};

ostream &operator<<(ostream &s, A b) {
	s << setw(4) << b.i << setw(4) << b.j << setw(4) << b.m << endl;
	return s;
}

main() {
	A x(1,2);
	x.m = 3;
	cout << x;
}
