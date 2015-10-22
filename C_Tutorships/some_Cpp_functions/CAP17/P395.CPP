#include "iostream.h"
#include "mem.h"
#include "stdio.h"
void main() {
	char *p,*q;
	int i;
	p = new char [30];
	q = new char [30];
	cout << "De cadena de caracteres <Maximo 29> " << endl;
	gets (p);
	cout << "De cadena de caracteres <Maximo 29> " << endl;
	gets (q);
	i = memcmp (p,q,3);  // i se debe definir con signo
	if (i==0)
		cout << "cadenas iguales\n";
	else if (i > 0)
		cout << "cadena p mayor que cadena q\n";
	else
		cout << "cadena p menor que cadena q\n";
	delete p;
	delete q;
}


