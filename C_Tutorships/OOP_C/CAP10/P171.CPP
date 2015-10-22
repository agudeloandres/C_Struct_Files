#include "iostream.h"

class A {
	int x,y;
public:
	A() {}
	A (int i,int j) : x(i), y(j) {}
	A operator=(A &b) {
		x = b.x;
		y = b.y;
		return *this;
	}
	void F(int &p,int &q) { p = x; q = y; }
};

main() {
	A b(1,2),c,d,e,f;
	c = b;
	d = e = f = c;
	int i,j;
	b.F(i,j);
	cout << i <<  ' ' << j << endl;
	c.F(i,j);
	cout << i <<  ' ' << j << endl;
	d.F(i,j);
	cout << i <<  ' ' << j << endl;
	e.F(i,j);
	cout << i <<  ' ' << j << endl;
	f.F(i,j);
	cout << i <<  ' ' << j << endl;
}

