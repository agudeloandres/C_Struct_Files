#include "iostream.h"

int i = 0;

void F() { i  = i + 12; }

class A {
	int i;
public:
	A(int ii=0) { i = ii; }
	void F(int ii) { i = i + ii; }
	void G(int *k) { i = i * *k; }
	int leai() { return i; }
};

class B : public A {
	float j;
public:
	B(float jj=0) : A(jj) { j = jj; }
	void F(float k) { j = j + k; }
	void G(int k) {
		F(k);
		A::F(k);
		this->A::F(k);
		::F();
	}
	float leaj() { return j; }
};

main() {
	A *a = new A(10);
	B *b = new B(23);
	void F();
	a->F(-11);        					// 1
	a->F(34.54);						// 2
	b->F(3);							// 3
	int j = 10;
	a->G(&j);                           // 4
	b->G(23);							// 5
	cout << i << endl;					// 6
	cout << a->leai() << endl;			// 7
	cout << b->leaj() << endl;			// 8
	cout << b->leai() << endl;			// 9
}





