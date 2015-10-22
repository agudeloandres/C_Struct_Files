#include "io.h"
#include "stdio.h"
#include "fcntl.h"
#include "dos.h"
#include "errno.h"
#include "conio.h"
#include "stdlib.h"

#define PRS(x) printf ("%s\n",x)

void main() {
	int i;
	char *p,antiguo[20],nuevo[20];

	PRS("De archivo a renombrar");
	gets (antiguo);
	PRS("De nuevo nombre del archivo");
	gets (nuevo);
	i = rename (antiguo,nuevo);
	if (i == -1) {
		p = strerror (errno);
		PRS (p);
		getch();
		exit (1);
	}
	getch();
}
