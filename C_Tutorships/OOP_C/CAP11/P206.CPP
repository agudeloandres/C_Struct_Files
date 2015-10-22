#include "iostream.h"
#include "stdlib.h"		// malloc(), free()
#include "string.h"
class A {
	int x,y;
public:
	void asignar (int i, int j) { x = i; y = j; }
	void *operator new (size_t lon) {
		return (void *)malloc (lon);
	}
	void operator delete (void *p) {
		cout << "Liberando objeto A\n";
		free (p);
	}
	int F() { return x + y; }
};
class B {
	double x,y;
	char *p;
	float ele,eme;
public:
	void asignar (double i,double j,float a,float b,char *q) {
		x = i;
		y = j;
		p = new char [strlen(q) + 1];
		strcpy (p,q);
		ele = a;
		eme = b;
	}
	void *operator new (size_t lon) {
		return (void *)malloc (lon);
	}
	void operator delete (void *t) {
		cout << "Liberando objeto B\n";
		free (t);
	}
	double F(float *t,char **q) {
		*t = ele + eme;
		*q = p;
		return x + y;
	}
};
main() {
	{
		A *p;
		p = new A;
		p->asignar (1,5);
		cout << p->F() << endl;
		delete p;
	}
	{
		B *p;
		char *q;
		q = new char [30];
		strcpy (q,"Estos son los datos...");
		float f;
		double d;
		p = new B;
		p->asignar (1.1,2.2,3.3,4.4,q);
		delete q;
		d = p->F(&f, &q);
		cout << q <<  ' ' << d << ' ' << f << endl;
		delete p;
	}
}
