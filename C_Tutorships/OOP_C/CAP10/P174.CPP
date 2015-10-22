#include "iostream.h"

class A {
	int x,y;
public:
	A(int i=0,int j=0) : x(i),y(j) {}
	void operator++() {
		x++;
		y++;
	}
	void F(int &p,int &q) { p = x; q = y; }
};

main() {
	A b(1,2);
	b++;
	++b;
	int i,j;
	b.F(i,j);
	cout << i << ' ' << j << endl;
}
