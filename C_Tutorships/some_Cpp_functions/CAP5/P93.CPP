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
	"Daniel",
	"Carolina",
	"Hugo",
	"Sandra",
	"Cristina",
};

void main() {
	int i,numero;

	/* Si se necesita escoger un nombre aleatoriamente
		lo podemos hacer de la siguiente forma: */

	randomize(); /* Reinicializa el generador de numeros aleatorios */
	for (i = 1; i <=20; i++) {
		numero = random (15);
		printf ("%2d %s\n",numero, a[numero]);
	}
	getch();
}
