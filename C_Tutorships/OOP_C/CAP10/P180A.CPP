#include "iostream.h"

class A {
	int x;
public:
	A(int i=0) : x(i) {}
	int operator()(int i) {
		x <<= i;
		return x;
	}
};

int F() {
	int i;
	cout << "De un entero..." << endl;
	cin >> i;
	return i;
}

main() {
	int F(void);
	A b(8);
	cout << b(2) << endl;
	int i = b( F() );
	cout << i << endl;
}
