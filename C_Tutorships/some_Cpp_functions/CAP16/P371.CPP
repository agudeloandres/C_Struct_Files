#include "iostream.h"
#include "stdlib.h"
#include "conio.h"
#include "fstream.h"		// Se debe incluir para manejar los archivos
							// de cadenas de caracteres.
void uno() {  // Ejemplo 1
	void error(void);
	fstream io;
	io.open("prueba",ios::ate,0);
	if (io == 0) error();
	io.close();
}
void dos() {  // Ejemplo 2
	void error(void);
	fstream io;
	io.open("prueba",ios::in | ios::out | ios::nocreate,0);
	if(io == 0) error();
	io.close();
}
void tres() {  // Ejemplo 3
	void error(void);
	fstream io;
	io.open("prueba",ios::in | ios::out,0);
	if (io == 0) error();
	io.close();
}
void error() {
	cout << "Error en apertura. \n";
	getch();
	exit(1);
}
void main() {
	void uno();
	void dos();
	void tres();
}