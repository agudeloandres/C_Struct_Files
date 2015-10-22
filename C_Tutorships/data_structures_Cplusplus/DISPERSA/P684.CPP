////////////////////////////////////////

// En este programa se encuentran todas
// Las rutinas de este capitulo.

////////////////////////////////////////

#include "stdio.h"
#include "alloc.h"
#include "conio.h"

struct NodoFila {
	int Fil;
	int Valor;
	struct NodoFila *Sig;
};

struct NodoColumna {
	int Col;
	struct NodoColumna *Sig;
	struct NodoFila *Cab;
};

void Imprimir (struct NodoColumna *M) {
	struct NodoColumna *q=M;
	struct NodoFila *p;
	while (q != NULL) {
		printf ("Columna %d : ",q->Col);
		p = q->Cab;
		while (p != NULL) {
			printf ("|%d  %d ",p->Fil, p->Valor);
			p = p->Sig;
		}
		printf ("\n");
		q = q->Sig;
	}
	printf ("\n");
}


void InitMatriz (struct NodoColumna **p) {
	*p =NULL;
}
void CambiarValor (struct NodoColumna **M, int Fila, int Columna, int Valor) {
	struct NodoColumna *NColumna,*q,*t;
	struct NodoFila *n,*p,*s;
	int enc;

	q = *M;
	t = NULL;
	enc = 0;
	while (q != NULL && !enc) {
		if (q->Col < Columna) {
			t = q;
			q = q->Sig;
		}
		else enc = 1;
	}
	if (q != NULL) {
		if (q->Col == Columna) {
			s = NULL;
			p = q->Cab;
			enc = 0;
			while (p != NULL && !enc) {
				if (p->Fil < Fila) {
					s = p;
					p = p->Sig;
				}
				else enc = 1;
			}
			if (p != NULL) {
				if (p->Fil == Fila) {
					if (Valor != 0)
						p->Valor = Valor;   // Cambia Valor
					else {
						if (s != NULL) {
							s->Sig = p->Sig;       // Existe mas de un nodo
							free (p);
						}
						else  {
							if (p->Sig == NULL) {
								t->Sig = q->Sig;
								free (q->Cab);
								free (q);
							}
							else {
								q->Cab = p->Sig;
								free (p);
							}
						}

					}
				}
				else {
					n = (struct NodoFila*)malloc (sizeof (struct NodoFila));
					n->Fil = Fila;
					n->Valor = Valor;
					n->Sig = p;
					if (s != NULL)
						s->Sig = n;
					else q->Cab = n;
				}
			}
			else {
					n = (struct NodoFila*)malloc (sizeof (struct NodoFila));
					n->Fil = Fila;
					n->Valor = Valor;
					n->Sig = NULL;
					if (s != NULL)
						s->Sig = n;
					else q->Cab = n;
			}
		}
		else {
			if (Valor != 0) {
				NColumna = (struct NodoColumna*)malloc (sizeof (struct NodoColumna));
				NColumna->Col = Columna;
				NColumna->Sig = q;
				if (t != NULL)
					t->Sig = NColumna;
				else *M = NColumna;
				n = (struct NodoFila*)malloc (sizeof (struct NodoFila));
				n->Fil = Fila;
				n->Valor = Valor;
				n->Sig = NULL;
				NColumna->Cab = n;
			}
		}
	}
	else {
		if (Valor != 0) {
			NColumna = (struct NodoColumna*)malloc (sizeof (struct NodoColumna));
			NColumna->Col = Columna;
			NColumna->Sig = NULL;
			if (t != NULL)
				t->Sig = NColumna;
			else *M = NColumna;
			n = (struct NodoFila*)malloc (sizeof (struct NodoFila));
			n->Fil = Fila;
			n->Valor = Valor;
			n->Sig = NULL;
			NColumna->Cab = n;
		}
	}
}

int ValorMatriz  (struct NodoColumna *M, int Fila, int Columna) {
	struct NodoColumna *q;
	struct NodoFila *p;
	int enc;

	q = M;
	enc = 0;
	while (q != NULL && !enc) {
		if (q->Col < Columna)
			q = q->Sig;
		else enc = 1;
	}
	if (q != NULL) {
		if (q->Col == Columna) {
			p = q->Cab;
			enc = 0;
			while (p != NULL && !enc) {
				if (p->Fil < Fila)
					p = p->Sig;
				else enc = 1;
			}
			if (p != NULL) {
				if (p->Fil == Fila) {
					return p->Valor;
				}
			}
		}
	}
	return 0;
}

