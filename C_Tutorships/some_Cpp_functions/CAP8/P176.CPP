#include "io.h"
#include "stdio.h"
#include "fcntl.h"
#include "dos.h"
#include "errno.h"
#include "dos.h"
#include "errno.h"
#include "string.h"
#include "conio.h"
#include "stdlib.h"

#define LON sizeof (struct DATOS)
#define PR(x) printf ("%d ",x)
#define PRS(x) printf ("%s\n",x)
#define ubicar(id,x) lseek (id,(long)x * LON,SEEK_SET)
#define leer(id,x)  _read (id,(char *)&x,LON)
#define grabar(id,x)  _write (id,(char *)&x,LON)

struct DATOS {
	int i;
	char a[30];
};

typedef struct DATOS DATOS;

void main() {
	int id,id1,id2,lea_reg (DATOS *);
	char *p;
	DATOS reg;
	char archivo[30];
   void actualizar(char*);

	strcpy (archivo,"c:\\turboc\\");
	if ( (id = creattemp (archivo,FA_ARCH) ) == -1) {
		p = _strerror ("Error _creat()");
		PRS (p);
		getch(); exit(1);
	}
	if ( _close (id) == -1) {
		p = _strerror ("Error _close ()");
		PRS (p);
		getch(); exit(1);
	}
	if ( (id = _open (archivo,O_WRONLY) ) == -1) {
		p = _strerror ("Error _open ()");
		PRS (p);
		getch(); exit(1);
	}
	lea_reg (&reg);
	id1 = dup (id);
	while (reg.i != 999) {
		if (grabar(id1,reg) == -1) {
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
	actualizar(archivo);
	id = _open (archivo,O_RDONLY);
	id1 = dup (id);
	id2 = dup (id1);
	while (!eof (id1)) {
		if (leer (id2,reg) == -1) {
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

void actualizar(char * prueba) {
	int n_registros(int );
	int lea_entero();
	int lea_reg (DATOS *);


		/*      Actualiza cualquier registro del archivo "prueba".
		/* 	Recuerde que el primer registro del archivo es el 0
			el segundo el 1, el tercero el 2, y asi
			sucesivamente */
	int n,id,n_r,c;
	DATOS r;
	char *p;

	if ( (id = _open (prueba,O_RDWR) ) == -1) {
		p = strerror (errno);
		PRS (p);
		getch(); exit(1);
	}
	n_r = n_registros(id);
	printf ("Numero de registros del archivo = %d\n",n_r);
	PRS("Lea el numero del registro a actualizar.");
	PRS("Recuerde que el primer registro en el 0.");
	PRS("El segundo es el 1, el tercero es el 2.");
	PRS("El cuarto es el 3 y asi sucesivamente.");
	n = lea_entero();
	while (n < n_r) {
		if (ubicar (id,n) == -1) {
			p = _strerror ("Error _lseek ()");
			PRS (p);
			getch(); exit(1);
		}
		if (leer (id,r) == -1) {
			p = _strerror ("Error _read ()");
			PRS (p);
			getch(); exit(1);
		}
		PRS("Los datos actuales son:");
		printf ("%d %s\n",r.i,r.a);
		PRS("Desea modificarlos?(s/n)");
		c = getch();
		if (c == 's' || c == 'S') {
			lea_reg (&r);
			if (ubicar(id,n) == -1) {
				p = _strerror ("Error _lssek ()");
				PRS (p);
				getch(); exit(1);
			}
			if (grabar (id,r) == -1) {
				p = _strerror ("Error _write()");
				PRS (p);
				getch(); exit(1);
			}
		}
		PRS("Lea el numero del registro a actualizar");
		n = lea_entero();
	}
	if ( _close (id) == -1) {
		p = strerror(errno);
		PRS (p);
		getch(); exit(1);
	}
}

int n_registros(int id) { /* Calcula el numero de registros del archivo */
	long i;

	i = lseek (id,(long)0,SEEK_END);
	return ((int) i / LON);
}

int lea_entero () {
	char a[15];

	printf ("Digite un numero de tipo int , sin errores\n");
	printf ("Esta funcion no valida los datos...\n");
	gets (a);
	return ( atoi(a) ); /* Retorna un numero aleatorio en caso de error */
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


