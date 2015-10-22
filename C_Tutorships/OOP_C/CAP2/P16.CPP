#include "iostream.h"

main() {
	int *p;
	p = new int (10);		// Con [] seria arreglo!
	if (p == NULL) {
		cout << "Memoria insufueiente...\n";
		return 1;
	}
	cout << *p;
}