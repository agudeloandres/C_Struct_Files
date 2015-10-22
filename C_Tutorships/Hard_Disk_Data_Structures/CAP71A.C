

/* Maneja un archivo AVL en disco duro.  */
/* Este programa no tiene la funcion main()  */
/* Se ejecuta desde el programa archiavl.c */



#include "stdio.h"
#include "io.h"
#include "fcntl.h"
#include "stdlib.h"
#define MAXIMO 35
#define MAX 10
#define P(x) printf ("%s\n",x)
#define LON sizeof (BUFFER)
#define grabar(id,a)  _write (id,(char *)&a,LON)
#define leer(id,a)  _read (id,(char *)&a,LON)
#define ubicar(id,a)  lseek (id,(long)a * LON, SEEK_SET)
typedef struct BUFFER BUFFER;

struct BUFFER {
	int info;
	int bal;
	int izq,der;
};


capturar ()
{
	int n,id;

	id = _open ("arbol",O_RDWR);
	P("De llave a incluir. 9999 para finalizar. ");
	n = lea_entero ();
	while (n != 9999) {
		if (ins_avl (id, n) == -1)
			P("Repetido...");
		else {
			P("Insertado..");
		}
		P("De llave a incluir. 9999 para finalizar. ");
		n = lea_entero();
	}
	close (id);
}

consul1 ()
{
	int n,id;

	id = _open ("arbol",O_RDONLY);
	P("De codigo. 9999 para finalizar.");
	n = lea_entero();
	while (n != 9999) {
		if (consultar (id, n) == -1)
			P("No existe. Trate otra vez...");
		else P("Si existe...");
		P("De codigo. 9999 para finalizar.");
		n = lea_entero();
	}
	close (id);
}

