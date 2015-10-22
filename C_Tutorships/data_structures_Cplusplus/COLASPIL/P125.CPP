
#include <stdio.h>
#include <alloc.h>
#include "math.h"
#define MAXIMO 10
#define MAX  20

struct LIFO {
	int t;
	float a [MAXIMO];
};

struct expre   {
	char op;
	float valor;
};

void main()
{
	struct expre posfijo [MAX];
	void evaluar (struct expre posfijo[],
				float *x);
	void lea_expresion (struct expre a[]);
	float x = 0;

	lea_expresion (posfijo);
	evaluar (posfijo,&x);
	printf ("resul=   %f\n",x);
}

void lea_expresion (struct expre a[])
{
	int i=0;
	float dato;
	char linea [20];
   printf ("LA EXPRESION DEBE ESTAR EN POSFIJO\n");
	printf("PARA EJECUTAR ESTE PROGRAMA AL PEDIR LA COMPONENTE, PRIMERO DE\n");
	printf("v o r Y LUEGO DE EL NUMERO SI FUE v O EL VALOR NUMERICO DEL\n");
	printf("OPERADOR SI FUE r. EL VALOR NUMERICO DE # ES 35.\n");
	printf("LA ULTIMA COMPONENTE DEBE SER SIEMPRE r Y LUEGO EL NUMERO 35\n");
	printf("Por ejemplo, para la expresion: 45 48 3 / +, se debe escribir:\n");
	printf("v:45:v:48:v:3:r:47:r:43::r:35\n");
	printf(" :  es ENTER\n");
	do {
		printf ("de  componente\n");
		gets (linea);
		a[i].op = linea [0];
		gets (linea);
		dato = (float)atof(linea);
		a[i].valor = dato;
		i++;
	} while (dato != (float)'#');
}

void evaluar (struct expre posfijo[],float *x)
{
	struct LIFO pila;
	void init_pila (struct LIFO *p);
	int pila_vacia (struct LIFO *p);
	void ins_pila (struct LIFO *p,float s);
	void retira_pila (struct LIFO *p,float *s);
	void F(float a,float b,float *r,char op);
	float aux,a,b,r;
	int i = 0;
	char c;

	init_pila (&pila);
	while (posfijo [i].op == 'v'  || posfijo [i].op == 'r') {
		if (posfijo [i].op == 'v') {
			aux = posfijo [i].valor;
			ins_pila (&pila,aux);
		}
		else if (posfijo [i].valor != '#') {
				retira_pila (&pila,&b);
				retira_pila (&pila,&a);
				c = (char)posfijo [i].valor;
				F (a,b,&r,c);
				ins_pila (&pila,r);
		}
		i++;
	}
	*x = pila.a[0];
}

void F(float a,float b,float *r,char op)
{
	switch (op) {
		case '+'  : *r = (a + b); break;
		case '-'  : *r = (a - b); break;
		case '*'  : *r = a * b; break;
		case '/'  : *r = (a / b); break;
		case '^'  : *r = exp (b * log(a)); break;
		default   : printf ("situacion de error\n"); break;
	}
}

void init_pila (struct LIFO *p)
{
	p->t = 0;
}

int pila_vacia (struct LIFO *p)
{
	return (!p->t);
}

void ins_pila (struct LIFO *p,float s)
{
	if (p->t == MAXIMO)
		printf ("la pila no soporta mas elementos\n");
	else  {
		  p->t++;
		  p->a [p->t - 1] = s;
	}
}

void retira_pila (struct LIFO *p,float *s)
{
	if (pila_vacia (p) )  {
		printf ("la pila esta vacia\n");
		*s = '#';
	}
	else  {
		  *s = p->a [p->t - 1];
		  p->t--;
	}
}





