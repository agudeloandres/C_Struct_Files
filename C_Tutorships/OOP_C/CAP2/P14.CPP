#include "iostream.h"

main() {
	cout << "De filas y columnas de la matriz\n";
	int f,c;
	cin >> f >> c;
	float **m;
	m = new float* [f];
	if (m == NULL) {
		cout << "Memoria insuficiente...\n";
		return 1;
	}
	for (int j = 0; j < f; j++) {
		m[j] = new float [c];
		if (m[j] == NULL) {
			cout << "Memoria insuficiente...\n";
			return 1;
		}
	}
	for (int i = 0; i < f; i ++)
		for (j = 0; j < c; j++)
			m[i][j] = 0;
	// Otros procesos con el arreglo...
	for (i = 0; i < f; i ++) {
		for (j = 0; j < c; j++)
			cout << m[i][j] <<  ' ';
		cout << endl;
	}
	for (i = 0; i < c; i++)
		delete m[i];
	delete m;
}

