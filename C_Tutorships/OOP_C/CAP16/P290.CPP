#include "iostream.h"

class A {
	int i,j;
public:
	A() {}
	int F() { return i+j; }
	friend istream &operator>>(istream &, A &);
};

istream &operator>>(istream &s, A &b) {
	cout << "De dos numeros separados por espacios\n";
	s >> b.i >> b.j;
	return s;
}

main() {
	A x;
	cin >> x;
	cout << x.F() << endl;
}


