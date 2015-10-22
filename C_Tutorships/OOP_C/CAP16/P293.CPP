#include "iostream.h"

class A {
	int i,j;
public:
	int m;
	A() {}
	int F() { return i+j+m; }
	void asignar(int k,int ele) { i = k; j = ele; }
};

istream &operator>>(istream &s, A &b) {
	cout << "De tres numeros separados por espacios\n";
	int i,j;
	cin >> i >> j;
	s >> b.m;
	b.asignar(i,j);
	return s;
}

main() {
	A x;
	cin >> x;
	cout << x.F() << endl;
}
