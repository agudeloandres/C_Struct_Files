#include "iostream.h"

class A {
	float x;
public:
	A(float i = 0) {
		x = i;
	}
	float F() { return this->x; }
	//  ~A() {}  no existe memoria asignada en ningun objeto..
};

main() {
	A *p[10];
	for (int i=0; i < 10; i++)
		p[i] = new A(i * 2.0);

	for (i=0; i < 10; i++)
		cout << p[i]->F() << ' ';

	cout << endl;
	for (i=0; i < 10; i++)
		delete p[i];
}

