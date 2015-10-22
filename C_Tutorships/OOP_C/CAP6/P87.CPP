#include "iostream.h"
#include "string.h"
class A {
	char *p;
public:
	A(char *q) {
		cout << "Construyendo...\n";
		p = new char[strlen(q) + 1];
		strcpy (p,q);
	}
	char *F() { return p; }
	void H(A c) {
		strcpy (p,"5678");
		strcpy (c.p,"algo");
	}
	~A() {
		cout << "Destruyendo " << p << endl;
		delete p;
	}
};
main() {
	A x("Alfa"),y("nada");
	y.H(x);
	cout << x.F() << endl;
	cout << y.F() << endl;
	cout << "--------\n";
}

