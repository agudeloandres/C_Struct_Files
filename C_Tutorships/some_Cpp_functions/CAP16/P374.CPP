#include "iostream.h"
#include "stdlib.h"
#include "string.h"
#include "stdlib.h"
#include "fstream.h"            // Se debe incluir para manejar los archivos
							// de cadenas de caracteres.
void main() {
	ifstream entra;

	char a[15];             // Debe calcularse bien su tamano.

	entra.open("prueba",ios::in,0);
	if(entra == 0) {
		cout << "Error en apertura\n";
		cout << "Oprima una tecla...\n";
		cin >> a;
		exit(1);
	}
	entra >> a;
	while (!entra.eof() ) {
		cout << a << endl;
		entra >> a;
	}
	entra.close();
}
