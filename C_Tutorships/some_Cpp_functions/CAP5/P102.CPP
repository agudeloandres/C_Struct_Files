#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
#define MAXIMO 10
#define SALTO printf ("\n")

void main() {
	double x,R,coefi [MAXIMO];
	long li;
	char a[15],*p;
	int j;

	a[0] = 13;
	printf ("Por favor, informe el grado del polinomio..\n");
	cgets (a);
	li = strtol (a+2, &p, 10);
	while (*p != '\0' || li < -32768L || li > 32767L) {
		printf ("%c",7);  		/* Aviso de error */
		printf ("Cifra incorrecta. Favor rectifique...\n");
		cgets (a);
		li = strtol (a+2,&p,10);
	}
	SALTO;
	j = li;
	while (j >= 0) {
		printf ("Digite el coeficiente..\n");
		cgets (a);
		x = strtod (a+2, &p);
		while (*p != '\0' || a <= 0) {
			printf ("%c",7);  		/* Aviso de error */
			printf ("Cifra incorrecta. Favor rectifique...\n");
			cgets (a);
			x = strtod (a+2,&p);
		}
		coefi [j--] = x;
		SALTO;
	}
	printf ("Lea el valor de X..\n");
	cgets (a);
	x = strtod (a+2, &p);
	while (*p != '\0') {
		printf ("%c",7);  		/* Aviso de error */
		printf ("Cifra incorrecta. Favor rectifique...\n");
		cgets (a);
		x = strtod (a+2,&p);
	}
	R = poly (x, (int)li, coefi);
	printf ("\n");
	printf ("El valor del polinomio, para X = %lf es %lf\n",x,R);
	getch();
}



