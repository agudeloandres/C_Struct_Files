#include "iostream.h"
#include "string.h"
#include "conio.h"

class B {
	char *p;
public:
	B(char *q) {
		p = new char [ strlen(q) + 1 ];
		strcpy (p, q);
	}
	char *F() { return p; }
	~B() { delete p; }
};

main() {
	B a("alfa");
	cout << a.F() << endl;
	cout << "Oprima la barra espaciadora..." << endl;
	getch();
}

