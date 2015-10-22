#include "iostream.h"

class A {
	int *p;
public:
	A(int i) { p = new int [i]; }
	int P(int i) { return p [i]; }
	~A() { delete p; }
	void F(int i, int j) { p[i] = j; }
};

main() {
	A x(5);
	{
		A y(10);
		for (int i=0; i < 10; i++)
			y.F(i,3);
		for (i=0; i < 10; i++)
			cout << y.P(i) << endl;
	}
	// Llamada a desctructor para el objeto y
	for (int i=0; i < 5; i++)
		x.F(i,2);
	for (i=0; i < 5; i++)
		cout << x.P(i) << endl;
	// Llamda al destructor para el objeto x
}
