#include "iostream.h"
class A {
	int y;
public:
	A() {};
	void F(int i) { y = i; }
	int G() { return y; }
};
main() {
	A x;
	x.F(3);
	cout << x.G() << endl;
}