#include "iostream.h"

class A {
	int x;
public:
	A() { x = 0; }
	A(int i) { x = i; }
	int F() { return x; }
};

main() {
	A b[5];
	A c[5] = { 1,2,3,4,5 };
	for (int i=0; i < 5; i++)
		cout << b[i].F() << endl;
	for (i=0; i < 5; i++)
		cout << c[i].F() << endl;
}
