#include "iostream.h"
#include "conio.h"



// Este programa debe ser corrido, una vez haya sido corregido
// de lo contrario bloquea su computador.
// El programa tiene errores de concepto. Favor corregirlos



class X {
	int x;
	int *p;
public:
	X(int ai, int pi) {
		x = ai;
		p = new int (pi);
	}
	int devolver(int &b) {
		b = x;
		return *p;
	}
	void cambiar (X &objeto) {
		objeto.x = objeto.x + this->x;
		objeto.p = this->p;
	}
	~X() {
		cout << "Destruyendo... " << endl;
		delete p;
	}
};

main() {
	X a(1,2),b(3,4);
	int i,j;
	i = a.devolver(j);
	cout << i << " " << j << endl;
	i = b.devolver(j);
	cout << i << " " << j << endl;
	a.cambiar (b);
	i = a.devolver(j);
	cout << i << " " << j << endl;
	i = b.devolver(j);
	cout << i << " " << j << endl;
}

