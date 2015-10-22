#include "iostream.h"
class A {
	static int i;
public:
	void iniciar(int j=0) { i = j; }
	void sumar(int j=0) { i = i + j; }
	int F() { return i; }
};
int A::i;
main() {
	A b,c,d;
	b.iniciar(1);
	b.sumar(3);
	c.sumar();
	d.sumar(-5);
	cout << b.F() << endl;
	cout << c.F() << endl;
	cout << d.F() << endl;
}
