#include "stdio.h"
#include "string.h"
#include "conio.h"
void main ()  {
	char a[20],*p,b[20];

	strcpy (a,"ALFA");
	strcpy (b,"BETA");
	p = strcat (a,b);
	printf ("%s %s\n",p,a); /* p queda con el valor de a */
	getch();
}



