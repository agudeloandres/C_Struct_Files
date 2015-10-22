#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <stdlib.h>
#define  nodo_arbol  (struct nodo *)malloc (sizeof (struct nodo))

struct nodo {
	int info;
	struct nodo *izq;
	struct nodo *der;
};

void main()
{
	struct nodo *raiz,*p,*q;
	int n;
	int lea_entero ();
	int buscar (struct nodo *p,int n);
	void ins_izq (struct nodo *p,int n);
	void ins_der (struct nodo *p,int n);
	printf ("de numero\n");
	n = lea_entero();
	raiz = nodo_arbol;
	raiz->info = n;
	raiz->izq = NULL;
	raiz->der = NULL;
	printf ("de numero\n");
	n = lea_entero();
	while (n != 9999) {
		p = q = raiz;
		while (p->info != n &&  q  != NULL ) {
			p = q;
			if (n < p->info)
				q = q->izq;
			else q = q->der;
		}
		if (p->info == n)
			printf ("numero repetido\n");
		  else if (n < p->info)
				ins_izq (p,n);
			else  ins_der (p,n);
		printf ("de numero\n");
		n = lea_entero ();
	}
	printf ("\n? que numero quiere buscar ? ");
	while ( (n = lea_entero()) != 9999) {
		printf ("%s\n",buscar(raiz,n) ? "si" : "no");
		printf ("\n? que numero quiere buscar ? ");
	}
}

int lea_entero ()
{
	char linea[10];
	gets (linea);
	return (atoi (linea));
}

void ins_izq (struct nodo *p,int n)
{
	struct nodo *nuevo;

	nuevo = nodo_arbol;
	nuevo->info = n;
	nuevo->izq = NULL;
	nuevo->der = NULL;
	p->izq = nuevo;
}

void ins_der (struct nodo *p,int n)
{
	struct nodo *nuevo;

	nuevo = nodo_arbol;
	nuevo->info = n;
	nuevo->izq = NULL;
	nuevo->der = NULL;
	p->der = nuevo;
}
buscar (struct nodo *p,int n)
{
	while (p)
		if (n < p->info)
			p = p->izq;
		else if (n > p->info)
			p = p->der;
		else return (1);
	return (0);
}

