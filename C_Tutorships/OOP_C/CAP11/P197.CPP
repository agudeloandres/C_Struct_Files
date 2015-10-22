#include "iostream.h"
#include "string.h"
class M {
	int cont;
	char *p;
public:
	M(char *q = NULL) {
		p = new char [strlen(q) + 1];
		strcpy (p,q);
		cont = 1;
	}
	char *G(int *t) {
		*t = cont;
		return p;
	}
	friend class S;
};
class S {
	M *cad;
public:
	S (char *q = NULL) { cad = new M (q); }
	S (S &a) {
		cad = a.cad;
		cad->cont++;
	}
	~S() {
		cout << "Destruyendo...\n";
		cad->cont--;
		if (cad->cont == 0) {
			delete cad->p;
			delete cad;
		}
	}
	char *F(int *t) { return cad->G(t); }
};
main() {
	S a("alfa");
	S b = a;
	S c = b;
	S d ("beta");
	int i;
	cout << a.F(&i) << " ";
	cout << i << endl;
	cout << b.F(&i) << " ";
	cout << i << endl;
	cout << c.F(&i) << " ";
	cout << i << endl;
	cout << d.F(&i) << " ";
	cout << i << endl;
}

