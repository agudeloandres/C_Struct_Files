#include "iostream.h"
#include "mem.h"
#include "string.h"
#include "stdio.h"
#include "conio.h"
void main() {
	char *p,*q;
	p = new char [30];
	strcpy (p,"calculadora");

	strcat (p + strlen (p) + 1,"computadores");
	q = (char *)memchr (p,'t',200);
	cout << q << endl;
	delete p;
	getch();
}