retirar1 ()
{
	int n,id;

	id = _open ("arbol",O_RDWR);
	P("De codigo a retirar... 9999 para finalizar.");
	n = lea_entero();
	while (n != 9999) {
		if (retira_avl (id, n) == -1)
			P("No existe. Trate otra vez...");
		else {
			P("retirado... ");
		}
		P("De codigo. 9999 para finalizar.");
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
	a.info = a.izq = a.bal = 0;
	for (i=0; i < MAXIMO; i++) {
		a.bal = 0;
		a.der = i + 1;
		grabar (id,a);
	}
	a.der = 0;
	grabar (id,a);
	close (id);
}


ins_avl (int id,int n)
{
	int nuevo,p,q,s,pivote,pp,llave,altura;
	BUFFER nuevoc,pc,qc,sc,pivotec,ppc,r0;

	ubicar (id,0);
	leer (id,r0);
	nuevo = disp (id,&r0);
	if (nuevo == -1) {
		printf ("Archivo lleno...");
		getch();
		exit (1);
	}
	nuevoc.info = n;
	nuevoc.bal = nuevoc.izq = nuevoc.der = 0;
	if (r0.izq == 0) {
		r0.izq = nuevo;
		ubicar (id,0);
		grabar (id,r0);
		ubicar (id,nuevo);
		grabar (id,nuevoc);
		return (0); /* Se inserto correctamente */
	}


	pp = q = 0;
	p = pivote = r0.izq;
	if (p != 0) {
		ubicar (id,p);
		leer (id,pc);
		pivotec = pc;
	}
	llave = nuevoc.info;
	while (p != 0) {
		ubicar (id,p);
		leer (id,pc);
		if (pc.bal != 0) {
			pp = q;
			pivote = p;
			pivotec = pc;
		}
		if (llave == pc.info) {
			liberar_nodo (nuevo,&pc,&r0);
			ubicar (id,0);
			grabar (id,r0);
			ubicar (id,nuevo);
			grabar (id,pc);
			return (-1);  /* Ya existe */
		}
		else {
			q = p;
			qc = pc;
			if (llave < pc.info)
				p = pc.izq;
			else p = pc.der;
		}
	}


	ubicar (id,nuevo);
	grabar (id,nuevoc);
	if (llave < qc.info)
		qc.izq = nuevo;
	else qc.der = nuevo;
	ubicar (id,q);
	grabar (id,qc);


	if (q == pivote)
		pivotec = qc;
	if (llave < pivotec.info) {
		s = pivotec.izq;
		altura = 1;
	}
	else {
		s = pivotec.der;
		altura = -1;
	}
	if (s == nuevo)
		sc = nuevoc;
	else {
		ubicar (id,s);
		leer (id,sc);
	}


	p = s;
	while (p != nuevo) {
		ubicar (id,p);
		leer (id,pc);
		if (llave < pc.info) {
			pc.bal = 1;
			ubicar (id,p);
			grabar (id,pc);
			if (s == p)
				sc = pc;
			p = pc.izq;
		}
		else {
			pc.bal = -1;
                        ubicar (id,p);
			grabar (id,pc);
			if (s == p)
				sc = pc;
			p = pc.der;
		}
	}


	if (pivotec.bal == 0) {
		pivotec.bal = altura;
		ubicar (id,pivote);
		grabar (id,pivotec);
	}
	else	if (pivotec.bal + altura == 0) {
			pivotec.bal = 0;
			ubicar (id,pivote);
			grabar (id,pivotec);
		}
		else {
			if (altura == 1)
				if (sc.bal == 1)
					r_derecha (pivote,&pivotec,&sc);
				else dr_derecha (id,pivote,&pivotec,&s,&sc);
			else 	if (sc.bal == -1)
					r_izquierda (pivote,&pivotec,&sc);
				else dr_izquierda (id,pivote,&pivotec,&s,&sc);
			if (pp == 0)
				r0.izq = s;
			else {
				ubicar (id,pp);
				leer (id,ppc);
				if (ppc.izq == pivote)
					ppc.izq = s;
				else ppc.der = s;
				ubicar (id,pp);
				grabar (id,ppc);
			}
			ubicar (id,pivote);
			grabar (id,pivotec);
			ubicar (id,s);
			grabar (id,sc);
		}


	ubicar (id,0);
	grabar (id,r0);
	return (0);  /* Se inserto correctamente */
}

r_derecha (int p,BUFFER *pc,BUFFER *qc)
{
	pc->bal = qc->bal = 0;
	pc->izq = qc->der;
	qc->der = p;
}

r_izquierda (int p,BUFFER *pc,BUFFER *qc)
{
	pc->bal = qc->bal = 0;
	pc->der = qc->izq;
	qc->izq = p;
}

dr_derecha (int id,int p,BUFFER *pc,int *q,BUFFER *qc)
{
	int r;
	BUFFER rc;

	ubicar (id,qc->der);
	leer(id,rc);
	r = qc->der;
	qc->der = rc.izq;
	rc.izq = *q;
	pc->izq = rc.der;
	rc.der = p;
	switch (rc.bal) {
		case -1 : qc->bal = 1;
			  pc->bal = 0;
			  break;
		case 0 :  qc->bal = pc->bal = 0;
			  break;
		case 1 :  qc->bal = 0;
			  pc->bal = -1;
			  break;
	}
	rc.bal = 0;
	ubicar (id,*q);
	grabar (id,*qc);
	*q = r;
	*qc = rc;
}

dr_izquierda (int id,int p,BUFFER *pc,int *q,BUFFER *qc)
{
	int r;
	BUFFER rc;

	r = qc->izq;
	ubicar (id,r);
	leer (id,rc);
	qc->izq = rc.der;
	rc.der = *q;
	pc->der = rc.izq;
	rc.izq = p;
	switch (rc.bal) {
		case -1 : qc->bal = 0;
			  pc->bal = 1;
			  break;
		case 0 :  qc->bal = pc->bal = 0;
			  break;
		case 1 :  qc->bal = -1;
			  pc->bal = 0;
			  break;
	}
	rc.bal = 0;
	ubicar (id,*q);
	grabar (id,*qc);
	*q = r;
	*qc = rc;
}


consultar (int id,int n)
{
	int p,enc = 0;
	BUFFER r0,pc;

	ubicar (id,0);
	leer (id,r0);
	p = r0.izq;
	while ( p != 0 && !enc) {
		ubicar (id,p);
		leer(id,pc);
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



disp (int id, BUFFER *a)
{
	int i;
	BUFFER a1;

	i = a->der;

	if (i == 0)
		return (-1);
	else {
		ubicar (id,i);
		leer (id,a1);
		a->der = a1.der;
		return (i);
	}
}


liberar_nodo (int p,BUFFER *pc, BUFFER *r0)
{
	pc->der = r0->der;
	r0->der = p;
}


bal_der (int id,int q,BUFFER *qc,int *t,int *terminar)
{
	BUFFER tc;

	switch (qc->bal) {
		case  1 : qc->bal = 0;
			  break;
		case -1 : *t = qc->der;
			  ubicar (id,*t);
			  leer (id,tc);
			  switch (tc.bal) {
			      case 1 : dr_izquierda(id,q,qc,t,&tc);
				       break;
			      case -1: r_izquierda (q,qc,&tc);
				       break;
			      case 0 : qc->der = tc.izq;
				       tc.izq = q;
				       tc.bal = 1;
				       *terminar = 1;
				       break;
			  }
			  ubicar (id,*t);
			  grabar (id,tc);
			  break;
		case  0 : qc->bal = -1;
			  *terminar = 1;
			  break;
	}
	ubicar (id,q);
	grabar (id,*qc);
}

bal_izq (int id,int q,BUFFER *qc,int *t,int *terminar)
{
	BUFFER tc;

	switch (qc->bal) {
		case -1 : qc->bal = 0;
			  break;
		case  1 : *t = qc->izq;
			  ubicar (id,*t);
			  leer (id,tc);
			  switch ( tc.bal) {
			  case  1: r_derecha (q,qc,&tc);
				   break;
			  case -1: dr_derecha (id,q,qc,t,&tc);
				   break;
			  case 0 : qc->izq = tc.der;
				   tc.der = q;
				   tc.bal = -1;
				   *terminar = 1;
				   break;
			  }
			  ubicar (id,*t);
			  grabar (id,tc);
			  break;
		case  0 : qc->bal = 1;
			  *terminar = 1;
			  break;
	}
	ubicar (id,q);
	grabar (id,*qc);
}

typedef struct LIFO LIFO;
typedef struct LIFO1 LIFO1;

struct LIFO {
	int t;
	int a[MAX];       /* Se calcula de acuerdo a la altura del arbol */
};

struct datos {
	int direccion;
	BUFFER d;
};


struct LIFO1 {
	int t;
	struct datos a[MAX]; /* Se calcula de acuerdo a la altura del arbol */
};

retira_avl (int id,int n)
{
	struct LIFO1 pila;
	int p,q,t,r,encontro,llave,terminar,accion;
	BUFFER r0,pc,qc,rc;

	ubicar (id,0);
	leer (id,r0);
	if (r0.izq == 0) {
		printf ("Archivo vacio \n");
		return (-1);
	}

	init1_pila (&pila);
	encontro = terminar = 0;
	p = r0.izq;
	while (!encontro && p != 0) {
		ubicar (id,p);
		leer (id,pc);
		ins1_pila (&pila,p,pc);
		if (n < pc.info)
			p = pc.izq;
		else if (n > pc.info)
			p = pc.der;
		else encontro = 1;
	}
	if (!encontro) {
		printf ("no existe en el archivo \n");
		return (-1);
	}


	retira1_pila (&pila,&p,&pc);
	llave = pc.info;
	if (pc.izq == 0 && pc.der == 0)
		accion = 0;
	else if (pc.der == 0)
		accion = 1;
	else if (pc.izq == 0)
		accion = 2;
	else accion = 3;

	t = 0;
	if (accion == 0 || accion == 1 || accion == 2) {
		if (!pila1_vacia (&pila) ) {
			retira1_pila (&pila,&q,&qc);
			if (llave < qc.info) {
				switch (accion) {
				   case 0:
				   case 1: qc.izq = pc.izq;
					   bal_der (id,q,&qc,&t,&terminar);
					   break;
				   case 2: qc.izq = pc.der;
					   bal_der (id,q,&qc,&t,&terminar);
					   break;
				}
			}
			else {
				switch (accion) {
				   case 0:
				   case 2: qc.der = pc.der;
					   bal_izq (id,q,&qc,&t,&terminar);
					   break;
				   case 1: qc.der = pc.izq;
					   bal_izq (id,q,&qc,&t,&terminar);
					   break;
				}
			}
		}
		else switch (accion) {
			case 0 : r0.izq = 0;
				 terminar = 1;
				 break;
			case 1 : r0.izq = pc.izq;
				 break;
			case 2 : r0.izq = pc.der;
				 break;
		     }
	}
	else {
			ins1_pila (&pila,p,pc);
			r = p;
			rc = pc;
			p = rc.der;
			ubicar (id,p);
			leer (id,pc);
			q = 0;
			while (pc.izq != 0)  {
				ins1_pila (&pila,p,pc);
				q = p;
				qc = pc;
				p = pc.izq;
				ubicar (id,p);
				leer (id,pc);
			}
			llave = rc.info = pc.info;
			ubicar (id,r);
			grabar (id,rc);
			if (q != 0) {
				qc.izq =pc.der;
				bal_der (id,q,&qc,&t,&terminar);
			}
			else {
				rc.der = pc.der;
				bal_izq (id,r,&rc,&t,&terminar);
			}
			retira1_pila (&pila,&q,&qc);
	}

	liberar_nodo (p,&pc,&r0);
	ubicar (id,p);
	grabar (id,pc);

	while (!pila1_vacia (&pila)  && !terminar) {
		retira1_pila (&pila,&q,&qc);
		if (llave < qc.info) {
			if (t != 0)  {
				qc.izq = t;
				t = 0;
			}
			if (accion == 3 && r == q)
				qc.info = llave;
			bal_der (id,q,&qc,&t,&terminar);
		}
		else {
				if (t != 0)  {
					qc.der = t;
					t = 0;
				}
				if (accion == 3 && r == q)
					qc.info = llave;
				bal_izq (id,q,&qc,&t,&terminar);
			}
	}


	if (t != 0)
		if (pila1_vacia (&pila) )
			r0.izq = t;
		else {
			retira1_pila (&pila,&q,&qc);
			if (accion == 3 && r == q)
				qc.info = llave;
			if (llave < qc.info)
			     qc.izq = t;
			else qc.der = t;
			ubicar (id,q);
			grabar (id,qc);
		      }

	ubicar (id,0);
	grabar (id,r0);
}


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
		printf ("%d %d   ",pc.info,pc.bal);
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


init1_pila (LIFO1 *p)
{
	p->t = 0;
}

pila1_vacia (LIFO1 *p)
{
	return (p->t == 0);
}

ins1_pila (LIFO1 *p,int s,BUFFER q)
{
	if (p->t == MAXIMO) {
		printf ("pila llena...");
		getch();
		exit (1);
	}
	else {
		p->a [p->t].direccion = s;
		p->a [p->t].d = q;
		p->t++;
	}
}

retira1_pila (LIFO1 *p, int *s, BUFFER *q)
{
	if (pila1_vacia (p) ) {
		printf ("pila vacia...");
		getch();
		exit (1);
	}
	else {
		p->t--;
		*s = p->a [p->t].direccion;
		*q = p->a [p->t].d;
	}
}

listar2(int id)
{
	BUFFER a;
	FILE *p;
	int i=0;

	p = fopen ("PRN","w");
	fprintf (p,"\n\n\n");
	ubicar (id,0);
	while ( _read (id,(char *)&a,LON) )
		fprintf (p,"%6d   %6d   %6d   %6d  %6d\n",
				i++,a.info,a.bal,a.izq,a.der);
}