int MaxFilas  (struct NodoColumna *M) {
	struct NodoColumna *q;
	struct NodoFila *p,*t;
	int Maximo = 0;

	if (M == NULL)
		return 0;
	q = M;
	while (q != NULL) {
		p = q->Cab;
		t = NULL;
		while (p != NULL) {
			t = p;
			p = p->Sig;
		}
		if (t->Fil > Maximo)
			Maximo = t->Fil;
		q = q->Sig;
	}
	return Maximo;
}
int MaxCol  (struct NodoColumna *M) {
	struct NodoColumna *q,*t;
	q = M;
	t = NULL;
	while (q != NULL) {
			t = q;
			q = q->Sig;
	}
	if (t != NULL)
		return t->Col;
	return 0;
}

int MultMat (struct NodoColumna *M1,struct NodoColumna *M2,struct NodoColumna **M3) {
	int i,j,k,Temp,T1,T2;
	InitMatriz (M3);
	if (MaxCol (M1) != MaxFilas (M2) ) {
		printf ("No se pueden multiplicar\n");
		return 0;
	}
	for (i=1; i <= MaxFilas(M1); i++) {
		for (k=1; k <= MaxCol (M2); k++) {
			Temp = ValorMatriz (*M3,i,k);
			for (j=1; j <= MaxFilas (M2); j++) {
				T1 = ValorMatriz (M1,i,j);
				T2 = ValorMatriz (M2,j,k);
				Temp = Temp + T1 * T2;
			}
			CambiarValor (M3,i,k,Temp);
		}
	}
	return 1;
}
void Destruir (struct NodoColumna **p) {
	struct NodoFila *q,*s;
	struct NodoColumna *t;

	while ((*p) != NULL) {
		t = (*p)->Sig;
		q = (*p)->Cab;
		while (q != NULL) {
			s = q->Sig;
			free(q);
			q = s;
		}
		free (*p);
		*p = t;
	}
}

void Nueva (struct NodoColumna *M,int Orden, int i,int j,struct NodoColumna **M1) {
	int k,l,m,n,Temp;
	m=1;
	InitMatriz (M1);
	for (k=1; k <= Orden; k++) {
		if (k != i) {
			n=1;
			for (l=1; l <= Orden; l++) {
				if (l != j) {
					Temp = ValorMatriz (M,k,l);
					CambiarValor (M1,m,n,Temp);
					n++;
				}
			}
			m++;
		}
	}
}
int Determ (struct NodoColumna *M, int Orden) {
	void Nueva (struct NodoColumna *M,int Orden, int i,int j,struct NodoColumna **M1);
	if (Orden == 2) {
		int Aux;
		Aux = ValorMatriz(M,1,1) * ValorMatriz(M,2,2) -
					ValorMatriz(M,2,1) * ValorMatriz(M,1,2);
		return Aux;
	}
	else {
		int i,j;
		int R,Signo=1;
		struct NodoColumna *M1;
		R = 0;
		i=1;
		for (j=1; j <= Orden; j++) {
				Nueva (M,Orden,i,j,&M1);
				R = R + Signo * ValorMatriz(M,i,j) * Determ (M1,Orden-1);
				Destruir (&M1);
				Signo = -Signo;
		}
		return R;
	}
}



void main() {
	void Destruir (struct NodoColumna **p);
	clrscr();
	struct NodoColumna *M1,*M2,*M3,*M4;
	int i,j;
	char Aux[20];
	InitMatriz(&M1);
	InitMatriz(&M2);
	CambiarValor (&M1,1,1,1);
	CambiarValor (&M1,2,1,7);
	CambiarValor (&M1,3,2,6);
	CambiarValor (&M1,3,3,5);

	CambiarValor (&M2,1,3,3);
	CambiarValor (&M2,2,1,4);
	CambiarValor (&M2,2,3,2);
	CambiarValor (&M2,3,2,2);
	CambiarValor (&M2,3,4,8);
	Imprimir (M1);
	Imprimir (M2);
	MultMat (M1,M2,&M3);
	printf ("Resultado de la multiplicacion\n");
	Imprimir(M3);  // Resultado de la multiplicacion
	Destruir (&M1);
	Destruir(&M2);
	Destruir (&M3);
// La matriz debe ser cuadrada.
// El programa no lo valida
	int Determ (struct NodoColumna *M, int Orden); // Prototipo
	InitMatriz(&M4);
	CambiarValor (&M4,1,1,2);
	CambiarValor (&M4,1,2,3);
	CambiarValor (&M4,1,3,2);
	CambiarValor (&M4,1,4,1);

	CambiarValor (&M4,2,1,3);
	CambiarValor (&M4,2,2,-2);
	CambiarValor (&M4,2,3,1);
	CambiarValor (&M4,2,4,2);

	CambiarValor (&M4,3,1,3);
	CambiarValor (&M4,3,2,2);
	CambiarValor (&M4,3,3,3);
	CambiarValor (&M4,3,4,4);

	CambiarValor (&M4,4,1,-2);
	CambiarValor (&M4,4,2,4);
	CambiarValor (&M4,4,3,0);
	CambiarValor (&M4,4,4,5);

	printf ("%d OK\n",Determ (M4,4) );
	Destruir (&M4);
	getch();
}
