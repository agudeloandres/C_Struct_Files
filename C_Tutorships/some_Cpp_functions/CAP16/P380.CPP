#include "iostream.h"
#include "fstream.h"
#include "conio.h"

void main() {
	ofstream sale;
	sale.open ("prueba",ios::out  | ios::trunc, 0);
	char c;
	while ( (c=getche() ) != 13)  // tecla Enter
		sale.put(c);
	sale.close();
	cout << endl;
}

