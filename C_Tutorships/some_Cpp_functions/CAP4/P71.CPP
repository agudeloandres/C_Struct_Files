#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
unsigned long lea_unsigned () {
	char a[15],*p;
	unsigned long x;

	gets (a);
	x = strtoul (a, &p,10);  /* Acepta la cadena en base 10 */
	while (*p != '\0') {
		printf ("Cifra errada. Favor rectifique... %c\n",7);
		gets (a);
		x = strtoul (a,&p,10); /* La base debe estar entre 2-36 */
	}
	return (x);
}

void main() {
	unsigned long i,lea_unsigned ();

	i = lea_unsigned ();
	printf ("%lu\n",i);
	getch();
}



