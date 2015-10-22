#include "iostream.h"
#include "stdlib.h"
#include "string.h"
#include "fstream.h"		// Se debe incluir para manejar los archivos
							// de cadenas de caracteres.
void main() {
	fstream io;
	char a;
	io.open("prueba",ios::in | ios::out,0);
	if(io == 0) {
		cout << "Error en apertura\n";
		cout << "Oprima una tecla...\n";
		cin >> a;
		return 1;
	}
	long pos;
	cout << "De posicion del caracter que desea cambiar?. -1=fin\n";
	cin >> pos;
	while (pos != -1) {
		io.seekp (pos,ios::beg);
		cout << "De nuevo caracter a grabar: \n";
		cin >> a;
		io.put(a);
		cout << "De posicion del caracter que desea cambiar?. -1=fin\n";
		cin >> pos;
	}
	io.close();
}
