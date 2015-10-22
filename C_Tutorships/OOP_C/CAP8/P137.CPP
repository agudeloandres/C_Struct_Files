#include "iostream.h"
#include "string.h"

class B {
	char *p;
public:
	B() {}
	B(char *q) {
		p = new char [ strlen(q) + 1];
		strcpy (p,q);
	}
	void F(char *q) {
		p = new char [ strlen(q) + 1];
		strcpy (p,q);
	}
	char *G() { return p; }
};

main() {
	B a[5];
	B c[5] =  { "uno","dos","tres","cuatro","cinco" };
	a[0].F("blanco");
	a[1].F("");
	a[2].F("rojo");
	a[3].F("azul");
	a[4].F("verde");
	for (int i = 0; i < 5; i++)
		cout << a[i].G() << endl;
	for (i = 0; i < 5; i++)
		cout << c[i].G() << endl;
}
