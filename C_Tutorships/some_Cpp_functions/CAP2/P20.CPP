#include "stdio.h"
#include "ctype.h"
#include "conio.h"
void main()  {
	int c;

	c = getch();
	if (islower (c))
		printf ("Es una letra minuscula\n");
	else printf ("No es una letra minuscula\n");
	getch();
}



