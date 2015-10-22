	#include "stdio.h"
	#include "conio.h"
	#include "stdlib.h"
	struct FIFO {
			struct ENEARIO *Info;
			struct FIFO *Sig;
			int Nivel;
	};

	void InitCola (struct FIFO **p) {
		*p = new FIFO;
		(*p)->Sig = *p;
	}

	int ColaVacia(struct FIFO *p) {
		return p == p->Sig;
	}

	void InsCola (struct FIFO **p, struct ENEARIO *pp,int n) {
		struct FIFO *q =  new struct FIFO;
		q->Info = pp;
		q->Nivel = n;
		q->Sig = (*p)->Sig;
		(*p)->Sig = q;
		(*p) = q;
	}

	struct ENEARIO *RetCola (struct FIFO **p,int *pp) {
		struct FIFO *q,*r;
		struct ENEARIO *Temp;
		if (!ColaVacia(*p)) {
			q = (*p)->Sig;
			r = q->Sig;
			Temp = r->Info;
			*pp = r->Nivel;
			q->Sig = r->Sig;
			if (r == *p)
				*p = q;
			delete r;
			return Temp;
		}
		else {
			printf ("Error...\n");
			return 0;
		}
	}
	struct LIFO {
		struct ENEARIO *Info;
		struct LIFO *Sig;
	};

	void InitPila (struct LIFO **p) {
		*p = NULL;
	}

	int PilaVacia(struct LIFO *p) { return p == NULL; }

	void InsPila (struct LIFO **p,struct ENEARIO *pp) {
		struct LIFO *q =  new struct LIFO;
		q->Info = pp;
		q->Sig = *p;
		*p = q;
	}

	struct ENEARIO *RetPila (struct LIFO **p) {
		if (!PilaVacia(*p)) {
			struct ENEARIO *Temp = (*p)->Info;
			struct LIFO *q = *p;
			*p = (*p)->Sig;
			delete q;
			return Temp;
		}
		else {
			printf ("Error...\n");
			return NULL;
		}
	}



struct ENEARIO {
	int Info;
	struct ENEARIO *Hijo;
	struct ENEARIO *Hermano;
};

void main() {
	struct ENEARIO *p;
	int t;
	char Aux[20];
	struct ENEARIO *Construir(struct ENEARIO *,int);
	struct ENEARIO *Construir(int);
	struct ENEARIO *Esta(int);
	void Inorden(struct ENEARIO *);
	void Preorden(struct ENEARIO *);
	void Posorden(struct ENEARIO *);

	int Hojas(struct ENEARIO *p);
	void Niveles (struct ENEARIO *p);
	int Piramide(struct ENEARIO *p);
	struct ENEARIO *Camino(struct ENEARIO *p,int n,
				struct ENEARIO **Lista);
	int Gordura(struct ENEARIO *p);

	p = Construir(28);
	t = Piramide(p);
	if (t == 2)
		printf ("arbol Vacio\n");
	else if (t == -1)
		printf ("arbol no es piramide\n");
	else
		printf ("arbol si es piramide\n");
	printf ("\n");
	printf ("La gordura del árbol es: %d\n",Gordura (p));
	printf ("INORDEN\n");

	Inorden (p);
	printf ("PREORDEN\n");
	Preorden (p);
	printf ("\n");
	printf ("NIVELES\n");
	Niveles (p);
	printf ("\nNumero de Hojas: %d",Hojas(p));
	printf("\n");
	printf ("POSORDEN\n");
	Posorden (p);
	printf("\n");
	printf ("CAMINO \n");
	struct ENEARIO *Lista=NULL,*w;
	Camino(p,2,&Lista);
	w = Lista;
	while (w != NULL) {
		printf ("%d ",w->Info);
		w = w->Hermano;
		delete Lista;
		Lista = w;
	}
}
int Gordura(struct ENEARIO *p) {
	int MasGordo=-1;
	struct FIFO *Cola;
	struct ENEARIO *s;
	struct ENEARIO *q;
	int i=0,Ant=-1,Cont=1;

	InitCola (&Cola);
	InsCola (&Cola,p,1);
	while (!ColaVacia(Cola)) {
		q = RetCola(&Cola,&i);
		if (i != Ant) {
			if (MasGordo < Cont)
				MasGordo = Cont;
			Cont = 0;
			Ant = i;
			printf ("\n");
		}
		Cont++;
		s = q->Hijo;
		while (s != NULL) {
			InsCola(&Cola,s,i+1);
			s = s->Hermano;
		}
	}
	return (MasGordo < Cont) ? Cont : MasGordo;
}
/*
// Posorden() Recursivo
void Posorden(struct ENEARIO *p) {
	struct ENEARIO *q;
	if (p!= NULL) {
		q = p->Hijo;
		while (q != NULL) {
			Posorden(q);
			q = q->Hermano;
		}
		printf ("%d ",p->Info);
	}
}
*/
void Posorden(struct ENEARIO *p) {
	struct LIFO *p1;
	struct ENEARIO *q;
	InitPila(&p1);
	while (p != NULL) {
		InsPila(&p1,p);
		p = p->Hijo;
	}
	while (!PilaVacia(p1)) {
		q = RetPila(&p1);
		printf ("%d ",q->Info);
		q = q->Hermano;
		while (q != NULL) {
			InsPila (&p1,q);
			q = q->Hijo;
		}
	}
}
void Niveles (struct ENEARIO *p) {
	struct FIFO *Cola;
	struct ENEARIO *s;
	struct ENEARIO *q;
	int i=0,Ant=-1;

	InitCola(&Cola);
	InsCola (&Cola,p,1);
	while (!ColaVacia(Cola)) {
		q = RetCola(&Cola,&i);
		if (i != Ant) {
			Ant = i;
			printf ("\n");
		}
		printf ("%d ",q->Info);
		s = q->Hijo;
		while (s != NULL) {
			InsCola(&Cola,s,i+1);
			s = s->Hermano;
		}

	}

}

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

