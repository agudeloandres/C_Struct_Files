#include "iostream.h"
class A {
	int x,y;
public:
	A(int i=0,int j=0) { x = i; y = j; }
	int F(int *p) {
		*p = y;
		return x;
	}
	A operator+(A &);
	A operator-(A &);
};
A A::operator+ (A &b) {
	A t;
	t.x = x + b.x;
	t.y = y + b.y;
	return t;
}
A A::operator- (A &b) {
	A t;
	t.x = x - b.x;
	t.y = y - b.y;
	return t;
}
main() {
	A b(1,2),c(3,4),d,f(9,2),h(4,5);
	int j;
	d = b + c - f + h;
	cout << d.F(&j) << endl;
	cout << j << endl;
}