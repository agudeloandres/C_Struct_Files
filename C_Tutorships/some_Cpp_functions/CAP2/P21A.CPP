#include "stdio.h"
#include "ctype.h"
#include "conio.h"
void main()  {
	int c,i;

	for (i=0; i <=255; i++)
		if (ispunct (i))
			printf ("%c ",i);
	printf ("\n");
	getch();
}



