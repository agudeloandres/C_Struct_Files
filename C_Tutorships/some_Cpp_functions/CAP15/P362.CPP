#include "dos.h"
#include "stdio.h"
#include "conio.h"

#undef peek

void main() {
	int i,j;
	char a[20];

	for (i = 0; i < 10; i++)
		a [i]  = peek (0xb000,0x0 + i * 2);
	a[i] = '\0';
	printf ("%s\n",a);
	getch();
}




