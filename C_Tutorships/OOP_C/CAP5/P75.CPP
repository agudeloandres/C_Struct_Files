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
	char *F(A a) { return a.p; }
	int G(A a) { return a.lon; }
public:
	B() {}
	char *H(A b) { return F(b); }
	int I(A b) { return G(b); }
};

main() {
	A b("alfa");
	B c;
	cout << c.H(b) << endl;
	cout << c.I(b) << endl;
}



