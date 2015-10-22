#include "stdio.h"
#include "stdarg.h"
#include "math.h"
char *a[3] = {
		"n elevado a la m",
		"raiz cuadrada de m",
		"logaritmo en base 2 de n"
};
void Imprimir(char *formato, ...) {
	va_list p;
	va_start(p,Cualquier_Identificador);
	vprintf(formato,p);
	va_end (p);
}

void main() {
	void Imprimir(char *, ...);
	double n=2,m=5,r,s,t;
	r = pow(n,m);
	s = sqrt (m);
	t = log(n) / log(2);
	/*
	.
	.   Otras instrucciones
	.
	.
	*/
	Imprimir ("%s = %f\n%s = %f\n%s = %f\n",a[0],r,
				a[1],s,a[2],t);

}


