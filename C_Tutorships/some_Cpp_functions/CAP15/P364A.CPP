#include "dos.h"
#include "stdio.h"
#include "conio.h"

void main() {
	int i;

	if (kbhit() )
		printf ("Si existe caracter\n");
	else printf ("No existe caracter\n");


	while (!kbhit())   // Continua hasta que se oprima una tecla....
   	;
}




