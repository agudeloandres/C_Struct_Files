#include "dos.h"
#include "conio.h"
#include "stdio.h"

void main() {
	unsigned int i;

	i = getpsp();
	if (i != _psp)
		printf ("Error. Estas variables deben ser iiguales\n");
	else printf ("Correcto\n");
	getch();
}