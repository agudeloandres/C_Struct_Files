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
	S S::operator+ (S &);
	S &operator= (S &a) {
		delete p;
		p = new char [strlen(a.p) + 1];
		strcpy (p,a.p);
		return *this;
	}
	char *F() { return p; }
};

S S::operator+ (S &a) {
	S t;
	delete t.p;
	t.p = new char [ strlen(p) + strlen (a.p) + 1 ];
	strcpy (t.p,p);
	strcat (t.p,a.p);
	return t;
}

main() {
	S a("alfa"), b ("beta"),c;
	c = a + b;
	cout << a.F() << ' ' << b.F() << ' ' << c.F() << endl;
	cout << "--------\n";
}
