#include "stdio.h"
#include "ctype.h"
#include "conio.h"
void main()  {
	unsigned int c1;

	c1 = 23;
	if (isascii (c1))
		printf ("VERDADERO\n");
	else printf ("FALSO\n");
	getch();
}

