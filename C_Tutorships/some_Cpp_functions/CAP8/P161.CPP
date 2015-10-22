#include "io.h"
#include "stdio.h"
#include "fcntl.h"
#include "dos.h"
#include "errno.h"
#include "conio.h"
#include "stdlib.h"

#define LON 7
#define PRS(x) printf ("%s\n",x)

char b[] = "HOJAS Y LAPICES";

void main() {
	int id,i;
	char *p,x[20];

	if ( (id = _creat ("prueba1",FA_ARCH)) == -1) {
		p = _strerror("Error _creat ()");
		PRS (p);
		getch(); exit(1);;
	}
	if ( _close (id) == -1) {
		p = _strerror("Error _close ()");
		PRS (p);
		getch(); exit(1);
	}
	if ( (id = _open ("prueba1",O_WRONLY) ) == -1) {
		p = _strerror ("Error _open ()");
		PRS (p);
		getch(); exit(1);
	}
	if (_write (id,b,LON) != LON) {
		p = _strerror ("Error _write()");
		PRS (p);
		getch();
		exit(1);
	}
	if ( _close (id) == -1) {
		p = _strerror("Error _close ()");
		PRS (p);
		getch(); exit(1);
	}
	if ( (id = _open ("prueba1",O_RDONLY) ) == -1) {
		p = _strerror ("Error _open ()");
		PRS (p);
		getch(); exit(1);
	}
	if ((i = _read (id,x,LON)) != LON) {
		p = _strerror ("Error _read ()");
		PRS (p);
		getch(); exit(1);
	}
	x[i] = '\0';  /* La instruccion _read, no asigna '\0'  */
	PRS(x);
	if ( _close (id) == -1) {
		p = _strerror("Error _close ()");
		PRS (p);
		getch(); exit(1);
	}
	getch();
}

