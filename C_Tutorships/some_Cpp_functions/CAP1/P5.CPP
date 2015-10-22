#include "stdio.h"
#include "conio.h"

void main() {

/* 1 */		char a[22];

/* 2 */		a[0] = 20;
/* 3 */		printf ("De cadena\n");
/* 4 */		cgets(a);
/* 5 */		printf ("\n%d %d %s\n",a[0],a[1],a+2);
/* 6 */		getch();

}

