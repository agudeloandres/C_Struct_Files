#include "iostream.h"

class A {
	int x,y;
public:
	A() {}
	A (int i,int j) : x(i), y(j) {}
	A &operator=(A &b) {
		x = b.x;
		y = b.y;
		return *this;
	}
	void F(int &p,int &q) { p = x; q = y; }
	~A() { cout << "d\n"; }
};

main() {
	A b(1,2),d,c;
	c = d = b;
	int i,j;
	b.F(i,j);
	cout << i <<  ' ' << j << endl;
	c.F(i,j);
	cout << i <<  ' ' << j << endl;
	d.F(i,j);
	cout << i <<  ' ' << j << endl;
}

