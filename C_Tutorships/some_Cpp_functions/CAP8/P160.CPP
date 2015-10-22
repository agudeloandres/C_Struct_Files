#include "io.h"
#include "stdio.h"
#include "fcntl.h"
#include "dos.h"
#include "errno.h"
#define PRS(x) printf ("%s\n",x)
#include "conio.h"
#include "stdlib.h"

void main() {
	int id;
	char *p;

	if ( (id = _open ("prueba",O_WRONLY) ) == -1) {
		p = _strerror ("Error _open ()");
		PRS (p);
		getch(); exit(1);
	}
	_close(id);
	getch();
}
