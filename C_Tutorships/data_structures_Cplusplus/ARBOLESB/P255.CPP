/* EN ESTE PROGRAMA SE INCLUYEN TODAS LAS RUTINAS QUE CONFORMAN
   EL PROGRAMA QUE MANEJA UN INDICE ANALITICO EN MEMORIA DINAMICA
   UTILIZANDO ARBOLES BINARIOS  */

#include "stdio.h"
#include "alloc.h"
#include "stdlib.h"
#include "string.h"
#define nodo_arbol  (struct termino *)  malloc (sizeof (struct termino))
#define nodo1_arbol (struct paginas *)  malloc (sizeof (struct paginas))
#define nodo2_arbol (struct subtermino *)malloc (sizeof (struct subtermino))

struct paginas {
	int info;
	struct paginas *izq;
	struct paginas *der;
};

struct subtermino {
	char info [30];
	struct subtermino *izq;
	struct subtermino *der;
	struct paginas *pag;
};

struct termino {
	char info [30];
	struct termino *izq;
	struct termino *der;
	struct paginas *pag;
	struct subtermino *sub;
};

void main()
{
	struct termino *raiz,*p;
	struct subtermino *raizsub,*q;
	char linea [60],tipo,palabra [30];
	int n,numeros [15];
	void configurar (char *linea,char *tipo,
			char *palabra,int *n,int *numeros);
	void ins_p (struct termino *raiz,
			struct termino **donde,char *palabra);
	void inorden(struct termino *);
	void ins_paginas (struct paginas **raiz,int n,
				int *enteros);
	void ins_subtermino (struct subtermino *raiz,
					struct subtermino **donde,char *palabra);
	printf ("Para leer los datos, favor consultar\n");
	printf ("paginas 253 y 254\n");
	printf ("----> ");
	gets (linea);
	raiz = NULL;
	while (strcmp(linea,"final") ) {
		configurar (linea,&tipo,palabra,&n,numeros);
		if (raiz == NULL) {
			raiz = nodo_arbol;
			strcpy(raiz->info,palabra);
			raiz->izq = raiz->der = NULL;
			raiz->pag = NULL;
			raiz->sub = NULL;
			p = raiz;
			ins_paginas (&p->pag,n,numeros);
			raizsub = NULL;
		}
		else {
				if (tipo == 't') {
					ins_p (raiz,&p,palabra);
						ins_paginas (&p->pag,n,numeros);
					raizsub = p->sub;
				}
				else {
						if (raizsub == NULL) {
						 	raizsub = nodo2_arbol;
							strcpy(raizsub->info, palabra);
							raizsub->izq = raizsub->der = NULL;
							raizsub->pag = NULL;
							p->sub = q = raizsub;
							ins_paginas (&q->pag,n,numeros);
						}
						else {
								ins_subtermino (p->sub,&q,palabra);
								ins_paginas (&q->pag,n,numeros);
							}
					}
			}
		printf ("----> ");
		gets (linea);
	}
	inorden (raiz); /* Esta rutina utiliza recursion */
}

void configurar (char *linea,char *tipo,
			char *palabra,int *n,int *numeros)
{
	int i,j;

	*tipo = linea [0];
	j=1;
	while (linea[j] == ' ') j++;
	i=0;
	while (linea [j] != ' ' && linea [j] != '\0')
		palabra [i++] = linea [j++];
	palabra [i] = '\0';
	while (linea[j] == ' ') j++;
	i = 0;
	while (linea [j]) {
		numeros [i] = 0;
		while (linea [j] >= '0' && linea [j] <= '9')
			numeros [i] = numeros [i] * 10  + linea [j++] - '0';
		while (linea[j] == ' ') j++;
		i++;
	}
	*n = i;
}

void ins_p (struct termino *raiz,struct termino **donde,
				char *palabra)
{
	struct termino *p,*q;
	void ins_izq (struct termino *p,char *n);
	void ins_der (struct termino *p,char *n);
	p = q = raiz;
	while (strcmp(p->info,palabra) &&  q  != NULL ) {
		p = q;
		if (strcmp(palabra, p->info) < 0)
			q = q->izq;
		else q = q->der;
	}
	*donde = p;
	  if (strcmp(palabra, p->info) < 0) {
				ins_izq (p,palabra);
			*donde = p->izq;
	}
	else if (strcmp(palabra,p->info) > 0) {
					ins_der (p,palabra);
			*donde = p->der;
	}
}


