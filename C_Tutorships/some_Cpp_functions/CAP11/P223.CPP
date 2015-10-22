#include "stdio.h"
#include "dir.h"
#include "dos.h"
#include "conio.h"
#include "stdlib.h"

#define PRS(x)  printf ("%s",x)
#define SALTO  printf ("\n")

struct t1 {
	unsigned segundos : 5;
	unsigned minutos : 6;
	unsigned horas : 5;
};

union TIEMPO {
	unsigned tiempo;
	struct t1 t1;
};

struct f1 {
	unsigned dia : 5;
	unsigned mes : 4;
	unsigned ano :7;
};

union FECHA {
	unsigned fecha;
	struct f1 f1;
};


/* En este programa, el nombre del archivo a buscar , se informa
	a traves de una linea de comandos.  Si en la linea de
	comandos se escribe *.*, encontrara el primer archivo */


void main(int argc, char *argv[]) {
	char *q;
	struct ffblk p;
	union TIEMPO tiempo;
	union FECHA fecha;

	if (argc != 2) {
		PRS ("Linea de comandos errada..");
		getch(); exit (1);
	}
	PRS("Archivo a buscar: ");
	PRS(argv [1]);
	SALTO;
	if (findfirst (argv [1],&p,FA_ARCH) == -1) {
		q = _strerror ("Error en findfirst ()");
		PRS(q);
		getch(); exit (1);
	}
	tiempo.tiempo = p.ff_ftime;
	fecha.fecha = p.ff_fdate;
	PRS("Datos del archivo buscado: ");
	SALTO;
	printf ("Atributo: %d\n",p.ff_attrib);
	printf ("Hora(h/m/s): %u %u %u\n",tiempo.t1.horas,tiempo.t1.minutos,
			tiempo.t1.segundos / 2);
	printf ("Fecha(a/m/d): %u %u %u\n",fecha.f1.ano + 1980,fecha.f1.mes,
			fecha.f1.dia);
	printf ("Longitud: %ld\n",p.ff_fsize);
	printf ("Nombre: %s\n",p.ff_name);
	getch();
}