struct ENEARIO *Construir(int x) {
	struct ENEARIO *t = NULL,*N,*q;
	N = new struct ENEARIO;
	N->Info = x;
	N->Hermano = N->Hijo = NULL;
	for (int i=1; i <= x / 2; i++) {
		if (x % i == 0) {
			q  = Construir (i);
			if (N->Hijo == NULL) {
				N->Hijo = q;
			}
			else {
				t->Hermano = q;
			}
			t = q;
		}
	}
	return N;
}
void Inorden(struct ENEARIO *p) {
	struct ENEARIO *q;
	if (p != NULL) {
		q = p->Hijo;
		if (q == NULL)
			printf ("%d\n",p->Info);
		else {
			Inorden(q);
			printf ("%d\n",p->Info);
			q = q->Hermano;
			while (q != NULL) {
				Inorden (q);
				q = q->Hermano;
			}
		}
	}
}
void Preorden (struct ENEARIO *p) {
	struct ENEARIO *q;
	if (p != NULL) {
		printf ("%d ",p->Info);
		q = p->Hijo;
		if (q == NULL)
			; // Ninguna Instruccion
		else {
			Preorden(q);
			q = q->Hermano;
			while (q != NULL) {
				Preorden (q);
				q = q->Hermano;
			}
		}
	}
}

int Hojas(struct ENEARIO *p) {
	struct ENEARIO *q;
	int Acum;
	if (p == NULL)
		return 0;
	else {
		q = p->Hijo;
		if (q == NULL)
			return 1;
		else {
			Acum = 0;
			while (q != 0) {
				Acum = Acum + Hojas(q);
				q = q->Hermano;
			}
			return Acum;
		}
	}
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

struct ENEARIO *Esta(struct ENEARIO *p,int n) {
	struct ENEARIO *q,*s;
	if (p == NULL)
		return p;
	if (p->Info == n)
		return p;
	q = p->Hijo;
	while (q != NULL) {
		s = Esta(q,n);
		if (s != NULL) {
			return s;
		}
		q = q->Hermano;
	}
	return NULL;
}

int Piramide(struct ENEARIO *p) {
	struct ENEARIO *q;
	int s=0,u;
	if (p == NULL)
		return -2;
	q = p->Hijo;
	while (q != NULL) {
		s = s + q->Info;
		u = Piramide(q);
		if (u == -1)
			return -1;
		q = q->Hermano;
	}
	if (p->Info == s || s == 0)
		return 1;
	return -1;
}


// Aqui se graban las clases COLA y PILA
// Para que se utilizen en caso de que
// el estudiante conozca la programacion OOP.

/*
class COLA {
	struct FIFO *p;
public:
	COLA () {
		p = new FIFO;
		p->Sig = p;
	}
	~COLA();
	int ColaVacia() { return p == p->Sig; }
	void InsCola (struct ENEARIO *pp,int n) {
		struct FIFO *q =  new struct FIFO;
		q->Info = pp;
		q->Nivel = n;
		q->Sig = p->Sig;
		p->Sig = q;
		p = q;
	}

	struct ENEARIO *RetCola (int *pp) {
		struct FIFO *q,*r;
		struct ENEARIO *Temp;
		if (!ColaVacia()) {
			q = p->Sig;
			r = q->Sig;
			Temp = r->Info;
			*pp = r->Nivel;
			q->Sig = r->Sig;
			if (r == p)
				p = q;
			delete r;
			return Temp;
		}
		else {
			printf ("Error...\n");
			return 0;
		}
	}
};
COLA::~COLA() {
	delete p;
}
*/

/*
class PILA {
	struct LIFO *p;
public:
	PILA () { p = NULL; 	}
	~PILA();
	int PilaVacia() { return p == NULL; }
	void InsPila (struct ENEARIO *pp) {
		struct LIFO *q =  new struct LIFO;
		q->Info = pp;
		q->Sig = p;
		p = q;
	}

	struct ENEARIO *RetPila () {
		if (!PilaVacia()) {
			struct ENEARIO *Temp = p->Info;
			struct LIFO *q = p;
			p = p->Sig;
			delete q;
			return Temp;
		}
		else {
			printf ("Error...\n");
			return NULL;
		}
	}
};
PILA::~PILA() {
	while (!PilaVacia()) {
		RetPila();
	}
}
*/





