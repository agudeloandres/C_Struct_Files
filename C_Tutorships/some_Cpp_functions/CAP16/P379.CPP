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
	io.seekg ((long)-17,ios::end);
    streampos i = io.tellg();
	cout << i << endl;

	io.seekp ((long)3,ios::beg);
	io.seekp (-1,ios::cur);
	i = io.tellp();
	cout << i << endl;
	io.close();
}
