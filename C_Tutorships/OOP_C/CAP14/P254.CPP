#include "iostream.h"

class A {
	int i;
	float f;
	double d;
public:
	A(int j=0,float k=0.0,double ele=0) {
		i = j; f = k; d = ele;
	}
	void F(int j) { i += j; }
	void F(float *k) { f += *k; }
	void F(double *ele) { d += *ele; }
	int leai() { return i; }
	float leaf() { return f; }
	double lead() { return d; }
};

main() {
	A b(1,2.0,3.023);
	b.F(3);
	double d = 8.034;
	float f = 3.456;
	b.F(&f);
	b.F(&d);
	cout <<  b.leai() << endl;
	cout <<  b.leaf() << endl;
	cout <<  b.lead() << endl;
}

