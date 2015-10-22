#include "io.h"
#include "stdio.h"
#include "fcntl.h"
#include "dos.h"
#include "errno.h"
#include "conio.h"
#include "stdlib.h"

#define LON sizeof (struct DATOS)
#define PR(x) printf ("%d ",x)
#define PRS(x) printf ("%s\n",x)

struct DATOS {
	int i;
	char a[30];
};

typedef struct DATOS DATOS;


void main() {
	int id;
	char *p;
	DATOS reg;


	id = _open ("prueba",O_RDONLY);
	while (!eof (id)) {
		if (_read (id,(char *)&reg,LON) == -1) {
			p = _strerror ("Error _read ()");
			PRS (p);
			getch(); exit(1);
		}
		PR(reg.i);
		PRS (reg.a);
	}
	if ( _close (id) == -1) {
		p = _strerror("Error _close ()");
		PRS (p);
		getch(); exit(1);
	}
	getch();
}

