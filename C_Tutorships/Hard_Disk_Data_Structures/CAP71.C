/* Este programa maneja un cursor AVL */

/* Se ejecuta desde el programa mcuravl.c */


#include "stdio.h"
#define MAXIMO 8
#define P(x) printf ("%s\n",x)
typedef struct CURSOR CURSOR;
struct CURSOR {
	int info;
	int bal,izq,der;
};



CURSOR a[MAXIMO];


captu ()
{
	capturar (a);
}

consul ()
{
	consul1 (a);
}
retirar ()
{
	retirar1 (a);
}


listar ()
{
	inorden (a);
}

inicializar ()
{
	init_cursor (a);
}

capturar (CURSOR a[])
{
	int n;

	P("De numero. <9999> para finalizar.");
	n = lea_entero();
	while (n != 9999) {
		if (ins_avl (a, n) == -1)
			P("Repetido...");
		else
			P("Insertado...");
		P("De numero. <9999> para finalizar.");
		n = lea_entero();
	}
}

consul1 (CURSOR a[])
{
	int n;

	P("De numero. <9999> para finalizar.");
	n = lea_entero();
	while (n != 9999) {
		if (consultar (a, n) == -1)
			P("No existe. Trate otra vez...");
		else P("Si existe...");
		P("De numero. <9999> para finalizar.");
		n = lea_entero();
	}
}

retirar1 (CURSOR a[])
{
	int n;

	P("De codigo a retirar... <9999> para finalizar.");
	n = lea_entero();
	while (n != 9999) {
		if (retira_avl (a, n) == -1)
			P("No existe. Trate otra vez...");
		else P("retirado... ");
		P("De numero. <9999> para finalizar.");
		n = lea_entero();
	}
}


lea_entero()
{
	char a[10];

	gets (a);
	return (atoi (a));
}

init_cursor (CURSOR a[])
{
	int i;

	a[0].izq = a[0].bal = 0;
	for (i=0; i < MAXIMO; i++) {
		a[i].bal = 0;
		a[i].der = i + 1;
	}
	a[i-1].der = 0;
}

ins_avl (CURSOR a[],int n)
{
	int nuevo,p,q,s,pivote,pp,llave,altura;

	nuevo = disp (a);
	a[nuevo].info = n;
	a[nuevo].bal = a[nuevo].izq = a[nuevo].der = 0;
	if (a[0].izq == 0) {
		a[0].izq = nuevo;
		return (0); /* Se inserto correctamente */
	}

	pp = q = 0;
	p = pivote = a[0].izq;
	llave = a[nuevo].info;
	while (p != 0) {
		if (a[p].bal) {
			pp = q;
			pivote = p;
		}
		if (llave == a[p].info) {
			liberar (a,nuevo);
			return (-1);  /* Ya existe */
		}
		else {
			q = p;
			if (llave < a[p].info)
				p = a[p].izq;
			else p = a[p].der;
		}
	}
	if (llave < a[q].info)
		a[q].izq = nuevo;
	else a[q].der = nuevo;

	if (llave < a[pivote].info) {
		s = a[pivote].izq;
		altura = 1;
	}
	else {
		s = a[pivote].der;
		altura = -1;
	}

	p = s;
	while (p != nuevo)
		if (llave < a[p].info) {
			a[p].bal = 1;
			p = a[p].izq;
		}
		else {
			a[p].bal = -1;
			p = a[p].der;
		}

	if (a[pivote].bal == 0)
		a[pivote].bal = altura;
	else	if (a[pivote].bal + altura == 0)
			a[pivote].bal = 0;
		else {
			if (altura == 1)
				if (a[s].bal == 1)
					r_derecha (a,pivote, s);
				else dr_derecha (a,pivote,&s);
			else 	if (a[s].bal == -1)
					r_izquierda (a,pivote,s);
				else dr_izquierda (a,pivote, &s);
			if (pp == 0)
				a[0].izq = s;
			else if (a[pp].izq == pivote)
				a[pp].izq = s;
			else a[pp].der = s;
		}

	return (0);  /* Se inserto correctamente */
}

r_derecha (CURSOR a[],int p,int q)
{
	a[p].bal = a[q].bal = 0;
	a[p].izq = a[q].der;
	a[q].der = p;
}

r_izquierda (CURSOR a[],int p,int q)
{
	a[p].bal = a[q].bal = 0;
	a[p].der = a[q].izq;
	a[q].izq = p;
}

dr_derecha (CURSOR a[],int p, int *q)
{
	int r;

	r = a[*q].der;
	a[*q].der = a[r].izq;
	a[r].izq = *q;
	a[p].izq = a[r].der;
	a[r].der = p;
	switch (a[r].bal) {
		case -1 : a[*q].bal = 1;
			  a[p].bal = 0;
			  break;
		case 0 :  a[*q].bal = a[p].bal = 0;
			  break;
		case 1 :  a[*q].bal = 0;
			  a[p].bal = -1;
			  break;
	}
	a[r].bal = 0;
	*q = r;
}

dr_izquierda (CURSOR a[],int p, int *q)
{
	int r;

	r = a[*q].izq;
	a[*q].izq = a[r].der;
	a[r].der = *q;
	a[p].der = a[r].izq;
	a[r].izq = p;
	switch (a[r].bal) {
		case -1 : a[*q].bal = 0;
			  a[p].bal = 1;
			  break;
		case 0 :  a[*q].bal = a[p].bal = 0;
			  break;
		case 1 :  a[*q].bal = -1;
			  a[p].bal = 0;
			  break;
	}
	a[r].bal = 0;
	*q = r;
}

