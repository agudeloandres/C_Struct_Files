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
	char *p;

	if ( (id = _creat ("prueba",FA_ARCH) ) == -1) {
		p = _strerror ("Error _creat()");
		PRS (p);
		getch(); exit(1);
	}
	_close (id);
	getch();
}
