#include "iostream.h"	// cin() cout()
#include "io.h"			// Para archivos
#include "fcntl.h"		// Para archivos
#include "dos.h"		// Para archivos
#include "conio.h" 		// getch()
#include "stdlib.h"		// exit()

class X {
	int i;
	char j;
public:
	X() {}
	void asignar(int m, char n) { i = m; j = n; }
	int G(char *p) {
		*p = j;
		return i;
	}
};

class A {
	X x;
public:
	A() {}
	void asignar(int i,char c) { x.asignar (i,c); }
	int F(char *p) {
		int i = x.G(p);
		return i;
	}
};

main() {
	void lea_datos(A *);
	void error(void);
	A b,c;
	int id;
	char caracter;
	if((id = _creat("Objeto",FA_ARCH)) == -1) error();
	if(_close (id) == -1) error();
	if((id = _open ("Objeto",O_WRONLY)) == -1) error();
	lea_datos(&b);
	while (b.F(&caracter) != 999) {
		_write (id, (char *)&b,sizeof (A) );
		lea_datos(&b);
	}
	_close (id);
	// Procesos Adicionales
	if((id = _open ("Objeto",O_RDONLY)) == -1) error();
	while ( !eof(id) ) {
		_read (id, (char *)&c,sizeof (A) );
		cout << c.F(&caracter) << " ";
		cout << caracter << endl;
	}
	if(_close (id) == -1) error();
}

void lea_datos(A *p) {
	char j;
	int i;
	cout << "De un numero entero...\n";
	cin >> i;
	cout << "De un caracter...\n";
	cin >> j;
	p->asignar(i,j);
}

void error(void) {
	cout << "Error al hacer una operacion sobre un archivo..\n";
	getch();
	exit(1);
}



