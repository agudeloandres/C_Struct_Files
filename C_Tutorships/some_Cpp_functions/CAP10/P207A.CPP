#include "stdio.h"
#include "conio.h"


#define PRS(x) printf ("%s\n",x)

void main() {
	char c;

	// Se ejecuta asi:
	// Oprimir caracter y <R>
	// Cuando se quiera finalizar, se orpime CTRL-Z

	while (!feof(stdin)) {	
		c = fgetchar ();
		fputchar(c);
	}
}
