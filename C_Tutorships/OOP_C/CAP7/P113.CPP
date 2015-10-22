#include "iostream.h"	// cin() cout()
#include "io.h"			// Para archivos
#include "fcntl.h"		// Para archivos
#include "dos.h"		// Para archivos
#include "conio.h" 		// getch()
#include "stdlib.h"		// exit()

class A {
	int x;
public:
	A() {}
	void asignar(int i) { x = i; }
	int F() { return x; }
};

main() {
	void lea_datos(A *);
	void error(void);
	A b,c;
	int id,pos,numero;
	if((id = _open ("Objeto",O_RDWR)) == -1) error();
	numero = filelength(id) / sizeof (A);
	cout << "De el numero del registro a actualizar\n";
	cin >> pos;
	while (pos >= 0 && pos < numero) {
		lea_datos(&b);
		if ((lseek (id,(long)pos * sizeof (A), SEEK_SET) ) == -1) error();
		_write(id, (char *)&b,sizeof (A) );
		cout << "De el numero del registro a actualizar\n";
		cin >> pos;
	}
	_close (id);
	// Procesos Adicionales
	if((id = _open ("Objeto",O_RDONLY)) == -1) error();
	while ( !eof(id) ) {
		_read (id, (char *)&c,sizeof (A) );
		cout << c.F() << endl;
	}
	if(_close (id) == -1) error();
}

void lea_datos(A *p) {
	int i;
	cout << "De un numero entero...\n";
	cin >> i;
	p->asignar(i);
}

void error(void) {
	cout << "Error al hacer una operacion sobre un archivo..\n";
	getch();
	exit(1);
}



