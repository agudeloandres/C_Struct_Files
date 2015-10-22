#include "iostream.h"
#include "stdio.h"

class base {
public:
	virtual void contar() {}
	virtual int F() { return 0; }
};

class A : public base {
	int i;
public:
	A(int j=0) { i = j; }
	void contar() { i++; }
	int F() { return i; }
};

class E : public base {
	int i;
public:
	E(int j=0) { i = j; }
	void contar() { i++; }
	int F() { return i; }
};

class I : public base {
	int i;
public:
	I(int j=0) { i = j; }
	void contar() { i++; }
	int F() { return i; }
};

class O : public base {
	int i;
public:
	O(int j=0) { i = j; }
	void contar() { i++; }
	int F() { return i; }
};

class U : public base {
	int i;
public:
	U(int j=0) { i = j; }
	void contar() { i++; }
	int F() { return i; }
};

main() {
	base nada,*p;
	A a;
	E e;
	I i;
	O o;
	U u;
	cout << "De cadena de caracteres(Maximo 40 caracteres)...\n";
	char cadena[70];
	gets(cadena);
	for (int j=0; cadena[j] != '\0'; j++) {
		switch(cadena[j]) {
			case 'a': p = &a; break;
			case 'e': p = &e; break;
			case 'i': p = &i; break;
			case 'o': p = &o; break;
			case 'u': p = &u; break;
			default: p = &nada; break;
		}
		p->contar();
	}
	cout << "Vocales a= " << a.A::F() << endl;
	cout << "Vocales e= " << e.E::F() << endl;
	cout << "Vocales i= " << i.I::F() << endl;
	cout << "Vocales o= " << o.O::F() << endl;
	cout << "Vocales u= " << u.U::F() << endl;
}

