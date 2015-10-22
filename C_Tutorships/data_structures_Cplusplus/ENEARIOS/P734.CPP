#include "stdio.h"
#include "stdlib.h"
struct ENEARIO {
	int Tarea;
	int Estado;
	int Tipo;
	ENEARIO *Hijo;
	ENEARIO *Hermano;
};

void Inorden(struct ENEARIO *p) {
	struct ENEARIO *q;
	if (p != NULL) {
		q = p->Hijo;
		if (q == NULL)
			printf ("%d %d %d \n",p->Tarea,p->Estado, p->Tipo);
		else {
			Inorden(q);
			printf ("%d %d %d \n",p->Tarea,p->Estado, p->Tipo);
			q = q->Hermano;
			while (q != NULL) {
				Inorden (q);
				q = q->Hermano;
			}
		}
	}
}

struct ENEARIO *Construir(struct ENEARIO *s,int h) {
	struct ENEARIO *Temp = NULL,*p,*q;
	char Aux[10];
	p = new struct ENEARIO;
	if(s == NULL)
		printf ("De la informacion del nodo raiz\n");
	else printf ("De la informacion del hijo %d del nodo %d\n",h,s->Tarea);
	printf ("De el numero de la tarea\n");
	gets (Aux);
	p->Tarea = atoi (Aux);
	printf ("De el estado de esa tarea\n");
	gets (Aux);
	p->Estado = atoi (Aux);
	printf ("De el tipo de nodo 1=OR, 2=AND\n");
	gets (Aux);
	p->Tipo = atoi (Aux);
	p->Hermano = p->Hijo = NULL;
	printf ("De el numero de hijos del nodo %d\n",p->Tarea);
	gets (Aux);
	int NHijos = atoi(Aux);

	for (int i=1; i <= NHijos; i++) {
			q  = Construir (p,i);
			if (p->Hijo == NULL)
				p->Hijo = q;
			if (Temp == NULL)
				Temp = q;
			else {
				Temp->Hermano = q;
				Temp = q;
			}
	}
	return p;
}

// OR = 1   AND = 2
struct ENEARIO *ArbolLogico(struct ENEARIO *p,int n) {
	struct ENEARIO *q;
	int x,y;
	if (p == NULL)
		return NULL;
	if (p->Tarea == n)   {
		p->Estado =  (p->Estado == 0) ? 1 : 0;
		return p;
	}
	q = p->Hijo;
	if (q == NULL)
		return NULL;
	x=y=0;
	while (q != NULL) {
		ArbolLogico(q,n);
		x++;
		if (q->Estado == 1)
			y++;
		q = q->Hermano;
	}
	if (p->Tipo == 1)   // OR
		p->Estado =  (y != 0) ? 1 : 0;
	else
		p->Estado =  (y != x) ? 0 : 1;
	return NULL;
}
void main() {
	struct ENEARIO *p;
	p = Construir (NULL,0);
	ArbolLogico (p,7);
	Inorden (p);
	printf ("\n");
	ArbolLogico (p,8);
	Inorden (p);
}
