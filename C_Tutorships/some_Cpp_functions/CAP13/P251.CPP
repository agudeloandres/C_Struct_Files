#include "stdio.h"
#include "alloc.h"
#include "string.h"
#include "conio.h"
#include "stdlib.h"
#define PR(x)  printf ("%s\n",x)
#define Localizar (struct Y *) malloc (sizeof (struct Y) )

struct Y {
	int i;
	char a[20];
};

void main() {
	struct Y *p;

	p = Localizar;
	if (p == NULL) {
		PR("No existe memoria dinamica..");
		getch();
		exit(1);
	}

	/* Notacion -> */

	p->i = 234;
	strcpy (p->a,"Calculadora");

	/* Notacion * */

	(*p).i++;
	strcat ( (*p).a,"s");

	printf ("%d %s",p->i,p->a);
	getch();
}
