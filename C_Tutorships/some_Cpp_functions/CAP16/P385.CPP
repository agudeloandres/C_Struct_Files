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

	ifstream entra;
	entra.open ("prueba",ios::in, 0);
	int d = entra.peek();
	cout << "d=" << d << endl;
	while (!entra.eof() ) {
		entra.get(c);
		cout << "c=" << c << endl;
		d = entra.peek();
		cout << "d=" << d << endl;
	}
	entra.close();
}


