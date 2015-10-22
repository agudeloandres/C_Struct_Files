#include "stdio.h"
#include "stdarg.h"
#include "math.h"
#include "conio.h"
char *a[3] = {
		"n elevado a la m",
		"raiz cuadrada de m",
		"logaritmo en base 2 de n"
};
void Imprimir(char *cadena,char *formato, ...) {
	va_list p;
	va_start(p,Cualquier_Identificador);
	vsprintf(cadena,formato,p);
	va_end (p);
}

void main() {
	clrscr();
	char *cadena;
	void Imprimir(char *,char *, ...);
	double n=5,m=4,r,s,t;
	r = pow(n,m);
	s = sqrt (m);
	t = log(n) / log(2);
	/*
	.
	.   Otras instrucciones
	.
	.
	*/
	cadena = new char [100];
	Imprimir (cadena,"%s = %f\n%s = %f\n%s = %f\n",a[0],r,
				a[1],s,a[2],t);
	printf ("%s\n",cadena);
	delete cadena;
}


