/* PRUEBE ESTE PROGRAMA CON UN DISCO PROTEGIDO O SIN DISCO EN LA UNIDAD A: */
#include "dos.h"
#include "io.h"
#include "string.h"
#include "conio.h"
#include "ctype.h"
#include "stdio.h"

#define CANCELE   2
#define REINTENTE 1
#define IGNORE    0


static char *errores[] = {
	"disco protegido",
	"Unidad desconocida",
	"unidad sin alistar",
	"comando desconocido",
	"error en comprobacion de redundancia ciclica",
	"pedido invalido",
	"error en busqueda",
	"error de formato",
	"sector no encontrado",
	"impresora sin papel",
	"falla en escritura",
	"falla en lectura",
	"falla general",
	"----reservado----",
	"----reservado----",
	"invalido cambio de disco"
};

int CONTESTA (char *a) {
	int resul,c;

	printf ("%s\n",a);
	c = toupper (getch());

	while ( c != 'C' && c != 'R' && c != 'I') {
		gotoxy (wherex()-1, wherey() );
		c = toupper (getch());
	}
	switch (c) {
		case 'C' :	resul = CANCELE; break;
		case 'R' :	resul = REINTENTE; break;
		case 'I' :	resul = IGNORE; break;
		default  :    	printf ("error en CONTESTA()\n"); break;
	}
	return (resul);
}

int IO_errores (int error, int a,int b,int s) {
	int unidad,errorno,devuelto;
	unsigned temp;
	char cad [150];

	temp = _DI;
	if (a < 0) {
		devuelto = CONTESTA ("Error en una unidad diferenta del disco");
		switch (devuelto) {
			case 0 : hardretn (IGNORE);break;
			case 1 : hardretn (REINTENTE);break;
			case 2 : hardresume (CANCELE);break;
		}
	}
	unidad = a & 0377;
	errorno  = temp & 0377;
	sprintf(cad,"Error: %s en unidad %c\nC)ancela: R)eintenta: I)gnora",
		errores [errorno], unidad + 'A');
	devuelto = CONTESTA (cad);
	switch (devuelto) {
		case 0 : hardretn (IGNORE);break;
		case 1 : hardretn (REINTENTE);break;
		case 2 : hardresume (CANCELE);break;
	}
	error++;b++;s++;  //Para quitar el warning
   return 0;
}


/* PRUEBE ESTE PROGRAMA CON UN DISCO PROTEGIDO O SIN DISCO EN LA UNIDAD A: */

void main() {
	int CONTESTA (char *a);
	int IO_errores (int,int,int,int);
	int id,i;
	char buffer[] = "Computadores e impresoras ";

	harderr (IO_errores);
	id = _creat("a:prueba",32);
	_write (id,(char *)buffer,10);
	_close (id);
	printf ("Oprima una tecla...\n");
	getch();
}
