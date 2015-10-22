#include "iostream.h"

class A {
	unsigned long x;
public:
	A(unsigned long i = 0) : x(i) {}
	void F() {
		void *p = this;
		cout << *(unsigned int *)p << endl;
		((unsigned int *)p)++;
		cout << *(unsigned int *)p << endl;
	}
	unsigned long G() { return this->x; }
};

main() {
	A b(0xabcdef83);
	b.F();
	cout << b.G() << endl;
}
