#include "iostream.h"
#include "string.h"

class B {
	char *p;
public:
	B (char *q) {
		p = new char [strlen (q)+1];
		strcpy (p,q);
	}
	B (B &c) {
		delete p;
		p = new char [strlen (c.p) + 6];
		strcpy (p,c.p);
		strcat (p,"Aqui");
	}
	~B() {
		cout << "Destruyendo" << endl;
		delete p;
	}
	char *F() { return p; }
};

void main() {
	B a("Alfa");
	B b(a);
	cout << a.F() << endl;
	cout << b.F() << endl;
}
