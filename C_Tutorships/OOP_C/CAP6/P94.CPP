#include "iostream.h"

class A {
	int *p;
public:
	A() { p = new int [10]; }
	int &pos(int i) { return p[i]; }
	int lea(int i) { return p[i]; }
	~A() { delete p; }
};

main() {
	A b;
	for (int i=0; i < 10; i++)
		b.pos(i) = i+ 3;
	for (i = 0; i < 10; i++)
		cout << b.lea(i) << endl;
};
