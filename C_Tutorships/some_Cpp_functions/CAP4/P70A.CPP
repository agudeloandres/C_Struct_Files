#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
long lea_long () {
	char a[15],*p;
	long x;

	gets (a);
	x = strtol (a, &p,10);  /* Acepta la cadena en base 10 */
	while (*p != '\0') {
		printf ("Cifra errada. Favor rectifique... %c\n",7);
		gets (a);
		x = strtol (a,&p,10);
	}
	return (x);
}

void main() {
	long i,lea_long();

	i = lea_long();
	printf ("%ld\n",i);
	getch();
}



