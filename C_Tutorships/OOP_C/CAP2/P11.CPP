#include "iostream.h"
#include "stdlib.h"  // exit()
#include "conio.h"   // getch()

main() {
	int *p;
	p = new int;
	if (p == NULL) {
		cout << "Memoria insuficiente...\n";
		getch();
		exit(1);
	}
	*p = 10;
	cout << *p << endl;
	delete p;
}