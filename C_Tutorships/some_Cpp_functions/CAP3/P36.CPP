#include "stdio.h"
#include "string.h"
#define PR(x) printf ("%s\n",x)
#include "conio.h"
char a[] = "PAPEL Y LAPIZ";
char b[] = "L Y LA";

void main ()  {
	char *c;

	c = strstr (a,b);
	PR (c);
	PR (a);
	PR (b);
	getch();
}