void ins_izq (struct termino *p,char *n)
{
	struct termino *nuevo;

	nuevo = nodo_arbol;
	strcpy(nuevo->info,n);
	nuevo->izq = nuevo->der = NULL;
	  nuevo->pag = NULL;
	nuevo->sub = NULL;
	p->izq = nuevo;
}

void ins_der(struct termino *p,char *n)
{
	struct termino *nuevo;

	nuevo = nodo_arbol;
	strcpy(nuevo->info,n);
	nuevo->izq = nuevo->der = NULL;
     nuevo->pag = NULL;
	nuevo->sub = NULL;
	p->der = nuevo;
}

void inorden (struct termino *p)
{
	void inorden1 (struct paginas *p);
	void inorden2 (struct subtermino *p);
	if (p) {
		if (p->izq)
			inorden (p->izq);
		printf ("\n%s  ",p->info);
		inorden1 (p->pag);
		printf ("\n");
		inorden2 (p->sub);
		if (p->der)
			inorden (p->der);
	}
}

void ins_paginas (struct paginas **raiz,int n,
				int *enteros)
{
	struct paginas *p,*q;
	void insp_der (struct paginas *p,int n);
	void insp_izq (struct paginas *p,int n);
	if (*raiz == NULL && n) {
		*raiz = nodo1_arbol;
		(*raiz)->info = enteros [n-- -1];
		(*raiz)->izq = NULL;
		(*raiz)->der = NULL;
	}
	while (n > 0) {
		p = q = *raiz;
		while (p->info != enteros [n-1] &&  q  != NULL ) {
			p = q;
			if (enteros [n-1] < p->info)
				q = q->izq;
			else q = q->der;
		}
     	if (enteros [n-1] < p->info)
			insp_izq (p,enteros [n-1]);
		else if (enteros [n-1] > p->info)
          	   insp_der (p,enteros [n-1]);
		n--;
	}
}


void insp_izq (struct paginas *p,int n)
{
	struct paginas *nuevo;

	nuevo = nodo1_arbol;
	nuevo->info = n;
	nuevo->izq = nuevo->der = NULL;
	p->izq = nuevo;
}


void insp_der (struct paginas *p,int n)
{
	struct paginas *nuevo;

	nuevo = nodo1_arbol;
	nuevo->info = n;
	nuevo->izq = nuevo->der = NULL;
	p->der = nuevo;
}

void inorden1 (struct paginas *p)
{
	if (p) {
		if (p->izq)
			inorden1 (p->izq);
		printf ("%d  ",p->info);
		if (p->der)
			inorden1 (p->der);
	}
}

void inorden2 (struct subtermino *p)
{
	if (p) {
		if (p->izq)
			inorden2 (p->izq);
		printf ("       %s ",p->info);
		inorden1 (p->pag);
		printf ("\n");
		if (p->der)
			inorden2 (p->der);
	}
}


void ins_subtermino (struct subtermino *raiz,
					struct subtermino **donde,char *palabra)
{
	struct subtermino *p,*q;
	void inss_der (struct subtermino *p,char *n);
	void inss_izq (struct subtermino *p,char *n);
	p = q = raiz;
	while (strcmp(p->info,palabra) &&  q  != NULL ) {
		p = q;
		if (strcmp(palabra, p->info) < 0)
			q = q->izq;
		else q = q->der;
	}
	*donde = p;
	  if (strcmp(palabra, p->info) < 0) {
				inss_izq (p,palabra);
			*donde = p->izq;
	}
	else if (strcmp (palabra,p->info) > 0) {
					inss_der (p,palabra);
			*donde = p->der;
	}
}


void inss_izq (struct subtermino *p,char *n)
{
	struct subtermino *nuevo;

	nuevo = nodo2_arbol;
	strcpy(nuevo->info,n);
	nuevo->izq = nuevo->der = NULL;
		nuevo->pag = NULL;
	p->izq = nuevo;
}


void inss_der (struct subtermino *p,char *n)
{
	struct subtermino *nuevo;

	nuevo = nodo2_arbol;
	strcpy(nuevo->info,n);
	nuevo->izq = nuevo->der = NULL;
		nuevo->pag = NULL;
	p->der = nuevo;
}

