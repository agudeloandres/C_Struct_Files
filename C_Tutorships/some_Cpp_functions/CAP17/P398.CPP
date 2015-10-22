#include "iostream.h"
#include "mem.h"
#include "stdio.h"
void main() {
	char *p,*q;
	int i;
	p = new char [30];
	cout << "De cadena de caracteres <Maximo 29> " << endl;
	gets (p);
	memmove (p+3,p,10);
	cout << p << endl;
	delete p;
}


