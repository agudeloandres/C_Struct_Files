#include "stdio.h"

struct ENEARIO {
	char Juego[3][3];
	struct ENEARIO *Hijo;
	struct ENEARIO *Hermano;
};

void Inorden(struct ENEARIO *p) {
	struct ENEARIO *q;

	if (p != NULL) {
		q = p->Hijo;
		if (q == NULL) {
			int i,j;
			for (i=0;i < 3; i++) {
				for (j=0; j < 3; j++)
					if (p->Juego[i][j]!= ' ')
						printf ("%c",p->Juego[i][j]);
					else printf ("-");
				printf("\n");
			}
			printf("\n");
			printf("\n");
		}
		else {
			Inorden(q);
			int i,j;
			for (i=0;i < 3; i++) {
				for (j=0; j < 3; j++)
					if (p->Juego[i][j]!= ' ')
						printf ("%c",p->Juego[i][j]);
					else printf ("-");
				printf("\n");
			}
			printf("\n");
         printf("\n");
			q = q->Hermano;
			while (q != NULL) {
				Inorden (q);
				q = q->Hermano;
			}
		}
	}
}

void main() {
	void Jugadas (char m[][3], struct ENEARIO **p);
	struct ENEARIO *p;
	char Juego[3][3] = {
		{' ', 'h',' '},
		{' ', ' ',' '},
		{' ', ' ',' '}
	};
	Jugadas(Juego,&p);  // Este programa asume que el
								// computador juega
	Inorden(p);
}

void Jugadas (char m[][3], struct ENEARIO **p) {
	int Cont=0,i,j;
	// Cuenta el numero de matrices a generar
	for (i=0;i < 3; i++) {
		for (j=0; j < 3; j++)
			if (m[i][j] == ' ')
				Cont++;
	}
	// Crea nodo con la jugada del humano
	*p = new struct ENEARIO;
	for (i=0;i < 3; i++)
		for (j=0; j < 3; j++)
			(*p)->Juego[i][j] = m[i][j];
	(*p)->Hijo = (*p)->Hermano = NULL;
	// Genera todas la jugadas del computador
	if (Cont != 0) {
		struct ENEARIO *z;
		int k = 0;
		while (k < Cont) {
			z = new struct ENEARIO;
			for (i=0;i < 3; i++)
				for (j=0; j < 3; j++)
					z->Juego[i][j] = m[i][j];
			z->Hermano = (*p)->Hijo;
			z->Hijo = NULL;
			(*p)->Hijo = z;
			k++;
		}
		z = (*p)->Hijo;
		i = j = 0;
		while (z != NULL) {
			if (z->Juego[i][j] == ' ') {
				z->Juego [i][j] = 'c';
				z = z->Hermano;
			}
			j++;
			if (j == 3) {
				i++;
				j = 0;
			}
		}
	}
}

