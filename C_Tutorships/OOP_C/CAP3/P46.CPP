#include "iostream.h"

class A {
	int *p;
public:
	A() {
		p = new int [10];
		for (int i=0; i < 10; i++)
		p[i] = 0;
	}
	~A() { delete p; }
}


