#include "iostream.h"

int F() {
	cout << "De dato\n";
	int i;
	cin >> i;
	return i;
}

class A {
	int *p;
public:
	A(int x) { p = new int (x); }  // Parentesis () !
	int F() { return *p; }
	~A() { delete p; }
};

main() {
	A b(F());
	cout << b.F() << endl;
	A c(F());
	A d(F());
	cout << c.F() << endl;
	cout << d.F() << endl;
}

