#include "iostream.h"

class X {
	int a;
public:
	X(int ai) {  a = ai; }
	int F() { return a; }
};

class Y : public X {
	int b,b1;
public :
	Y(int bi) : X(bi) {
		b = bi * 10;
		b1 = bi * 100;
	}
	int G() {
		return b + b1;
	}
};

class Z : public Y {
	int c,c1;
public :
	Z(int ci) : Y(ci) {
		c = ci * 5;
		c1 = ci * 50;
	}
	int H() {
		return c + c1;
	}
};

main() {
	X a(23);
	Y b (45);
	Z c(42);
	cout << "1. " << a.F() << " " << b.F() << " " << c.F() << endl;
	cout << "2. " << b.G() << " " << c.G() << " " << c.H() << endl;
	b = c;
	a = b;
	cout << "3. " << a.F() << " " << b.F() << " " << c.F() << endl;
	cout << "4. " << b.G() << " " << c.G() << " " << c.H() << endl;
	return 0;
}