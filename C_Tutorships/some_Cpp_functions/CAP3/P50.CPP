#include "stdio.h"
#include "conio.h"
#include "string.h"
#define PR(x) printf ("%s\n",x)

char a[] = "computadores";
char b[] = "ComputadoREs";

void main ()  {
	if (strnicmp(a,b,20) == 0 )
		PR("IGUALES");
	else PR("DIFERENTES");
	if (strncmp(a,b,20) == 0 )
		PR("IGUALES");
	else PR("DIFERENTES");
	getch();
}
