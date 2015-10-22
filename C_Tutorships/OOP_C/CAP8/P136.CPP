#include "iostream.h"
#include "string.h"

class A {
	char *p;
public:
	A() {
		p = new char [3];
		p[0] = '\0';
	}
	A(char *q) {
		p = new char [ strlen(q) + 1];
		strcpy (p,q);
	}
	char *F() { return p; }
};

main() {
	A b;
	A c("ALFA");
	cout << b.F() << endl;
	cout << c.F() << endl;
}