consultar (CURSOR a[], int n)
{
	int p,enc = 0;

	p = a[0].izq;
	while ( p != 0 && !enc) {
		if (n < a[p].info)
			p = a[p].izq;
		else if (n > a[p].info)
			p = a[p].der;
		else enc = 1;
	}
	if (enc != 1)
		return (-1);
	else return (p);
}



disp (CURSOR a[])
{
	int i = a[0].der;

	if (i == 0)
		return (-1);
	else {
		a[0].der = a[i].der;
		return (i);
	}
}


liberar (CURSOR a[],int p)
{
	a[p].der = a[0].der;
	a[0].der = p;
}


bal_der (CURSOR a[],int q,int *t,int *terminar)
{
	switch (a[q].bal) {
		case  1 : a[q].bal = 0;
			  break;
		case -1 : *t = a[q].der;
			  switch ( a[*t].bal) {
			      case 1 : dr_izquierda(a,q,t);
				       break;
			      case -1: r_izquierda (a,q,*t);
				       break;
			      case 0 : a[q].der = a[*t].izq;
				       a[*t].izq = q;
				       a[*t].bal = 1;
				       *terminar = 1;
				       break;
			  }
			  break;
		case  0 : a[q].bal = -1;
			  *terminar = 1;
			  break;
	}
}

bal_izq (CURSOR a[],int q,int *t,int *terminar)
{
	switch (a[q].bal) {
		case -1 : a[q].bal = 0;
			  break;
		case  1 : *t = a[q].izq;
			  switch ( a[*t].bal) {
			  case  1: r_derecha (a,q,*t);
				   break;
			  case -1: dr_derecha (a,q,t);
				   break;
			  case 0 : a[q].izq = a[*t].der;
				   a[*t].der = q;
				   a[*t].bal = -1;
				   *terminar = 1;
				   break;
			  }
			  break;
		case  0 : a[q].bal = 1;
			  *terminar = 1;
			  break;
	}
}

typedef struct LIFO LIFO;
struct LIFO {
	int t;
	int a[MAXIMO];
};

retira_avl (CURSOR a[],int n)
{
	struct LIFO pila;
	int p,q,t,r,encontro,llave,terminar,accion;

	if (a[0].izq == 0) {
		printf ("Archivo vacio \n");
		return (-1);
	}

	init_pila (&pila);
	encontro = terminar = 0;
	p = a[0].izq;
	while (!encontro && p != 0) {
		ins_pila (&pila,p);
		if (n < a[p].info)
			p = a[p].izq;
		else if (n > a[p].info)
			p = a[p].der;
		else encontro = 1;
	}
	if (!encontro) {
		printf ("no existe en el archivo \n");
		return (-1);
	}
	t = 0;
	retira_pila (&pila,&p);
	llave = a[p].info;
	if (a[p].izq == 0 && a[p].der == 0)
		accion = 0;
	else if (a[p].der == 0)
		accion = 1;
	else if (a[p].izq == 0)
		accion = 2;
	else accion = 3;

	if (accion == 0 || accion == 1 || accion == 2) {
		if (!pila_vacia (&pila) ) {
			retira_pila (&pila,&q);
			if (llave < a[q].info) {
				switch (accion) {
				   case 0:
				   case 1: a[q].izq = a[p].izq;
					   bal_der (a,q,&t,&terminar);
					   break;
				   case 2: a[q].izq = a[p].der;
					   bal_der (a,q,&t,&terminar);
					   break;
				}
			}
			else {
				switch (accion) {
				   case 0:
				   case 2: a[q].der = a[p].der;
					   bal_izq (a,q,&t,&terminar);
					   break;
				   case 1: a[q].der = a[p].izq;
					   bal_izq (a,q,&t,&terminar);
					   break;
				}
			}
		}
		else switch (accion) {
			case 0 : a[0].izq = 0;
				 terminar = 1;
				 break;
			case 1 : a[0].izq = a[p].izq;
				 break;
			case 2 : a[0].izq = a[p].der;
				 break;
		     }
	}
	else {

			ins_pila (&pila,p);
			r = p; p = a[r].der;
			q = 0;
			while (a[p].izq != 0)  {
				ins_pila (&pila,p);
				q = p;
				p = a[p].izq;
			}
			llave = a[r].info = a[p].info;
			if (q != 0) {
				a[q].izq =a[p].der;
				bal_der (a,q,&t,&terminar);
			}
			else {
				a[r].der = a[p].der;
				bal_izq (a,r,&t,&terminar);
			}
			retira_pila (&pila,&q);
	}
	liberar (a,p);
	while (!pila_vacia (&pila)  && !terminar) {
		retira_pila (&pila,&q);
		if (llave < a[q].info) {
			if (t != 0)  {
				a[q].izq = t;
				t = 0;
			}
			bal_der (a,q,&t,&terminar);
		}
		else {
				if (t != 0)  {
					a[q].der = t;
					t = 0;
				}
				bal_izq (a,q,&t,&terminar);
			}
	}
	if (t != 0)
		if (pila_vacia (&pila) )
			a[0].izq = t;
		else {
			retira_pila (&pila,&q);
			if (llave < a[q].info)
			     a[q].izq = t;
			else a[q].der = t;
		      }
}



inorden (CURSOR a[])
{
	LIFO pila;
	int p = a[0].izq;

	init_pila (&pila);
	while (p != 0) {
		ins_pila (&pila,p);
		p = a[p].izq;
	}
	while (!pila_vacia (&pila) ) {
		retira_pila(&pila,&p);
		printf ("%d %d   ",a[p].info,a[p].bal);
		p = a[p].der;
                while (p != 0) {
			ins_pila (&pila,p);
			p = a[p].izq;
		}
	}
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




imp_cursor (CURSOR a[])
{
	int i;

	for (i=0; i < MAXIMO; i++)
		printf ("%d %d %d %d\n",a[i].info,a[i].bal,a[i].izq,a[i].der);
}