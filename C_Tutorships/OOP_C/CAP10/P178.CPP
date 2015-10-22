#include "iostream.h"
#include "conio.h"
#include "stdlib.h"

class A {
	int *p;
public:
	A() { p = new int [10]; }
	int &operator[](int j) {
		if (j < 0 || j > 9) {
			cout << "Indice fuera de rango...\n";
			getch();
			exit(1);
		}
		return p[j];
	}
	int *F(int i) { return p+i; }
};

main() {
	A a;
	a[10] = 3;
	cout << *a.F(1) << endl;
}


