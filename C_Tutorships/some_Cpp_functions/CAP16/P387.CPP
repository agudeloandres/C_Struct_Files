#include "iostream.h"
#include "fstream.h"
#include "ctype.h"
#include "stdlib.h"
#include "conio.h"

void main() {
	ofstream sale;
	sale.open ("prueba",ios::out  | ios::trunc, 0);
	char c;
	while ( (c=getche() ) != 13)  // tecla Enter
		sale.put(c);
	sale.close();
	cout << endl;
	char a[10], *p;
	p = a;
	ifstream entra;
	entra.open ("prueba",ios::in, 0);
	entra.get(c);
	while (!entra.eof() ) {
		cout << c;
		entra.get(c);
	}
	entra.close();
	entra.open ("prueba",ios::in, 0);
	cout << endl;
	int j;
	int d = entra.peek();
	while (!entra.eof() ) {
		if (isalpha (d)) {
			if (p != a) {
				*p = '\0';
				j = atoi(a);
				cout << j << endl;
				p = a;
			}
			entra.get(c);
		}
		else {
			entra.get(c);
			if (d != -1) {
				*p = d;
				p++;
			}
		}
		d = entra.peek();
		if (entra.eof() ) {
			if (p != a) {
				*p = '\0';
				j = atoi (a);
				cout << j << endl;
			}
		}
	}
	entra.close();
}

