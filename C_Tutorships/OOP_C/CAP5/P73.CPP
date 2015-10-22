#include "iostream.h"
#include "string.h"

class A {
	char *p;
	int lon;
public:
	A(char *q) {
		lon = strlen (q);
		p = new char [lon+1];
		strcpy (p,q);
	}
	friend class B;
};

class B {
public:
	B() {}
	char *H(A b) { return b.p; }
	int I(A b) { return b.lon; }
};

main() {
	A b("alfa");
	B c;
	cout << c.H(b) << endl;
	cout << c.I(b) << endl;
}