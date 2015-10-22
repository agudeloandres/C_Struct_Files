#include "io.h"
#include "stdio.h"
#include "fcntl.h"
#include "dos.h"
#include "errno.h"
#include "conio.h"
#include "stdlib.h"

#define PRS(x) printf ("%s\n",x)

void main() {
	char *p;

	if (unlink ("prueba") == -1) {
		p = strerror (errno);
		PRS(p);
		getch();
	}
	else {
		PRS("Archivo borrado del sistema");
		getch();
	}
}
