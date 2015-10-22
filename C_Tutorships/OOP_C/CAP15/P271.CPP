#include "iostream.h"
class A {
	float i;
	static int j;
public:
	A(float f = 0) : i(f) {}
	void sumar(float f,int k) {
		i = i + f;
		j = j + k;
	}
	float F(int *p) {
		*p = j;
		return i;
	}
};
int A::j = 0;
main() {
	A b(23.45),c(2.45);
	b.sumar (1.0, 3);
	c.sumar (3.4, 2);
	int k;
	cout << b.F(&k) << ' ';
	cout << k << endl;
	cout << c.F(&k) << ' ';
	cout << k << endl;
}

