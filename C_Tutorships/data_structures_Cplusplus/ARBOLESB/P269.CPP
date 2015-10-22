#include "stdio.h"
#include "alloc.h"
#include "conio.h"
#include "string.h"
#define nodo_arbol  (struct nodo *) malloc (sizeof (struct nodo) )
#define LONGITUD  100

struct nodo {
	int info;
	struct nodo *izq;
	struct nodo *der;
};

void main()  /*  genera un  arbol binario */
		/* a partir de una expresion en prefijo */
{
	struct nodo *raiz;
	struct nodo *crea_arbol(char *prefijo);
	void construye (struct nodo *p,char *infijo);
	char  prefijo [LONGITUD];
	char  infijo [LONGITUD];
	clrscr();
	printf ("1. Este programa lee una expresion en prefijo y\n");
	printf ("   construye el arbol correspondiente.\n");
	printf ("2. Genera a partir de una expresion en un arbol\n");
	printf ("   una expresion parentizada escrita en infijo.\n\n\n");
	raiz = crea_arbol (prefijo);
	printf ("El arbol esta construido en la memoria... Oprima una tecla");
	getch();
	construye (raiz,infijo);
	printf ("expresion original en infijo.... %s\n",infijo);
	printf ("\nOprima una tecla para continuar...");getch();
}


#define MAXIMO 20

struct LIFO {
	int t;
	struct nodo *a[MAXIMO];
};

void construye (struct nodo *p,char *infijo)
{
	struct LIFO pila;
	struct nodo *q,*par;
	int i = 0;
   void init_pila (struct LIFO *p);
	int pila_vacia (struct LIFO *p);
	void ins_pila (struct LIFO *p, struct nodo *s);
	void retira_pila (struct LIFO *p,struct nodo **s);
	int prioridad (char op1,char op2);
	int operando (char c);
	par = nodo_arbol;
	par->info = ')';
	par->izq = par->der = NULL;
	init_pila (&pila);
	while (p) {
		q = p->izq;
		ins_pila (&pila,p);
		if (q)
			if (!operando (p->info) &&
				 !operando (q->info) &&
								prioridad (p->info,q->info) ) {
				ins_pila (&pila,par);
					infijo [i++] = '(';
			}
		p = p->izq;
	}
	while (!pila_vacia (&pila)) {
		retira_pila (&pila,&p);
		infijo [i++] = p->info;
		q = p->der;
		if (q)
			if (!operando (p->info) &&
				 !operando (q->info) &&
				prioridad (p->info,q->info) )  {
					infijo [i++] = '(';
					ins_pila (&pila,par);
			}
		p = p->der;
		while (p) {
			q = p->izq;
			ins_pila (&pila,p);
			if (q)
				if (!operando (p->info) &&
					 !operando (q->info) &&
							prioridad (p->info,q->info) ) {
					ins_pila (&pila,par);
						infijo [i++] = '(';
				}
			p = p->izq;
		}
	}
	infijo [i] = '\0';
}

void init_pila (struct LIFO *p)
{
	p->t = 0;
}

int pila_vacia (struct LIFO *p)
{
	return (!p->t);
}

void ins_pila (struct LIFO *p, struct nodo *s)
{
	if (p->t == MAXIMO)
		printf ("la pila no soporta mas elementos\n");
	else  {
			p->t++;
			p->a [p->t -1] = s;
	}
}

void retira_pila (struct LIFO *p,struct nodo **s)
{
	if (pila_vacia (p) )  {
		printf ("la pila esta vacia\n");
		*s = NULL;
	  }
	else  {
			*s = p->a [p->t -1];
			p->t--;
	}
}



int operando (char c)
{
	return (c != '+' &&
			 c != '-' &&
			 c != '*' &&
			 c != '/' &&
			 c != '^' &&
		    c != ')' &&
			 c != '('    );
}

static int m[6][7] = {
	{ 0,1,0,0,0,0,1 },
	{ 1,1,0,0,0,0,1 },
	{ 1,1,0,1,0,0,1 },
	{ 1,1,1,1,0,0,1 },
	{ 1,1,1,1,1,0,1 },
	{ 0,0,0,0,0,0,0 }
};

int prioridad (char op1,char op2)
{
	int i,j;

	switch (op1) {
		case '+' :  i = 0; break;
		case '-' :  i = 1; break;
		case '*' :  i = 2; break;
		case '/' :  i = 3; break;
		case '^' :  i = 4; break;
		case '(' :  i = 5; break;
	}
	switch (op2) {
		case '+' :  j = 0; break;
		case '-' :  j = 1; break;
		case '*' :  j = 2; break;
		case '/' :  j = 3; break;
		case '^' :  j = 4; break;
		case '(' :  j = 5; break;
		case ')' :  j = 6; break;
	}
	return (m [i][j]);
}

struct nodo *crea_arbol(char *prefijo)
/* construye una expresion en un arbol binario */
{
	struct nodo *raiz;
	void conformar (struct nodo **raiz,char *prefijo);
	printf ("   De expresion en prefijo. <Se asume correcta>\n\n");
	gets(prefijo);
	conformar (&raiz,prefijo);
	return (raiz);
}

#define MAXIMO1 20

struct LIFO1 {
	int t;
	struct nodo *a[MAXIMO1];
};


void init1_pila (struct LIFO1 *p)
{
	p->t = 0;
}

int pila1_vacia (struct LIFO1 *p)
{
	return (!p->t);
}

void ins1_pila (struct LIFO1 *p, struct nodo *s)
{
	if (p->t == MAXIMO)
		printf ("la pila no soporta mas elementos\n");
	else  {
			p->t++;
			p->a [p->t -1] = s;
	}
}

void retira1_pila (struct LIFO1 *p,struct nodo **s)
{
	if (pila1_vacia (p) )  {
		printf ("la pila esta vacia\n");
		*s = NULL;
	  }
	else  {
			*s = p->a [p->t -1];
			p->t--;
	}
}


void conformar (struct nodo **raiz,char *prefijo)
{
	struct nodo *ultimo,*nuevo;
	struct LIFO1 pila;
	int senal,i,caracter;

	i=0;
	caracter = prefijo [i++];
	nuevo = nodo_arbol;
	nuevo->info = caracter;
	*raiz = nuevo;
	senal = 0;
	init1_pila (&pila);
	caracter = prefijo [i++];
	while (caracter) {
		ultimo = nuevo;
		nuevo = nodo_arbol;
		nuevo->info = caracter;
		if (senal) {
			retira1_pila (&pila,&ultimo);
			ultimo->der = nuevo;
		}
		else {
				ultimo->izq = nuevo;
				ins1_pila (&pila,ultimo);
			}
		if (!operando (caracter))
			senal = 0;
		else {
				nuevo->izq = NULL;
				nuevo->der = NULL;
				senal = 1;
			}
		caracter = prefijo [i++];
	}
}


