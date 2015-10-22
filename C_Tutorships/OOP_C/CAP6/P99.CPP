#include "stdio.h"  // Funcion gets()
#include "stdlib.h"	// Funcion atoi()
#include "iostream.h"

int G(void) {
	char a[10];
	cout << "De un numero...\n";
	gets(a);
	return atoi (a);
}

main() {
	int G(void);
	int (*f)();
	// Otras instrucciones...
	f = G;
	cout << f() << endl;
	int j;
	j = f();
	cout << j << endl;
}


