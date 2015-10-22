#include <stdio.h>
#include <alloc.h>
#define  localizar  (struct nodo *) malloc (sizeof (struct nodo))

struct nodo {
	int info;
	struct nodo *sig;
};

void main()
{
	struct nodo  *cabeza,*p;
	void retirar (struct nodo *p, int *dato);
	void escribir_lista (struct nodo *q);
	void insertar (struct nodo **cab,struct nodo *p,
				struct nodo *q,int n);
	void mantener (struct nodo **cab, int n);
	int numero;

	cabeza = NULL;
	printf ("de numero a insertar en la lista\n");
	scanf ("%d",&numero);
	while (numero != 9999) {
		mantener (&cabeza,numero);
		printf ("de numero a insertar en la lista\n");
		scanf ("%d",&numero);
	}
	p = cabeza;
	numero = -1;
	retirar (p,&numero);
	printf ("retirado....%d\n",numero);
	escribir_lista (cabeza);

}
/* retira el nodo despues de p */
void retirar (struct nodo *p, int *dato)
{
	struct nodo *q;

	if (p == NULL)
			printf ("no se puede retirar\n");
	else if (p->sig == NULL)
			printf ("no se puede retirar\n");
		  else {
				 q = p->sig;
				 *dato = q->info;
				 p->sig =q->sig;
				 free (q);
			}
}

void escribir_lista (struct nodo *q)
{
	while (q != NULL) {
		printf ("%d  ",q->info);
		q = q->sig;
	}
}
void insertar (struct nodo **cab,struct nodo *p,
				struct nodo *q,int n)
{
	struct nodo *nuevo;

	nuevo = localizar;
	nuevo->info = n;
	nuevo->sig = q;
	if (p != NULL)
		p->sig = nuevo;
	else *cab = nuevo;
}

void mantener (struct nodo **cab, int n)
{
	struct nodo *p,*q;
	int encontro ;

	p = NULL;
	q = *cab;
	encontro = 0;
	while ((q != NULL) && (!encontro))
		if (n > q->info) {
			p = q;
			q = q->sig;
		}
		else  encontro = 1;
	if (encontro)
		if (n == q->info)
		  printf ("repetido\n");
		else insertar (cab,p,q,n);
	else insertar (cab,p,q,n);
}

