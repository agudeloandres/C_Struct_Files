#include "iostream.h"
#include "mem.h"
#include "stdio.h"
void main() {
	char *p,*q;
	int i;
	p = new char [30];
	cout << "De cadena de caracteres <Maximo 29> " << endl;
	gets (p);
	q = (char *)memset(p,'&',10);
	cout << q << endl << p << endl;
	delete p;
}


