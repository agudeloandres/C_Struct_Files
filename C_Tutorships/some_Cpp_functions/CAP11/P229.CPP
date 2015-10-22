#include "stdio.h"
#include "dir.h"
#include "conio.h"
#include "stdlib.h"

#define PRS(x)  printf ("%s",x)
#define SALTO  printf ("\n")

void main() {
	char *q;
	int i;

	i = getdisk();
	PRS("La unidad de trabajo es ");
	printf ("%c:",i + 'a');
	SALTO;
	getch();
}


