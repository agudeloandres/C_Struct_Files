

/* tablero.c - escribe un minitablero de ajedrez con asteriscos
**
** Pablo A. Straub
** Viernes 14 de marzo de 1997
**
** El minitablero tiene 4 cuadrados de 3 caracteres cada uno.
** Para determinar si una posicion (f,c) debe tener un asterisco
** o un espacio en blanco se considera si la paridad de f/3 es
** igual a la paridad de c/3.  La paridad se averigua usando el
** el operador modulo (%) de 2.
*/

#include <stdio.h>

void main ()
{
    int f, c;

    for (f = 0; f < 3 * 4; f++) {
	for (c = 0; c < 3 * 4; c++)
	    if (c / 3 % 2 == f / 3 % 2)
		printf("*");
	    else
		printf(" ");
	printf("\n");
    }
}
