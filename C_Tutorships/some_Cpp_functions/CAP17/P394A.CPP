#include "iostream.h"
#include "mem.h"
#include "stdio.h"
void main() {
	char *p,*q;
	p = new char [30];
	q = new char [30];
	cout << "De cadena de caracteres <Maximo 29> " << endl;
	gets (p);
	cout << "De cadena de caracteres <Maximo 29> " << endl;
	gets (q);

	memcpy (p,q,10);
	cout << p << endl;
	delete p;
	delete q;
}


