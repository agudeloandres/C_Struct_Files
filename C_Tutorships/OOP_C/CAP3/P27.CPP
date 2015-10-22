#include "iostream.h"

class X {
	double y,z;
public:
	X(double c, double d): y(c),z(d) {}
	double F(double *p) {
		*p = y;
		return z;
	}
};

main() {
	X a(3.5, 4.8);
	double d;
	cout << a.F(&d) << endl;
	cout << d << endl;
}
