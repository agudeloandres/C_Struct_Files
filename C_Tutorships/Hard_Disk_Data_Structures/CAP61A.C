/* Maneja un cursor arbol binario en disco duro. Este programa se
	ejecuta desde el programa marcharb.c */

#include "stdio.h"
#include "io.h"
#include "fcntl.h"
#include "stdlib.h"
#define MAXIMO 10
#define P(x) printf ("%s\n",x)
#define LON sizeof (BUFFER)
#define grabar(id,a)  _write (id,(char *)&a,LON)
#define leer(id,a)  _read (id,(char *)&a,LON)
#define ubicar(id,a)  lseek (id,(long)a * LON, SEEK_SET)


typedef struct BUFFER BUFFER;
struct BUFFER {
	int info;
	int izq;
	int der;
};

capturar ()
{
	int n,id;

	id = _open ("arbol",O_RDWR);
	P("De numero");
	n = lea_entero();
	while (n != 9999) {
		if (insertar (id, n) == -1)
			P("Repetido...");
		else    P("Insertado...");
		P("De numero");
		n = lea_entero();
	}
	close (id);
}

consul ()
{
	int n,id;

	id = _open ("arbol",O_RDONLY);
	P("De codigo");
	n = lea_entero();
	while (n != 9999) {
		if (consultar (id, n) == -1)
			P("No existe. Trate otra vez...");
		else    P("Si existe...");
		P("De codigo");
		n = lea_entero();
	}
	close (id);
}

lea_entero()
{
	char a[10];

	gets (a);
	return (atoi (a));
}

init_archivo ()
{
	int i,id;
	BUFFER a;

	id = _creat ("arbol",32);
	a.izq = a.info = 0;
	for (i=0; i < MAXIMO; i++) {
		a.der = i + 1;
		grabar (id,a);
	}
	a.der = 0;
	grabar (id,a);
	close (id);
}

insertar (int id, int n)
{
	int p, q, enc = 0, prox;
	BUFFER a,r0,pc,qc,proxc;

	ubicar (id,0);
	leer (id,r0);
	if (r0.izq == 0) {
		prox = disp (id,&r0);
		a.info = n;
		a.izq = a.der = 0;
		r0.izq = prox;
		ubicar (id,0);
		grabar (id,r0);
		ubicar (id,prox);
		grabar (id,a);
		return (0);
	}


	p = q = r0.izq;
	while ( p != 0 && !enc) {
		ubicar (id,p);
		leer (id,pc);
		qc = pc;
		q = p;
		if (n < pc.info)
			p = pc.izq;
		else if (n > pc.info)
			p = pc.der;
		else enc = 1;
	}


	if (enc == 1)
		return (-1);
	prox = disp (id,&r0);
	if (prox != -1) {
		proxc.info = n;
		proxc.izq = proxc.der = 0;
		if (n < qc.info)
			qc.izq = prox;
		else qc.der = prox;
		ubicar (id,prox);
		grabar (id,proxc);
		ubicar (id,q);
		grabar (id,qc);
	}
	else {
		P("Archivo lleno...");
		getch();
		exit (1);
	}
	ubicar (id,0);
	grabar (id,r0);
	return (0);

}


consultar (int id, int n)
{
	int p, q, enc = 0, prox;
	BUFFER a,r0,pc,qc,proxc;

	ubicar (id,0);
	leer (id,r0);
	p = r0.izq;
	while ( p != 0 && !enc) {
		ubicar (id,p);
		leer (id,pc);
		if (n < pc.info)
			p = pc.izq;
		else if (n > pc.info)
			p = pc.der;
		else enc = 1;
	}
	if (enc != 1)
		return (-1);
	else return (p);
}


disp (int id,BUFFER *r0)
{
	int i;
	BUFFER r1;

	i = r0->der;
	if (i == 0)
		return (-1);
	else {
		ubicar (id,i);
		leer (id,r1);
		r0->der = r1.der;
		return (i);
	}
}

