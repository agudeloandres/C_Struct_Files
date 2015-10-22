#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"

void main() {              /* Para este ejemplo, usamos la funcion cgets() */
	char a[15],*p,*q;
	double seno_h, coseno_h, x, UNO;

	a[0]=8;
	printf ("De un angulo medido en radianes.....\n");
	cgets (a);
	x = strtod (a+2, &p);
	while (*p != '\0') {
		printf ("Cifra errada. Rectifique... %c\n",7);
		cgets (a);
		x = strtod (a+2,&p);
	}
	printf ("\n");
	seno_h = sinh (x);
	coseno_h = cosh (x);
	UNO = coseno_h * coseno_h - seno_h * seno_h;

	/* fabs() calcula el valor absoluto de un numero de tipo double */
	/* Esta funcion se estudia mas adelante */

	if (fabs (UNO - 1.0) > 0.0001) /* Para comparar con 0.0 */
		printf ("He descubierto una nueva identidad!\n");
	else printf ("No he descubierto nada.\n");
	printf ("Valor calculado: %30.19lf\n",UNO);
	getch();
}



