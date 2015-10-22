#include "iostream.h"

typedef struct NODO NODO;

struct NODO {
	int info;
	NODO *sig;
};

class LISTA {
	NODO *cab;
public:
	LISTA() { cab = NULL; }
	int ins_lista (int n);
	int retira_lista (int n);
	void listar_lista();
	void insertar(NODO *,NODO *,int);
	~LISTA();
};

void LISTA::insertar(NODO *p,NODO *q,int n) {
	NODO *nuevo;
	nuevo = new NODO;
	nuevo->info = n;
	nuevo->sig = q;
	if (p != NULL)
		p->sig = nuevo;
	else cab = nuevo;
}

int LISTA::ins_lista (int n) {
	NODO *p,*q;
	p = NULL;
	q = cab;
	int encontro = 0;
	while (q!= NULL && !encontro)
		if (n > q->info) {
			p = q;
			q = q->sig;
		}
		else encontro = 1;
	if (encontro)
		if (n == q->info)
			return (-1); // Repetido
		else insertar (p,q,n);
	else insertar (p,q,n);
	return 0;
}

void LISTA::listar_lista() {
	NODO *p = cab;
	while (p != NULL) {
		cout << p->info << endl;
		p = p->sig;
	}
}

int LISTA::retira_lista (int n) {
	NODO *p,*q;
	p = NULL;
	q = cab;
	int encontro = 0;
	while (q != NULL && !encontro)
		if (n > q->info) {
			p = q;
			q = q->sig;
		}
		else encontro = 1;
	if (encontro == 1 && n == q->info) {
		if (p == NULL)
			cab = q->sig;
		else p->sig = q->sig;
		delete q;
		return 0;
	}
	return -1;
}

LISTA::~LISTA() {
	NODO *p;
	if (cab == NULL)
		;
	else {
		p = cab;
		while (cab != NULL) {
			cab = cab->sig;
			delete p;
			cout << "Destruido nodo..." << endl;
			p = cab;
		}
	}
}

main() {
	LISTA lista1;
	int i;
	cout << "De numero(Para fin de 999)..." << endl;
	cin >> i;
	while (i != 999) {
		if (lista1.ins_lista(i) == -1)
			cout << "repetido" << endl;
		cout << "De numero(Para fin de 999)..." << endl;
		cin >> i;
	}
	lista1.listar_lista();
	cout << "De numero a retirar (Para fin de 999)..." << endl;
	cin >> i;
	while (i != 999) {
		if (lista1.retira_lista(i) == -1)
			cout << "No existe" << endl;
		cout << "De numero a retirar (Para fin de 999)..." << endl;
		cin >> i;
	}
	lista1.listar_lista();
}

