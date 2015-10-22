#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
char *a[] = {
	"Esteban",
	"Dario",
	"Mireya",
	"Nubia",
	"Gustavo Adolfo",
	"Julio",
	"Carlos",
	"Helena",
	"Sebastian",
	"Nicolai",
	"Daniel"
};

void main() {
	int i;

	/* Si se necesita escoger un nombre aleatoriamente
		lo podemos hacer de la siguiente forma: */

	randomize(); /* Reinicializa el generador de numeros aleatorios */
	i = rand(); /* Numero aleatorio de 0-32767 */
	i = i % 11; /* i = numero entre 0 y 10 */
	printf ("%d %s\n",i,a[i]);
	getch();
}





