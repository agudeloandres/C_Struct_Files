#include "iostream.h"
#include "io.h"
#include "fcntl.h"
#include "dos.h"

class A {
	int x;
public:
	A(int i) : x(i) {}
	int F() { return x; }
};

main() {
	A b(3),c(100);
	int id;
	id = _creat("Objeto",FA_ARCH);
	_write (id, (char *)&b,sizeof (A) );
	// Procesos Adicionales
	_close (id);
	id = _open ("Objeto",O_RDONLY);
	_read (id, (char *)&c,sizeof (A) );
	cout << c.F() << endl;
}


