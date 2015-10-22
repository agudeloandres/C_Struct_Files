#include "stdio.h"
#include "string.h"
#define PR(x)  printf ("%s\n",x)
#include "conio.h"
void main()  {
/* 1 */		char a[20],b[20];

/* 2 */		b[0] = 18;
/* 3 */		PR("De cadena");
/* 4 */		cgets (b);
/* 5 */		strcpy (a,"Cuaderno y lapiz");
/* 6 */		PR (a);
/* 7 */		PR (b+2);
/* 8 */		strcpy (a,b+2);
/* 9 */		PR (a);
/* 10 */	PR (b+2);
		getch();
}

