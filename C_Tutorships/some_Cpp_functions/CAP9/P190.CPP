#include "io.h"
#include "stdio.h"
#include "fcntl.h"
#include "dos.h"
#include "errno.h"
#include "sys\stat.h"
#include "conio.h"
#include "stdlib.h"
#define PRS(x) printf ("%s\n",x)

void main() {
	char *p;

	if ( chmod("prueba",S_IREAD)  == -1) {
		p = strerror (errno);
		PRS(p);
		getch();
		exit (1);
	}
	getch();
}
