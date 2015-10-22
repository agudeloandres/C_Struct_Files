#include "io.h"
#include "stdio.h"
#include "fcntl.h"
#include "dos.h"
#include "errno.h"
#include "conio.h"
#include "stdlib.h"

#define PRS(x) printf ("%s\n",x)

void main() {
	int id;
	long numero;
	char *p;

	if ( (numero = filelength (id) ) == -1 ) {
		p = _strerror ("Error! archivo cerrado()");
		printf ("%d\n",numero);
		PRS (p);
		getch();
		exit (1);
	}
	getch();
}
