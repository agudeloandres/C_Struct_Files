/* Maneja un cursor lista doblemente encadenado en disco duro, cuando la
	informacion de cada registro es de tipo INFO */

#include "stdio.h"
#include "stdlib.h"
#include "io.h"
#include "fcntl.h"
#define MAXIMO 300
#define P(x)  printf ("%s\n",x)
#define LON sizeof (BUFFER)
#define grabar(id,a)  _write (id,(char *)&a,LON)
#define lea(id,a)  _read (id,(char *)&a,LON)
#define ubicar(id,a)  lseek (id,(long)a * LON, SEEK_SET)
typedef struct BUFFER BUFFER;
typedef struct INFO INFO;

struct INFO {
	int cod;
	char n [30];
};

struct BUFFER {
	int ant;
	INFO info;
	int sig;
};

main()
{
	int id,n1;
	INFO n;

	id = init_archivo ();
	id = _open ("lista",O_RDWR);
	P(" ");
	P("De datos");
	lea_datos (&n);
	while (n.cod != 9999) {
		if (insertar (id, n) == -1)
			P("Repetido");
		else P("Insertado");
		P("De datos");
		lea_datos (&n);
	}
	escribir (id);
	getch();
	P(" ");
	P("De codigo a retirar");
	while (   (n1 = lea_entero() ) != 9999) {
		if (retirar (id, n1) == -1)
			P("No existe...");
		else P("Retirado");
		P("De codigo a retirar ");
	}
	escribir (id);
	getch();

}

lea_datos (INFO *n)
{
	P("De codigo <R> y nombre <R>");
	n->cod = lea_entero();
	gets (n->n);
}

init_archivo ()
{
	int i,id;
	BUFFER a;

	id = _creat ("lista",32);
	a.ant = a.info.cod = 0;
	strcpy (a.info.n, "                        ");
	for (i=0; i < MAXIMO; i++) {
		a.sig = i + 1;
		grabar (id,a);
	}
	a.sig = 0;
	grabar (id,a);
	close (id);
	return (id);
}

lea_entero()
{
	char a[10];

	gets (a);
	return (atoi (a));
}


escribir (int id)
{
	int i;
	BUFFER a;

	ubicar (id,0);
	lea (id,a);
	i = a.ant;
	while (i != 0) {
		ubicar (id,i);
		lea (id,a);
		printf ("%d %s\n",a.info.cod,a.info.n);
                i = a.sig;
	}
	P("\n");
	ubicar (id,0);
	lea (id,a);
	i = a.info.cod;
	while (i != 0) {
		ubicar (id,i);
		lea (id,a);
		printf ("%d %s\n ",a.info.cod,a.info.n);
		i = a.ant;
	}
}

insertar (int id,INFO n)
{
	int p,q,enc,prox;
	BUFFER r0,pc,qc,proxc;

	ubicar (id,0);
	lea (id,r0);
	p = r0.ant;
	enc = q = 0;
	while (p != 0 && !enc) {
		ubicar (id,p);
		lea (id,pc);
		if (n.cod > pc.info.cod) {
			q = p;
			copie (&qc,pc);
			p = pc.sig;
		}
		else enc = 1;
	}
	if (enc == 1)
		if (pc.info.cod == n.cod)
			return (-1);
	prox = disp (id, &r0);
	if (prox != -1) {
		proxc.info.cod = n.cod;
		strcpy (proxc.info.n, n.n);
		proxc.sig = p;
		proxc.ant = q;
		ubicar (id,prox);
		grabar (id,proxc);
		if (p == 0)
			r0.info.cod = prox;
		else {
			pc.ant = prox;
			ubicar (id,p);
			grabar (id,pc);
		}
		if (q == 0) {
			r0.ant = prox;
		}
		else {
			qc.sig = prox;
			ubicar (id,q);
			grabar (id,qc);
		}
	}
	else {
		P("Lista llena...");
		getch();
		exit (1);
	}
	ubicar (id,0);
	grabar (id,r0);
}

copie (BUFFER *q,BUFFER p)
{
	q->ant = p.ant;
	q->info.cod = p.info.cod;
	strcpy (q->info.n,p.info.n);
	q->sig = p.sig;
}

disp (int id, BUFFER *r0)
{
	int i;
	BUFFER r1;

	i = r0->sig;
	if (i == 0)
		return (-1);
	else {
		ubicar (id,i);
		lea (id, r1);
		r0->sig = r1.sig;
		return (i);
	}
}


retirar (int id,int n)
{
	BUFFER r0,pc,qc,rc;
	int p,q,r,enc;

        ubicar (id,0);
        lea (id,r0);
        p = r0.ant;
        enc = 0;
	while (p != 0 && !enc) {
		ubicar (id,p);
		lea (id,pc);
		if (n > pc.info.cod) {
			p = pc.sig;
		}
		else enc = 1;
	}

	if (enc == 1)
		if (pc.info.cod != n)
			return (-1); /* No existe */
	if (p == 0)
	   return (-1); /* No existe */

        r = pc.ant;
        q = pc.sig;
        if (r == 0)
	   if (q == 0) {
	      r0.ant = 0;
	      r0.info.cod = 0; /* Final de la lista */
	   }
           else {
                    r0.ant = pc.sig;
                    ubicar (id,q);
                    lea (id,qc);
                    qc.ant = 0;
                    ubicar (id,q);
                    grabar (id,qc);
           }
	else if (q == 0) {
		r0.info.cod = r; /* Apunta al ultimo de la lista */
		ubicar (id,r);
		lea (id,rc);
		rc.sig = 0;
		ubicar (id,r);
		grabar (id,rc);
	}
	else {
		ubicar (id,r);
		lea (id,rc);
		ubicar (id,q);
		lea (id,qc);
		rc.sig = q;
		qc.ant = r;
		ubicar (id,r);
		grabar (id,rc);
		ubicar (id,q);
		grabar (id,qc);
	}
	liberar (id,p,pc,&r0);

	ubicar (id,0);
	grabar (id,r0);
	return (0); /* Retirado correctamente */
}


liberar (int id,int p, BUFFER pc, BUFFER *r0)
{
	pc.sig = r0->sig;
	ubicar (id,p);
	grabar (id,pc);
	r0->sig = p;
}




