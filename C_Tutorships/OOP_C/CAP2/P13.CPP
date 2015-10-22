#include "iostream.h"

main() {
	float *p;
	cout << "De el tamano del arreglo...\n";
	int i;
	cin >> i;
	p = new float [i];
	if (p == NULL) {
		cout << "Memoria insuficiente" << endl;
		return 1;
	}
	for (int j = 0;j < i; j++) {
		cout << "De valor...\n";
		cin >> p[j];
	}
	// Algun proceso usando el arreglo p[]
	for (j = 0;j < i; j++)
		cout << p[j] << endl;
}