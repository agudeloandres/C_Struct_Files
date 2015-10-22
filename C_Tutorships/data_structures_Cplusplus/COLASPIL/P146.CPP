/* ESTE PROGRAMA INCLUYE LAS RUTINAS :
		c_expresion()
		in_a_pos()
		operando()
		tope1()
		formar_e()
		evaluar()
		F()
		prioridad()
*/


#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include  <math.h>
#define MAXIMO 50

#define MAX  50

struct LIFO {
	int t;
	double a [MAXIMO];
};

struct LIFO1 {
	int t;
	char a [MAXIMO];
};

struct expre   {
	char op;
	double valor;
};

void main()
{
	int i;
	void formar_e (char p[],struct expre posfijo[],
							double operan[]);
	void c_expresion (char linea[],char infijo[],
					double operan []);
	struct expre posfijo [MAX];
	void evaluar (struct expre posfijo [],double *x);
	char infijo [MAX],posfijo1 [MAX],linea [100];
	void in_a_pos (char *infijo,char *posfijo);
	double x = 0;
	double	operan [MAX];
	for (i=0 ; i < MAX ; i++) {
		infijo [i] = ' ';
		linea [i] = ' ';
		operan [i] = 0;
		posfijo [i].op =  ' ';
		posfijo [i].valor = 0;
	}
	printf ("Lea expresion sin espacios y escrita correctamente\n");
	printf ("Este programa no valida los datos\n");
	printf ("La expresion debe estar en notacion infijo\n");
	printf ("La expresion puede tener parentesis\n");
	printf ("-----> ");
	gets (linea);
	c_expresion (linea,infijo,operan);
	in_a_pos (infijo,posfijo1);
	formar_e (posfijo1,posfijo,operan);
	evaluar (posfijo,&x);
	printf ("resultado =   %15.6f\n",x);
}

void formar_e (char p[],struct expre posfijo[],
							double operan[])
{
	int i,j;
	int operando (char c);;
	i = j = 0;
	while (p [i]) {
		 if (operando (p[i]) )  {
			 posfijo [j].op = 'v';
			 posfijo [j].valor = operan [ p[i] -'0' ];
		 }
		 else {
			 posfijo [j].op = 'r';
			 posfijo [j].valor =  p[i];
		 }
		 i++;
		 j++;
	}
	posfijo [j].op = 'r';
	posfijo [j].valor = '#';
}

void c_expresion (char linea[],char infijo[],double operan [])
{
	double cifra = 0;
	int i,j,k,m;
	char auxiliar[10];

	i = k = m = 0;
	while (linea[i]) {
		j = 0;
		while (linea[i] >= '0' && linea[i] <= '9' ||
				linea [i] == '.')
			auxiliar [j++] = linea[i++];
		if (j != 0) {
			auxiliar [j] = '\0';
			cifra = atof (auxiliar);
			infijo [k++] = m + '0';
			operan [m++] = cifra;
		}
		if (linea [i])
			infijo [k++] = linea [i++];
	}
	infijo [k++] = '#';
	infijo [k] = '\0';
}

void evaluar (struct expre posfijo [],double *x)
{
	struct LIFO pila;
	void init_pila (struct LIFO *p);
	int pila_vacia (struct LIFO *p);
	void ins_pila (struct LIFO *p,double s);
	void retira_pila (struct LIFO *p,double *s);
	double aux,a,b,r;
	void F(double a,double b,double *r,char op);
	int i = 0;
	char c;

	aux = a = b = r = 0;
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

void F(double a,double b,double *r,char op)
{
	switch (op) {
		case '+'  : *r = (a + b); break;
		case '-'  : *r = (a - b); break;
		case '*'  : *r = a * b; break;
			case '/'  : *r = (a / b); break;
		case '^'  : *r = exp (b * log (a));  break;
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

void ins_pila (struct LIFO *p,double s)
{
	if (p->t == MAXIMO)
		printf ("la pila no soporta mas elementos\n");
	else  {
		  p->t++;
		  p->a [p->t - 1] = s;
	}
}

void retira_pila (struct LIFO *p,double *s)
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



void in_a_pos (char *infijo,char *posfijo)
{
	struct LIFO1 pila;
	int i,j;
	char elemento;
	int operando (char c);
	int prioridad (char op1,char op2);
	char tope1 (struct LIFO1 p);
	void init1_pila (struct LIFO1 *p);
	int pila1_vacia (struct LIFO1 *p);
	void ins1_pila (struct LIFO1 *p,char s);
	void retira1_pila (struct LIFO1 *p,char *s);


	i=0;
	j=-1;
	init1_pila (&pila);
	while (infijo [i] != '#') {
		if (operando (infijo [i]) )
		 posfijo [++j] = infijo [i++];
		else {
			 while (!pila1_vacia (&pila)  &&
			prioridad (tope1 (pila),infijo [i] ) )  {
				retira1_pila (&pila,&elemento);
				posfijo [++j] = elemento;
			 }
			 if (infijo [i] == ')')
			 retira1_pila (&pila,&elemento);
			 else ins1_pila (&pila,infijo [i]);
			 i++;
		}
	}
	while (!pila1_vacia (&pila) ) {
		retira1_pila (&pila,&elemento);
		posfijo [++j] = elemento;
	}
	posfijo [++j] = '\0';
}

int operando (char c)
{
	return ( c != '+' &&
		 c != '-' &&
		 c != '*' &&
		 c != '/' &&
		 c != '^' &&
		 c != ')' &&
		 c != '('    );
}

static int m[6][7] = {
	{ 1,1,0,0,0,0,1 },
	{ 1,1,0,0,0,0,1 },
	{ 1,1,1,1,0,0,1 },
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

char tope1 (struct LIFO1 p)
{
	return ( p.a [p.t -1] );
}

void init1_pila (struct LIFO1 *p)
{
	p->t = 0;
}

int pila1_vacia (struct LIFO1 *p)
{
	return (!p->t);
}

void ins1_pila (struct LIFO1 *p,char s)
{
	if (p->t == MAXIMO)
		printf ("la pila no soporta mas elementos\n");
	else  {
		  p->t++;
		  p->a [p->t - 1] = s;
	}
}

void retira1_pila (struct LIFO1 *p,char *s)
{
	if (pila1_vacia (p) )  {
		printf ("la pila esta vacia\n");
		*s = '#';
	}
	else  {
		  *s = p->a [p->t - 1];
		  p->t--;
	}
}




