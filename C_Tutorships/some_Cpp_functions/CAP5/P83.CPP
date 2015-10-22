// Este programa utiliza la clase complex del C++
// Esta diferente al escrito en el libro.
// Favor estudiarlo con detenimiento


#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
#include "complex.h"
void main() {
	char a[15],*p,*q;

	double x,y;
	double valor;

	printf ("De la parte real del numero...\n");
	gets (a);
	x = strtod (a, &p);
	while (*p != '\0') {
		printf ("Cifra errada. Rectifique... %c\n",7);
		gets (a);
		x = strtod (a,&p);
	}
	printf ("De la parte imaginaria del numero...\n");
	gets (a);
	y = strtod (a, &p);
	while (*p != '\0') {
		printf ("Cifra errada. Rectifique... %c\n",7);
		gets (a);
		y = strtod (a,&p);
	}
// Crea un complejo utilizando la clase complex del C++

	class complex c(x,y);

// Calcula el valor absoluto del complejo c, invocando la funcion
// amiga abs() de la clase complex

	valor = abs (c);
	printf ("El valor absoluto de (%lf) + (%lf)i es  %lf\n",
			real(c), imag(c), valor);
	getch();
}



