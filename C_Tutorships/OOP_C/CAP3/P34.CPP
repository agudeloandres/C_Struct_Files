#include "iostream.h"
#include "string.h"
#include "conio.h"

class A {
public:
	A(char *q) {
		p = new char [10];
		strcpy(p,q);
	}
	~A() {
		cout << "Destruyendo...\n";
		delete p;
	}
	char *F() { return p; }
private:
	char *p;
};

main() {
	{
		A a("hoja"),b("papel"),c("lapiz");
		cout <<  a.F() << b.F() << c.F() << endl;
	}
	getch();
}
