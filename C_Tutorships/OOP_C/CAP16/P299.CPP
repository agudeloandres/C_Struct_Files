#include "iostream.h"

istream &orden (istream &s) {
	cout << "De orden de la matriz...\n";
	cout << "Favor, informe las filas y columnas separadas\n";
	cout << "Por un espacio.\n";
	return s;
}

istream &mat (istream &s) {
	cout << "Favor, informe la matriz por filas...\n";
	return s;
}

ostream &matriz (ostream &s) {
	cout << endl;
	cout << "Datos de la matriz \n";
	return s;
}

ostream &error(ostream &s) {
	cout << endl;
	cout << "El numero de columnas de la primera\n";
	cout << "Debe ser igual al numero de filas de la segunda\n";
	return s;
}

int **R(int f, int c) {
	int **p;
	p = new int* [f];
	for (int i = 0; i < f; i++)
		p[i] = new int [c];
	int j;
	for (i=0; i < f; i++)
		for(j = 0; j < c; j++)
			p [i][j] = 0;
	return p;
}

int **F(int f, int c) {
	int **p;
	p = new int* [f];
	for (int i = 0; i < f; i++)
		p[i] = new int [c];
	int j;
	for (i=0; i < f; i++)
		for(j = 0; j < c; j++)
			cin >> p [i][j];
	return p;
}

void destruir (int **p, int f) {
	for (int i=0; i < f; i++)
		delete p[i];
	delete p;
}

void escribir(int **r,int f, int c) {
	int i,j;
	for (i=0; i < f; i++) {
		for(j = 0; j < c; j++)
			cout << r [i][j] << " ";
		cout << endl;
	}
}

main() {
	int f,c,f1,c1,i,j,k;
	cin >> orden >> f >> c >> mat;
	int **m = F(f,c);
	cin >> orden >> f1 >> c1 >> mat;
    if (c != f1) {
		cout << error;
		return 1;
	}
	int **m1 = F(f1,c1);
	int **r = R(f,c1);
	for (i=0; i < f; i++)
		for(k = 0; k < c; k++)
			for (j = 0; j < c1; j++)
				r[i][j] = r[i][j] + m[i][k] * m1 [k][j];
	cout << matriz << "Multiplicando\n";
	escribir(m,f,c);
	cout << matriz << "Multiplicador\n";
	escribir(m1,f1,c1);
	cout << matriz << "Resultado\n";
	escribir(r,f,c1);
	destruir(m,f);
	destruir(m1,f1);
	destruir(r,f);
}