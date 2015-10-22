#include "iostream.h"
#include "conio.h"

class A {
	float x,y,z;
public:
	A(float u,float v) { x = y = u; z = v; }
	void F(float *p,float *q,float *r) {
		*p = x + *p;
		*q = y + *q;
		*r = z + *r;
	}
};

main() {
	A x(8,2), y(10,20), z(-1,-2);
	float s=0,t=0,u=0;
	x.F(&s,&t,&u);
	y.F(&s,&t,&u);
	z.F(&s,&t,&u);
	cout << "s= " << s << endl;
	cout << "t= " << t << endl;
	cout << "u= " << u << endl;
	getch();
}
