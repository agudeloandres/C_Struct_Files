#include "stdio.h"
#include "string.h"
#include "conio.h"
#define PR(x) printf ("%s\n",x)

char a[] = "LENGUAJE TURBO C++";

void main ()  {
	strnset (a,'T',8);
	PR (a);
	strnset (a,'x',30);  /* a[], queda inicializado con 'x'  */
	getch();
}
