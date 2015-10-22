#include "io.h"
#include "stdio.h"
#include "fcntl.h"
#include "dos.h"
#include "errno.h"
#include "sys/stat.h"
#include "conio.h"
#include "stdlib.h"

#define LON sizeof (struct DATOS)
#define PR(x) printf ("%d ",x)
#define PRS(x) printf ("%s\n",x)
#define ubicar(id,x) lseek (id,(long)x * LON,SEEK_SET)
#define leer(id,x)  read (id,(char *)&x,LON)
#define grabar(id,x)  write (id,(char *)&x,LON)

struct DATOS {
	int i;
	char a[30];
};

typedef struct DATOS DATOS;


void main() {
	int id,id1,id2;
	void lea_reg (DATOS *);
	char *p;
	DATOS reg;
	int lea_entero() ;

	_fmode = O_BINARY; /* Al hacer las pruebas a este programa, se
				encontro que al trabajar los archivos
				bajo DOS con las instrucciones para UNIX,
				se debe utilizar el modo O_BINARY */


	id = creat ("prueba",S_IREAD | S_IWRITE);
	id2 = creat ("prueba2",S_IREAD | S_IWRITE);
	close (id);
	close (id2);
	id = open ("prueba",O_CREAT | O_TRUNC | O_RDWR,    S_IREAD | S_IWRITE);
	if (id==-1) {
		printf ("error apertura(id)\n");
		getch();
		exit (1);
	}
	id2=open ("prueba2",O_CREAT | O_TRUNC | O_RDWR,    S_IREAD | S_IWRITE);
	if (id2==-1) {
		printf ("error apertura(id2)\n");
		getch();
		exit (1);
	}

	id1 = dup (id2);                 					/*  1  */



	// id2 es el nuevo manejador
	dup2 (id,id2); 	  										/*  2  */



	close (id);                                     /*  3  */
	lea_reg (&reg);                                 /*  4  */
	while (reg.i != 999) {
		grabar(id2,reg);
		lea_reg (&reg);
	}
	PRS ("Datos del archivo \'prueba\'");           /*  5  */
	ubicar (id2,0);
	while (!eof (id2)) {
		leer (id2,reg);
		PR(reg.i);
		PRS (reg.a);
	}
	close (id2);
	dup2 (id1,id2);                                 /*  6  */
	close (id1);                                    /*  7  */
	PRS ("Datos del archivo \'prueba2\'");          /*  8  */
	ubicar (id2,0);
	while (!eof (id2)) {
		leer (id2,reg);
		PR(reg.i);
		PRS (reg.a);
	}
	close (id2);                                    /*  9  */
	getch();

}


void lea_reg (DATOS *p) {
	char a[10];

	PRS("De los datos del registro...");
	PRS("Codigo");
	gets (a);
	p->i = atoi (a);
	PRS("Nombre");
	gets (p->a);
}


int lea_entero() {
	char a[10];gets(a);return (atoi(a));
}
