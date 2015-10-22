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
	int id,lea_reg (DATOS *);
	char *p;
	DATOS reg;

	if ( (id = _open ("prueba",O_WRONLY) ) == -1) {
		p = _strerror ("Error _open ()");
		PRS (p);
		getch(); exit(1);
	}
	lea_reg (&reg);
	while (reg.i != 999) {
		if (_write (id,(char *)&reg,LON) == -1) {
			p = _strerror ("Error _write()");
			PRS (p);
			getch(); exit(1);
		}
		lea_reg (&reg);
	}
	if ( _close (id) == -1) {
		p = _strerror("Error _close ()");
		PRS (p);
		getch(); exit(1);
	}
	getch();
}

int lea_reg (DATOS *p) {
	char a[10];

	PRS("De los datos del registro...");
	PRS("Codigo");
	gets (a);
	p->i = atoi (a);
	PRS("Nombre");
	gets (p->a);
   return 0;
}

