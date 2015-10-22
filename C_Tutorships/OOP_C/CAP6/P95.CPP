#include "iostream.h"
#include "stdlib.h"
#include "conio.h"

class A {
	int **p;
public:
	A();
	int &pos(int, int);
	int lea(int, int);
	~A() { delete p; }
};

A::A() {
	p = new int* [4];
	for (int i = 0; i < 4; i++)
		p[i] = new int [4];
};

int &A::pos(int i, int j) {
	if (  (i < 0 || i > 3) || (j < 0 || j > 3)  ) {
		cout << "Indice fuera de rango...\n";
		getch();
		exit(1);
	}
	return p[i][j];
}

int A::lea(int i, int j) {
	if (  (i < 0 || i > 3) || (j < 0 || j > 3)  ) {
		cout << "Indice fuera de rango...\n";
		getch();
		exit(1);
	}
	return p[i][j];
}

main() {
	A b;
	int j;
	for (int i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			b.pos(i,j) = (i == j) ? 1 : 0;
	// Algun proceso con la matriz...
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++)
			cout << b.lea(i,j) << " ";
		cout << "\n";
	}
}
