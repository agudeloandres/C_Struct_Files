#include "conio.h"
#include "iostream.h"

#define MAXIMO 10

class PILA {
	int *p;
	int t;
public:
	PILA(int i) {
		p = new int [i];
		t = 0;
	}

	int ins_pila (int objeto) {
		if ( t == MAXIMO)
			return -1;
		p[t++] = objeto;
		return 0;
	}

	int retira_pila(int *q) {
		if ( t == 0)
			return -1;
		*q = p[--t];
		return 0;
	}

	int tope_pila() {
		if ( t == 0)
			return -1;
		return p[t-1];
	}

	int pila_vacia() { return t == 0; }

	~PILA() { delete p; }
};

main() {
	PILA p(10);
	int i;
	cout << "De objeto a insertar(final=999) " << endl;
	cin >> i;
	while (i != 999) {
		if (p.ins_pila(i) == -1)
			cout << "Pila llena..." << endl;
		cout << "De objeto a insertar(final=999) " << endl;
		cin >> i;
	}
	cout << "Retira pila (s/n)?" << endl;
	while ( getch() == 's') {
		if (p.retira_pila(&i) != -1)
			cout << "Objeto retirado = " << i << endl;
		else cout << "Pila vacia..." << endl;
	}
	while (p.pila_vacia() == 0) {
		p.retira_pila(&i);
		cout << i << endl;
	}
}

