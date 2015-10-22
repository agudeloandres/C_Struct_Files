#include "iostream.h"

class A {
	int x;
public:
	A(int i=0) : x(i) {}
	int operator()() {
		x <<= 2;
		return x;
	}
};

main() {
	A b(8);
	cout << b() << endl;
	int i = b();
	cout << i << endl;
}
