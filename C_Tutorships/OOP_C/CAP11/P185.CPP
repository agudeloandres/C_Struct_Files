#include "iostream.h"
#include "string.h"

class S {
	char *p;
public:
	S(char *q = NULL) {
		p = new char [strlen(q) + 1];
		strcpy (p,q);
	}
	~S() {
		cout << "Destruye  " << endl;
		delete p;
	}
	void operator+ (S &a) {
		char *t;
		t = new char [ strlen(p) + strlen (a.p) + 1 ];
		strcpy (t,p);
		strcat (t,a.p);
		delete p;
		p = t;
	}
	char *F() { return p; }
};

main() {
	S a("alfa"), b ("beta");
	a + b;
	cout << a.F() << ' ' << b.F() << endl;
}

