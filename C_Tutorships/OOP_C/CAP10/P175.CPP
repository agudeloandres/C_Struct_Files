#include "iostream.h"

class A {
	int x,y;
public:
	A(int i=0,int j=0) : x(i),y(j) {}
	A &operator++() {
		x++;
		y++;
		return *this;
	}
	void F(int &p,int &q) { p = x; q = y; }
};

main() {
	A b(1,2),c;
	c = b++;
	int i,j;
	b.F(i,j);
	cout << i << ' ' << j << endl;
	c.F(i,j);
	cout << i << ' ' << j << endl;
}

