#include "iostream.h"

class C {
	int x;
public:
	C(int i) : x(i) {}
	int F() { return x; }
    void G (C &);
	~C() { cout << "Destruyendo..." << endl; }
};

void C::G(C &y) {
	(y.x)++;
}

main() {
	C a(10),d(-1);
	d.G(a);
	cout << a.F() << endl;
}
