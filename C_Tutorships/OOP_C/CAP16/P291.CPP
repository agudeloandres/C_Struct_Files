#include "iostream.h"

class A {
	int i,j;
public:
	A() {}
	int F() { return i+j; }
	void asignar(int k, int ele) { i = k; j = ele; }
};

istream &operator>>(istream &s, A &b) {
	cout << "De dos numeros separados por espacios\n";
	int i,j;
	cin >> i >> j;
	b.asignar(i,j);
	return s;
}

main() {
	A x;
	cin >> x;
	cout << x.F() << endl;
}