retirar ()
{
	int n,id;


	id = _open ("arbol",O_RDWR);
	P("De codigo a retirar...");
	n = lea_entero();
	while (n != 9999) {
		if (borrar (id, n) == -1)
			P("No existe. Trate otra vez...");
		else P("retirado... ");
		P("De codigo a retirar");
		n = lea_entero();
	}
	close (id);
}

borrar (int id, int n)
{
	int p, q, enc = 0, prox;
	BUFFER r0,pc,qc;

	ubicar (id,0);
	leer (id,r0);
	q = 0;
	p = r0.izq;
	while ( p != 0 && !enc) {
		ubicar (id,p);
		leer (id,pc);
		if (n < pc.info) {
			q = p;
			qc = pc;
			p = pc.izq;
		}
		else if (n > pc.info) {
			q = p;
			qc = pc;
			p = pc.der;
		}
		else enc = 1;
	}
	if (enc == 1) {
		borrar_elemento (id,q,p,qc,pc,r0);
		return (0);
	}
	else return (-1);
}

borrar_elemento (int id,int q,int p,BUFFER qc, BUFFER pc,BUFFER r0)
{
	int r,t,s;
	BUFFER rc,tc,sc;

	if (pc.izq == 0)
		r = pc.der;
	else if (pc.der == 0)
		r = pc.izq;
	else {
		s = p;
		sc = pc;
		r = pc.der;
		ubicar (id,r);
		leer (id,rc);
		t = rc.izq;
		while (t != 0) {
			ubicar (id,t);
			leer (id,tc);
			s = r;
			sc = rc;
			r = t;
			rc = tc;
			t = tc.izq;
		}
		if (p != s) {
			sc.izq = rc.der;
			rc.der = pc.der;
			ubicar (id,s);
			grabar (id,sc);
		}
		rc.izq = pc.izq;
                ubicar (id,r);
		grabar (id,rc);
	}
	if (q == 0)
		r0.izq = r;
	else if (p == qc.izq) {
		qc.izq = r;
		ubicar (id,q);
		grabar (id,qc);
	}
	else {
		qc.der = r;
                ubicar (id,q);
		grabar (id,qc);
	}
	liberar (p,&pc,&r0);
	ubicar (id,0);
	grabar (id,r0);
	ubicar (id,p);
	grabar (id,pc);
}

liberar (int p,BUFFER *pc,BUFFER *r0)
{
	pc->der = r0->der;
	r0->der = p;
}


typedef struct LIFO LIFO;
struct LIFO {
	int t;
	int a[MAXIMO];
};

inorden ()
{
	LIFO pila;
	int p,id;
	BUFFER r0,pc;

	id = _open ("arbol",O_RDONLY);
	ubicar (id,0);
	leer (id,r0);
	p = r0.izq;
	init_pila (&pila);
	while (p != 0) {
		ins_pila (&pila,p);
		ubicar (id,p);
		leer (id,pc);
		p = pc.izq;
	}
	while (!pila_vacia (&pila) ) {
		retira_pila(&pila,&p);
		ubicar (id,p);
		leer (id,pc);
		printf ("%d ",pc.info);
		p = pc.der;
                while (p != 0) {
			ins_pila (&pila,p);
			ubicar (id,p);
			leer (id,pc);
			p = pc.izq;
		}
	}
	close (id);
}

init_pila (LIFO *p)
{
	p->t = 0;
}

pila_vacia (LIFO *p)
{
	return (p->t == 0);
}

ins_pila (LIFO *p,int s)
{
	if (p->t == MAXIMO) {
		printf ("pila llena...");
		getch();
		exit (1);
	}
	else {
		p->a [p->t] = s;
		p->t++;
	}
}

retira_pila (LIFO *p, int *s)
{
	if (pila_vacia (p) ) {
		printf ("pila vacia...");
		getch();
		exit (1);
	}
	else {
		p->t--;
		*s = p->a [p->t];
	}
}




