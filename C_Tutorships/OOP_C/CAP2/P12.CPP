#include "iostream.h"

struct X {
	int i;
	char c;
};

main() {
	struct X *p;
	p = new struct X;
	if (p == NULL) {
		cout << "Memoria insuficiente...\n";
		return 1;
	}
	p->i = 10;
	p->c = 'A';
	cout << p->i << " " << p->c << endl;
	delete p;
}