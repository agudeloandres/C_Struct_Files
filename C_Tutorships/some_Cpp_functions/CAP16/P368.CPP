#include "iostream.h"
#include "stdlib.h"
#include "conio.h"
#include "fstream.h"		// Se debe incluir para manejar los archivos
							// de cadenas de caracteres.
void uno() {  // Ejemplo 1
	void error(void);
	ifstream a;
	a.open("prueba",ios::in,0);
	if (a == 0) error();
	a.close();
}
void dos() {  // Ejemplo 2
	void error(void);
	ifstream a("prueba");
	if(a == 0) error();
	a.close();
}
void tres() {  // Ejemplo 3
	void error(void);
	ifstream a;
	a.open("prueba",ios::noreplace,0);
	if (a == 0) error();
	a.close();
}
void cuatro() {  // Ejemplo 4
	void error(void);
	ifstream a;
	a.open("prueba",ios::trunc,0);
	if (a == 0) error();
	a.close();
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
	void cuatro();
}
