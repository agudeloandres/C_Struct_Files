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
	S &operator=(S &a) {
		cad->cont--;
		a.cad->cont++;
		if(cad->cont == 0) {
			delete cad->p;
			delete cad;
		}
		cad = a.cad;
		return *this;
	}
	S operator+(S &);
	char *F(int *t) { return cad->G(t); }
};
S S::operator+(S &a) {
	S t;
	delete t.cad->p;
	t.cad->p = new char [strlen (cad->p) + strlen (a.cad->p) + 1];
	strcpy (t.cad->p,cad->p);
	strcat (t.cad->p,a.cad->p);
	return t;
}
main() {
	S b("alfa"), c("beta"),d;
	d = b + c;
	int i;
	cout << b.F(&i) << " ";
	cout << i << endl;
	cout << c.F(&i) << " ";
	cout << i << endl;
	cout << d.F(&i) << " ";
	cout << i << endl;
	S e = c;
	S f(e);
	c = e + f;
	cout << b.F(&i) << " ";
	cout << i << endl;
	cout << c.F(&i) << " ";
	cout << i << endl;
	cout << d.F(&i) << " ";
	cout << i << endl;
	cout << e.F(&i) << " ";
	cout << i << endl;
	cout << f.F(&i) << " ";
	cout << i << endl;
}
