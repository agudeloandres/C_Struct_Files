/* Este programa maneja las multilistas en disco duro. Este programa
	se ejecuta desde el codigo demomenu.c */

#include "stdio.h"
#include "io.h"
#include "fcntl.h"
#include "stdlib.h" /* atof() */
#define ubicar(id,i) lseek (id,(long)(i * sizeof (struct REG)),SEEK_SET)
#define leer(id,q) _read (id,(char *)&q,sizeof (struct REG));
#define leer_r0(id,r0) _read (id,(char *)&r0,sizeof (struct REG0))
#define grabar(id,q) _write (id,(char *)&q,sizeof (struct REG));
#define grabar_r0(id,r0) _write (id,(char *)&r0,sizeof (struct REG0));
#define P(x) cprintf ("%s\n",x) /* Escribe en una ventana */
typedef struct REG REG;
typedef struct REG0 REG0;
struct REG0 {
	int cab [10];
	char blancos [23]; /* Iguala las longitudes de los dos registros */
};

struct REG {
	char nombre[30];
	int edad;
	char sexo;
	char educa;
	char estado;
	int sig_edad;
	int sig_sexo;
	int sig_educa;
	int sig_estado;
};

captura ()
{
	char s;
	int id;
	REG r;

	window (1,1,80,24);
	clrscr();
	marco (2,2,79,23);
	id = _open ("MULTILISTAS",O_RDWR);
	if (id == -1) {
		P("error apertura");
		exit (1);
	}
	P("DE INFORMACION.... ");
	s = 's';
	while (s == 's' || s == 'S') {
		clrscr();
		lectura (&r);
		insertar (r,id);
		P("INSERTA MAS REGISTROS? (S/N)");
		s = getche ();
	}
	close (id);
	window (1,1,80,24);
	clrscr();
}

insertar (nuevo,id)
REG nuevo;
int id;
{
	REG qc,pc;
	REG0 r0;
	int n,p,q,encontro,proximo;

	n = nuevo.edad;
	ubicar (id,0);
	leer_r0 (id,r0);
	proximo = long_archivo (id);
	p = 0;
	q = r0.cab[0];
	encontro = 0;
	while (q != 0 && !encontro ) {
                ubicar (id,q);
		leer (id,qc);
		if (n > qc.edad) {
			p = q;
			asigne (&pc,&qc);
			q = qc.sig_edad;
		}
		else encontro = 1;
	}
        nuevo.sig_edad = q;
	if (p != 0) {
                pc.sig_edad = proximo;
		ubicar (id,p);
		grabar (id,pc);
	}
	else r0.cab [0] = proximo;

        if (nuevo.sexo == 'm')
		q = r0.cab[1];
	else q = r0.cab [2];
	p = 0;
	while (q) {
		ubicar (id,q);
		leer (id,qc);
		p = q;
		asigne (&pc,&qc);
		q = qc.sig_sexo;
	}
	if (p != 0) {
		pc.sig_sexo = proximo;
		ubicar (id,p);
		grabar (id,pc);
	}
	else if (nuevo.sexo == 'm')
			r0.cab [1] = proximo;
	     else r0.cab [2] = proximo;

	switch (nuevo.educa) {
		case 'p' : q = r0.cab [3]; break;
		case 'b' : q = r0.cab [4]; break;
		case 'u' : q = r0.cab [5]; break;
		default : cprintf ("error\n");exit (1);
	}
	p = 0;
	while (q) {
		ubicar (id,q);
		leer (id,qc);
		p = q;
		asigne (&pc,&qc);
		q = qc.sig_educa;
	}
	if (p != 0) {
		pc.sig_educa = proximo;
		ubicar (id,p);
		grabar (id,pc);
	}
	else
		switch (nuevo.educa) {
			case 'p' : r0.cab [3] = proximo; break;
			case 'b' : r0.cab [4] = proximo; break;
			case 'u' : r0.cab [5] = proximo; break;
			default : cprintf ("error\n");exit (1);
		}

	switch (nuevo.estado) {
		case 's' : q = r0.cab [6]; break;
		case 'c' : q = r0.cab [7]; break;
		case 'd' : q = r0.cab [8]; break;
		case 'v' : q = r0.cab [9]; break;
		default : cprintf ("error\n");exit (1);
	}
	p = 0;
	while (q) {
		ubicar (id,q);
		leer (id,qc);
		p = q;
		asigne (&pc,&qc);
		q = qc.sig_estado;
	}
	if (p != 0) {
		pc.sig_estado = proximo;
		ubicar (id,p);
		grabar (id,pc);
	}
	else
		switch (nuevo.estado) {
			case 's' : r0.cab [6] = proximo; break;
			case 'c' : r0.cab [7] = proximo; break;
			case 'd' : r0.cab [8] = proximo; break;
			case 'v' : r0.cab [9] = proximo; break;
			default : cprintf ("error\n");exit (1);
		}

	ubicar (id,0);
	grabar_r0 (id,r0);
	ubicar (id,proximo);
	grabar (id,nuevo);
}

long_archivo(int id)
{
	long final;

	final = lseek (id,(long)0,SEEK_END);
	return ( (int) final / sizeof (REG) );
}


