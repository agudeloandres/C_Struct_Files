#include "iostream.h"

class A {
	float x,y;
public:
	A (float i=0,float j=0) {
		x = i; y = j;
	}
	A operator+= (A &b) {
		x = x + b.x;
		y = y + b.y;
		return *this;

	}
	A operator-= (A &b) {
		x = x - b.x;
		y = y - b.y;
		return *this;

	}
	A operator*= (A &b) {
		x = x * b.x;
		y = y * b.y;
		return *this;

	}
	A operator/= (A &b) {
		x = x / b.x;
		y = y / b.y;
		return *this;

	}
	void F(float *p, float *q) { *p = x; *q = y; }
	~A() {}
};

main() {
	A c(1,2),d(3,4),e(4,5);
	c *= c;
	d -= e;
	c /= d *= e;
	float i,j;
	e.F(&i,&j);
	cout << i << ' ' << j << endl;
	d.F(&i,&j);
	cout << i << ' ' << j << endl;
	c.F(&i,&j);
	cout << i << ' ' << j << endl;
}


