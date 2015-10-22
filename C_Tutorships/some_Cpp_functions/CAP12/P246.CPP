#include "stdio.h"
#include "fcntl.h"
#include "io.h"
#include "time.h"
#include "dos.h"
#include "errno.h"
#include "conio.h"
#include "string.h"
#include "stdlib.h"

#define LON sizeof (struct X)
struct X {
	long numero[80];
	char a[50];
	float x [80];
};

void main() {
	struct X dato;
	int i,id;
	time_t t1,t2;
	double d;
	void error();

	for (i = 1; i < 80; i++) {
		dato.numero [i] = 56723L;
		dato.x [i] = 3.4567;
	}

	id = _creat ("a:prueba",FA_ARCH);
	if (id == -1) error();
	_close (id);

	id = _open ("a:prueba",O_WRONLY);
	if (id == -1) error();
	strcpy (dato.a,"prueba");
	for (i = 1; i < 100; i++)
		if (_write(id, (char *)&dato,LON) != LON) error();
	close (id);
	if (id == -1) error();


	id = _open ("a:prueba",O_RDWR);
	if (id == -1) error();
	i = time (&t1);   		/* Hora antes del lseek() */
	if (lseek (id, (long)60 * LON,SEEK_SET) == -1) error();
	if (_read (id,(char *)&dato,LON) != LON) error();
	dato.numero [0] = 0;
	if (lseek (id, (long)60 * LON,SEEK_SET) == -1) error();
	if (_write (id,(char *)&dato,LON) != LON) error();

	i = time (&t2);		/* Hora despues del lseek */
	d = difftime (t2,t1);
	printf ("Tiempo gastado por la actualizacion = %10.7lf segundos\n",d);


	_close (id);
	getch();
}

void error () {
	printf ("%s\n",strerror(errno)  );
	getch();
	exit(1);
}




