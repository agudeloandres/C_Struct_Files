#include "iostream.h"
#include "stdlib.h"
#include "string.h"
#include "fstream.h"		// Se debe incluir para manejar los archivos
							// de cadenas de caracteres.
void sumaNULL(char *p) {
	int i=strlen (p);
	p[i] = '\n';
    p[i+1] = '\0';
}
void main() {
	void sumaNULL(char *);
	ofstream sale;
	char a[50];
	sale.open("prueba",ios::out | ios::trunc,0);
	if(sale == 0) {
		cout << "Error en apertura\n";
		cout << "Oprima una tecla...\n";
		cin >> a;
		return 1;
	}
	cout << "De una cadena. Maximo 50 posiciones. fin=para terminar\n";
	cin >> a;
	sumaNULL(a);
	while (strcmp(a,"fin\n") != 0) {
		sale << a;
		cout << "De una cadena. Maximo 50 posiciones. fin=para terminar\n";
		cin >> a;
		sumaNULL(a);
	}
	sale.close();
}
