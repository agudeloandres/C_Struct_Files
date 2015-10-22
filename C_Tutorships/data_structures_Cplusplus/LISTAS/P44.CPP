#include <stdio.h>
#include <alloc.h>
#define  localizar  (struct nodo *) malloc (sizeof (struct nodo))

struct nodo {
	char info [30];
	struct nodo *sig;
};

void main()
{
	void retirar_despues (struct nodo *p, char *nombre);
	void insertar2 (struct nodo **p,char *n);
	void copiar (char *a,char *b);
	int converi (char a[]);
	int texto (char *a,int n);
   int compare (char *a,char *b);
	struct nodo  *cab;
	int n,i;
	char  nombre [30],linea[10];

	cab = NULL;
	printf ("de el primer nombre\n");
	texto (nombre,30);
	while (compare (nombre,"final") ) {
		insertar2 (&cab,nombre);
		printf ("de otro nombre\n");
		texto (nombre,30);
	}
	printf ("de valor para efectuar el conteo\n");
	texto (linea,10); n=converi(linea);
	while (cab != cab->sig) {
		for (i=1 ; i <= n-1 ; i++)
			cab = cab->sig;
		retirar_despues (cab,nombre);
		printf ("retirado...%s\n",nombre);
	}
	printf ("soldado escogido...%s\n",cab->info);
	free (cab);
}

void retirar_despues (struct nodo *p, char *nombre)
{
	struct nodo *q;
	void copiar (char *a,char *b);

	if (p == NULL)
	    printf ("lista vacia\n");
	else if (p == p->sig)
		printf ("solamente un nodo...");
		  else {
		      q = p->sig;
				copiar (nombre,q->info);
		      p->sig = q->sig;
		      free (q);
		   }
}

void insertar2 (struct nodo **p,char *n)
{
	struct nodo *nuevo;
	void copiar (char *a,char *b);
	nuevo = localizar;
	copiar (nuevo->info,n);
	if (*p == NULL)
		nuevo->sig = nuevo;
	else {
			nuevo->sig =(*p)->sig;
			(*p)->sig = nuevo;
		}
	*p = nuevo;
}
int texto (char *a,int n)
{
	int c,i;
	i=0;
	while (--n > 0 && (c=getchar()) != EOF && c != '\n')
	  *(a + i++) = c;
	a[i] = '\0';
	return (i);

}

void copiar (char *a,char *b)
{
	while (*a++ = *b++)
		;
}

int converi (char a[])
{
	int i,signo,n;

	i=0;
	while (a[i] == ' ' ||
			 a[i] == '\n' ||
			 a[i] == '\t' )
	  i++;
	signo=1;
	if (a[i] == '+' || a[i] == '-')
		signo = (a[i++] == '+') ? 1 : -1;
	n=0;
	while (a[i] >= '0' && a[i] <= '9')
			n = n * 10 + a[i++] - '0';
	return (n * signo);
}

int compare (char *a,char *b)
{
	while (*a == *b) {
		if (*a == '\0')
			return (0);
		a++;
		b++;
	}
	return (*a - *b);
}
