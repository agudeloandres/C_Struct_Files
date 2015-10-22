#include "iostream.h"
#include "stdlib.h"
#include "conio.h"
#include "fstream.h"		// Se debe incluir para manejar los archivos
							// de cadenas de caracteres.
void uno() {  // Ejemplo 1
	void error(void);
	ofstream sale;
	sale.open("prueba",ios::out,0);
	if (sale == 0) error();
	sale.close();
}
void dos() {  // Ejemplo 2
	void error(void);
	ofstream sale("prueba");
	if(sale == 0) error();
	sale.close();
}
void tres() {  // Ejemplo 3
	void error(void);
	ofstream sale;
	sale.open("prueba",ios::nocreate,0);
	if (sale == 0) error();
	sale.close();
}
void cuatro() {  // Ejemplo 4
	void error(void);
	ofstream sale;
	sale.open("prueba",ios::app,0);
	if (sale == 0) error();
	sale.close();
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