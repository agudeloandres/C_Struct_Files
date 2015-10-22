#include "stdio.h"
#include "latino.c"

#define localizar  (struct nodo *) malloc (sizeof (struct nodo))

#define NE 11 /* numero de eventos reales + 1 */
#define NA 18  /* No de actv. reales + 1  */
#define NER NE-1
#define NAR NA-1
#define P(x) printf ("%s\n",x)

struct nodo {
	int info;
	struct nodo *sig;
};

struct todo {
	int tiempo,act;
};

struct nucleo {
	int temp,tarde;
};

main()
{
	struct todo eventos[NE][NE];
	struct nucleo even [NE];
	struct nucleo act [NA];
	struct nodo *cab;
	int topo [NE],i,j,suma,F,C,mayor = -32768;

	iniciar (&cab);
	for (i=1; i<=NER; i++) {
		topo [i] = 0;
		even [i].temp = even[i].tarde = 0;
	}
	for (i=1; i<=NAR; i++) {
		act [i].temp = act [i].tarde = 0;
	}


	cargar (eventos);
	for (j=1; j <= NER; j++)
		for (i=1; i <= NER; i++)
			if (eventos [i][j].tiempo != 0)
				topo [j] += 1;
	for (i=1;i<=NER;i++)
		if (topo [i] == 0 )
			sumar (&cab,i);
	while (!vacia (&cab)) {
		atender (&cab,&F);
		for (C=1; C<= NER; C++)
			if (eventos [F][C].tiempo != 0) {
				topo[C]--;
				if (topo[C] == 0)
					sumar (&cab,C);
				act[eventos[F][C].act].temp =
					even [F].temp;
				suma = even[F].temp + eventos [F][C].tiempo;
				if (even[C].temp < suma)
					even[C].temp =  suma;
				if (suma > mayor)
					mayor = suma;
			}
	}

	for (i=1; i<=NER; i++)
		topo [i] = 0;
	for (i=1; i <= NER; i++)
		for (j=1; j <= NER; j++)
			if (eventos [i][j].tiempo != 0)
				topo [i] += 1;
	for (i=1;i<=NER;i++)
		if (topo [i] == 0 )
			sumar (&cab,i);
	for (i=1; i <= NER; i++)
		even [i].tarde = mayor;
	while (!vacia (&cab)) {
		atender (&cab,&C);
		for (F=1; F<= NER; F++)
			if (eventos [F][C].tiempo != 0) {
				topo[F]--;
				if (topo[F] == 0)
					sumar (&cab,F);
				suma = even[C].tarde - eventos [F][C].tiempo;
				if (even[F].tarde > suma)
					even[F].tarde =  suma;
				act[eventos[F][C].act].tarde = suma;
			}
	}
	P(" ");
	for (i=1; i<=NER; i++) {
		printf ("%4d",even [i].temp);
	}
	P(" ");
	for (i=1; i<=NER; i++) {
		printf ("%4d",even [i].tarde);
	}
	P(" ");
	P(" ");
	for (i=1; i<=NAR; i++) {
		printf ("%4d",act [i].temp);
	}
	P(" ");
	for (i=1; i<=NAR; i++) {
		printf ("%4d",act [i].tarde);
	}
	P("\nRUTA CRITICA.....");
	P("EVENTOS..");
	for (i=1; i <= NER; i++)
		if (even [i].temp == even [i].tarde)
			printf ("%4d ",i);
	P("\nACTIVIDADES ");
	for (i=1; i <= NAR; i++)
		if (act [i].temp == act [i].tarde)
			printf ("%4d ",i);
	getch();
}

struct DATOS {
	int v1,v2,dias,acti;
};
cargar (struct todo eventos[][NE] )
{
	int k,i,j,tiempo,activ;
	struct DATOS a[20];
	char aux [40];

	printf ("\nlea el dato\n");
	gets (aux);
	a[0].v1 = 1; a[0].v2 =2; a[0].acti = 1; a[0].dias=aux[0];
	a[1].v1 = 1; a[1].v2 =3; a[1].acti =11 ;a[1].dias=aux[10];
	a[2].v1 = 2; a[2].v2 =4; a[2].acti = 2; a[2].dias=aux[1];
	a[3].v1 = 3; a[3].v2 =5; a[3].acti =12; a[3].dias=aux[11];
	a[4].v1 = 4; a[4].v2 =5; a[4].acti =10; a[4].dias=aux[9];
	a[5].v1 = 4; a[5].v2 =7; a[5].acti =13;  a[5].dias=aux[12];
	a[6].v1 = 4; a[6].v2 =6; a[6].acti = 3;  a[6].dias=aux[2];
	a[7].v1 = 5; a[7].v2 =7; a[7].acti = 8;  a[7].dias=aux[7];
	a[8].v1 = 5; a[8].v2 =8; a[8].acti = 9;  a[8].dias=aux[8];
	a[9].v1 = 8; a[9].v2 =9; a[9].acti = 7;  a[9].dias=aux[6];
	a[10].v1 = 7; a[10].v2 =9; a[10].acti = 6;a[10].dias=aux[5];
	a[11].v1 = 6; a[11].v2 =10;a[11].acti = 4;a[11].dias=aux[3];
	a[12].v1 = 9; a[12].v2 =10;a[12].acti = 5;a[12].dias=aux[4];

	a[13].v1 = 3; a[13].v2 =2; a[13].acti =14;a[13].dias=aux[13];
	a[14].v1 = 3; a[14].v2 =4 ;a[14].acti =15;a[14].dias=aux[14];
	a[15].v1 = 7; a[15].v2 = 6;a[15].acti =16;a[15].dias=aux[15];
	a[16].v1 = 8; a[16].v2 =10;a[16].acti =17;a[16].dias=aux[10];
	a[17].v1 = 9999; a[17].v2 =10;a[17].acti = 5;a[17].dias=aux[13];
	for (i=0; i < NE; i++)
		for (j=0; j < NA; j++)
			eventos [i][j].tiempo = eventos [i][j].act = 0;
	k = 0;
	i = a[k].v1;
	while (i != 9999) {
		j = a[k].v2;
		tiempo = a[k].dias;
		activ = a[k].acti;
		k++;
		eventos [i][j].tiempo = tiempo;
		eventos [i][j].act = activ;
		i = a[k].v1;
	}
}

lea()
{
	char a[5];
	texto (a,5);
	return (converi (a));
}



iniciar (p)
struct nodo **p;
{
	*p = localizar;
	(*p)->sig = *p;
}

sumar (p,objeto)
struct nodo **p;
int objeto;
{
	struct nodo *nuevo;

	nuevo = localizar;
	nuevo->info = objeto;
	nuevo->sig = (*p)->sig;
	(*p)->sig = nuevo;
	*p = nuevo;
}

atender (p,s)
struct nodo **p;
int  *s;
{
	struct nodo *q,*r;

	if (*p == (*p)->sig) {
	   printf ("no existen objetos para atender\n");
	   *s = '#';
	}
	else {
		  q = (*p)->sig;
		  r = q->sig;
		  *s = r->info;
		  q->sig = r->sig;
		  if (q == q->sig)
		      *p = q;
		  free (r);
	     }
}


vacia (p)
struct nodo **p;
{
	return (*p == (*p)->sig);
}
