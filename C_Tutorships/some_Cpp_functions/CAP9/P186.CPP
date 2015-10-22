#include "io.h"
#include "stdio.h"
#include "fcntl.h"
#include "dos.h"
#include "errno.h"
#include "sys\stat.h"
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
	int id,id1,id2,lea_reg (DATOS *);
	void actualizar();
	int lea_entero();
	char *p;
	DATOS reg;

	_fmode = O_BINARY; /* Al hacer las pruebas a este programa, se
				encontro que al trabajar los archivos
				bajo DOS con las instrucciones para UNIX,
				se debe utilizar el modo O_BINARY */

	if ( (id = creat ("c:\\bc\\prueba",S_IREAD | S_IWRITE ))== -1) {
		p = _strerror ("Error creat()");
		PRS (p);
		getch(); exit(1);
	}
	if ( close (id) == -1) {
		p = _strerror ("Error close ()");
		PRS (p);
		getch(); exit(1);
	}
	if ( (id = open ("c:\\bc\\prueba",O_WRONLY) ) == -1) {
		p = _strerror ("Error open ()");
		PRS (p);
		getch(); exit(1);
	}
	lea_reg (&reg);
	while (reg.i != 999) {
		if (grabar(id,reg) == -1) {
			p = _strerror ("Error _write()");
			PRS (p);
			getch(); exit(1);
		}
		lea_reg (&reg);
	}
	if ( close (id) == -1) {
		p = _strerror("Error close ()");
		PRS (p);
		getch(); exit(1);
	}
	actualizar();
	id = open ("c:\\bc\\prueba",O_RDONLY);
	while (!eof (id)) {
		if (leer (id,reg) == -1) {
			p = _strerror ("Error read ()");
			PRS (p);
			getch(); exit(1);
		}
		PR(reg.i);
		PRS (reg.a);
	}
	if ( close (id) == -1) {
		p = _strerror("Error close ()");
		PRS (p);
		getch(); exit(1);
	}
	getch();
}
n_registros(int id) {
	long l;
	l= lseek(id,0L,SEEK_END);
	return ( (int)l/LON);
}

int lea_reg (DATOS *p) {
	char a[10];

	PRS("De los datos del registro...999 para fin");
	PRS("Codigo");
	gets (a);
	p->i = atoi (a);
	PRS("Nombre");
	gets (p->a);
	return 0;
}


int lea_entero() {
	char a[10];gets(a);return (atoi(a));
}


void actualizar() {
	int n,id,n_r,c;
	DATOS r;
	char *p;

	if ( (id = open ("c:\\bc\\prueba",O_RDWR) ) == -1) {
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
			p = _strerror ("Error lseek ()");
			PRS (p);
			getch(); exit(1);
		}
		if (leer (id,r) == -1) {
			p = _strerror ("Error read ()");
			PRS (p);
			getch(); exit(1);
		}
		PRS("Los datos actuales son:");
		printf ("%d %s\n",r.i,r.a);
		cprintf ("Desea modificarlos?");
					 textbackground (15);
		textcolor (128);
		cprintf ("(s/n)");
		textbackground (0);
		textcolor (15);
		PRS("\n");
		c = getch();
		if (c == 's' || c == 'S') {
			lea_reg (&r);
			if (ubicar(id,n) == -1) {
				p = _strerror ("Error lseek ()");
				PRS (p);
				getch(); exit(1);
			}
			if (grabar (id,r) == -1) {
				p = _strerror ("Error write()");
				PRS (p);
				getch(); exit(1);
			}
		}
		PRS("Lea el numero del registro a actualizar. 999 para fin");
		n = lea_entero();
	}
	if ( close (id) == -1) {
		p = strerror(errno);
		PRS (p);
		getch(); exit(1);
	}
}