asigne (p,q)
REG *p,*q;
{
	strcpy (p->nombre, q->nombre);
	p->edad = q->edad;
	p->sexo = q->sexo;
	p->educa = q->educa;
	p->estado =q->estado;
	p->sig_edad = q->sig_edad;
	p->sig_sexo = q->sig_sexo;
	p->sig_educa = q->sig_educa;
	p->sig_estado = q->sig_estado;
}



lectura (r)
REG *r;
{
	char aux [20],c;
	int resul;
	P("De nombre");
	textowindow (r->nombre,30);
	P("\nDe edad");
	textowindow (aux,10);
	while ( (resul = entero (aux)) == 0 ) {
		cprintf ("%c",7);
		P("\nDe edad");
		textowindow (aux,10);
	}
	r->edad = resul;
	P("\nDe sexo");
	c = getch();putch(c);getch();putch('\n');
	while (c != 'M' && c != 'm' && c!= 'f' && c != 'F') {
		cprintf ("%c",7);
		P("\nDe sexo");
		c = getch();putch(c);getch();putch('\n');
	}
	r->sexo = c;
	P("De educacion (p=primaria, b=bachillerato, u=universitarios)");
	c = getch();putch(c);getch();putch('\n');
	while (c != 'p' && c != 'P' && c!= 'b' && c != 'B' &&
		c != 'u' && c != 'U') {
		cprintf ("%c",7);
   	   	P("De educacion (p=primaria, b=bachillerato, u=universidad)");
		c = getch();putch(c);getch();putch('\n');
	}
	r->educa = c;
	P("De estado (s=soltero, c=casado, d=divorciado, v=viudo)");
	c = getch();putch(c);getch();putch('\n');
	while (c != 's' && c != 'S' && c!= 'c' && c != 'C' &&
		c != 'd' && c != 'D' && c != 'v' && c != 'V') {
		cprintf ("%c",7);
		P("De estado (s=soltero, c=casado, d=divorciado, v=viudo)");
		c = getch();putch(c);getch();putch('\n');
	}
	r->estado= c;
	r->sig_edad = 0;
	r->sig_sexo = 0;
	r->sig_educa = 0;
	r->sig_estado = 0;
}


textowindow (a,n)
char a[];
int n;
{
   int c,i;
   i=0;
   while (--n > 0 && (c=getche ()) != EOF && c != 13)
     if (c!=8)
     	a [i++] = c;
     else if (i>0) i--;
   a[i] = '\0';
   return (i);

}


entero (a)
char a[];
{
	double h;
	int i=0;
	while (a[i] != '\0' && a[i] >= '0' && a[i] <= '9') i++;
	if (a[i] != '\0')
		return (0);
	else {
                  h = atof (a);
		  if (h > 0 && h <= 110)
		  	return ( (int) h);
		  else return (0);
	}
}


escribir (r)
REG *r;
{
	cprintf("%-35s",r->nombre);
	cprintf ("%-4d ",r->edad);
	cprintf ("%c ",r->sexo);
	cprintf ("%c ",r->educa);
	cprintf ("%c\n",r->estado);
}



ini_archivo()
{
	int id,i;
	char c;
	REG0 r0;
        REG r;

	window (1,1,80,24);
	clrscr();
	marco (2,2,79,23);
	P("Esta seguro que desea borrar el archivo anterior si existe?(s/n)");
	c = getch();putch(c);
	if (c != 's') {
		window (1,1,80,24);
		clrscr();
                return(1);
	}
	P("\nIniciando archivo...");
	id = _creat ("MULTILISTAS",32);
	if (id==-1) {
		cprintf ("error creat"); exit (1);
	}
	close(id);
	id = _open ("MULTILISTAS",O_WRONLY);
	for (i = 0; i < 10; i++)
		r0.cab [i] = 0;
	strcmp (r0.blancos,"                  ");
        grabar_r0 (id,r0);
	window (1,1,80,24);
	clrscr();
	close (id);

}

consult_1 (s)
int s;
{
	REG0 r0;
	REG r;
	char buf [LREG];
	int i,id;

	window (1,1,80,24);
	clrscr();
	marco (1,1,60,24);
	id = _open ("MULTILISTAS",O_RDONLY);
	ubicar (id,0);
	leer_r0 (id,r0);
	i = r0.cab [s];
	while (i) {
		ubicar (id,i);
		leer (id,r);
		escribir (&r);
		switch (s) {
			case 0 : i = r.sig_edad; break;
			case 1 :
			case 2 : i = r.sig_sexo; break;
			case 3 :
			case 4 :
			case 5 : i = r.sig_educa; break;
			case 6 :
			case 7 :
			case 8 :
			case 9 : i = r.sig_estado; break;
			default : cprintf ("orror\n"); exit(1);
		}
	}
	P("Oprima <R>");getch();
	window (1,1,80,24);
	clrscr();
	close (id);
}

/*
typedef struct REG REG;
struct REG {
	char nombre[30];
	int edad;
	int sig_edad;
	int sig_sexo;
	int sig_educa;
	int sig_estado;
};
*/
