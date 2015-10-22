#include "stdio.h"
#include "process.h"
#include "fcntl.h"
#include "io.h"
#include "errno.h"
#include "conio.h"
#include "stdlib.h"

#define lea(x,y) _read (x,(char *)&y,sizeof (REG))

typedef struct X REG;

struct X {
	int i;
	char a[20];
};

/* spawnl(), solamente busca en el directorio actual  */

void main() {
	int i;
	REG r;

	i = spawnl (P_WAIT,"prog.exe","prog.exe","prueba",NULL);
	if (i == -1) {
		printf ("%s\n",strerror (errno) );
		getch();
		exit (1);
	}
	i = _open ("prueba",O_RDONLY);
	while (! eof (i) ) {
		lea (i,r);
		printf ("%d %s\n",r.i,r.a);
	}
	_close (i);
	getch();
}

/*************  Programa prog.cpp(De prueba) *****************/
/*
#include "stdio.h"
#include "process.h"
#include "fcntl.h"
#include "io.h"
#include "conio.h"
#include "stdlib.h"


#define escriba(q,p) _write (q,(char *)&p,sizeof (REG))
#define PR(x) printf ("%s\n",x)

typedef struct X REG;

struct X {
	int i;
	char a[20];
};

void main(int argc, char *argv[]) {
	REG r;
	int id = _creat (argv[1],32);
	void lea_reg(REG *p) ;
	_close (id);
	id = _open (argv[1],O_WRONLY);
	PR("Lea el primer registro");
	lea_reg (&r);
	while (strcmp(r.a,"final") != 0) {
		escriba (id,r);
		PR("Lea otro registro");
		lea_reg(&r);
	}
	_close (id);
}

void lea_reg(REG *p) {
	char a[10];

	puts ("Codigo:");
	gets (a);
	p->i = atoi (a);
	puts ("Nombre:");
	gets (p->a);
}

*/