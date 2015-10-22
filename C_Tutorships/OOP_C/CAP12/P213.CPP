#include "iostream.h"

class base {
	int x;
public:
	base (int i=0): x(i) {}
	int F() { return x; }
	void G() { x++; }
};

class derivada : public base {
public:
	derivada(int j) : base(j) {}
};

main() {
	derivada a(3);
	a.G();
	cout << a.F() << endl;
}
