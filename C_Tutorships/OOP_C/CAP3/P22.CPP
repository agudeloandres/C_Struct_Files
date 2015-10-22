#include "iostream.h"

class B {
	int x;
	int F() { return x; }
public:
	B() {}
	void G(int i) { x = i; }
	int H() { return F(); }
};

main() {
	B b;
	int i;
	cin >> i;
	b.G(i);
	cout << b.H() << endl;
}