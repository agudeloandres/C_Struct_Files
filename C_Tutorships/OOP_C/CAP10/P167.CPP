#include "iostream.h"

class A {
	int x,y;
public:
	A (int i=0,int j=0) {
		x = i; y = j;
	}
	A operator+= (A &b) {
		x = x + b.x;
		y = y + b.y;
		return *this;
	}
	void F(int *p, int *q) { *p = x; *q = y; }
	~A() {}
};

main() {
	A c(1,2),d(3,4),e(4,5);
	c += d += e;
	int i,j;
	e.F(&i,&j);
	cout << i << ' ' << j << endl;
	d.F(&i,&j);
	cout << i << ' ' << j << endl;
	c.F(&i,&j);
	cout << i << ' ' << j << endl;
}
