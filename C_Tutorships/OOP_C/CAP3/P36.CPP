#include "iostream.h"
#include "string.h"
#include "conio.h"

class A {
public:
	A() {
		p = new int* [5];
		p[0] = new int [4];
		p[1] = new int [4];
		p[2] = new int [4];
		p[3] = new int [4];
		p[4] = new int [4];
		// Se podria con un for ?
	}
	~A() {
		cout << "Destruyendo...\n";
		delete p[0];
		delete p[1];
		delete p[2];
		delete p[3];
		delete p[4];
		// Se podria con un for ?
		delete p;
	}
	void F(int i,int j,int k) { p[i][j] = k; }
	int **G() { return F(); }
private:
	int **p;
	int **F() { return p; }
};

main() {
	A b,c,d;
	for (int i=0,j; i < 5; i++)
		for (j = 0; j < 4; j++) {
			b.F(i,j,1);
			c.F(i,j,2);
			d.F(i,j,3);
		}
	// Algun proceso con los objetos
	int **q = b.G();
	for (i=0; i < 5; i++) {
		for (j=0; j < 4; j++)
			cout << q[i][j] <<  " ";
		cout << endl;
	}
	cout << endl;
	q = c.G();
	for (i=0; i < 5; i++) {
		for (j=0; j < 4; j++)
			cout << q[i][j] <<  " ";
		cout << endl;
	}
	cout << endl;
	q = d.G();
	for (i=0; i < 5; i++) {
		for (j=0; j < 4; j++)
			cout << q[i][j] <<  " ";
		cout << endl;
	}
}
