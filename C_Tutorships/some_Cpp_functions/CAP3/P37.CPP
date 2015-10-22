#include "stdio.h"
#include "string.h"
#define PR(x) printf ("%s\n",x)
#include "conio.h"
void main()  {
	char a[20],b[20],*p;

	strcpy (a,"123");
	strcpy (b,"LAPICERO");

	p = strcpy (a,b);
	PR(p);  		/* Escribe la cadena "LAPICERO"  */
	p = stpcpy (a,b); 	
	PR(p);			/* No escribe nada */
	getch();

}



