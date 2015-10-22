#include "stdio.h"
#include "conio.h"
#include "stdlib.h"


struct ENEARIO {
	int Info;
	struct ENEARIO *Hijo;
	struct ENEARIO *Hermano;
};

struct ENEARIO *Construir(struct ENEARIO *s,int h) {
	struct ENEARIO *Temp = NULL,*p,*q;
	char Aux[10];
	p = new struct ENEARIO;
	if(s == NULL)
		printf ("De la informacion del nodo raiz\n");
	else printf ("De la informacion del hijo %d del nodo %d\n",h,s->Info);
	gets (Aux);
	p->Info = atoi(Aux);
	p->Hermano = p->Hijo = NULL;
	printf ("De el numero de hijos del nodo %d\n",p->Info);
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

struct ENEARIO *Camino(struct ENEARIO *p,int n,
			struct ENEARIO **Lista) {
	struct ENEARIO *s,*q,*Nuevo;
	if (p == NULL)
		return p;
	if (p->Info == n) {
			Nuevo = new struct ENEARIO;
			Nuevo->Info = p->Info;
			Nuevo->Hijo = p->Hijo;
			Nuevo->Hermano = NULL;
			if (*Lista == NULL) {
				*Lista = Nuevo;
			}
			else {
				Nuevo->Hermano = *Lista;
				*Lista = Nuevo;
			}
			return p;
	}

	q = p->Hijo;
	while (q != NULL) {
		s = Camino(q,n,Lista);
		if (s != NULL) {
			Nuevo = new struct ENEARIO;
			Nuevo->Info = p->Info;
			Nuevo->Hijo = p->Hijo;
			Nuevo->Hermano = NULL;
			if (*Lista == NULL) {
				*Lista = Nuevo;
			}
			else {
				Nuevo->Hermano = *Lista;
				*Lista = Nuevo;
			}
			return p;
		}
		q = q->Hermano;
	}
	return NULL;
}


