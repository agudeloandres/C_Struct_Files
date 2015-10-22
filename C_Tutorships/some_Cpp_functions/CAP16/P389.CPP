#include "iostream.h"
#include "fstream.h"
#include "ctype.h"
#include "stdlib.h"
#include "conio.h"
#include "iomanip.h"

ostream &o_nombre (ostream &s) {
	s.flags (0x0001);
	s << setw(30);
	s.setf(ios::left);
	return s;
}

ostream &o_sueldo(ostream &s) {
	s.flags(0x0001);
	s << setw(15) << setiosflags (0x0104);
	return s;
}


void main() {
	ofstream sale;
	sale.open ("prueba",ios::out  | ios::trunc, 0);
	char c;
	while ( (c=getche() ) != 13)  // tecla Enter
		sale.put(c);
	sale.close();
	cout << endl;
	ifstream entra;
	entra.open ("prueba", ios::in, 0);
	char nombre[30],sueldo [10],*p;
	float suma = 0,sueldo_n;
	p = nombre;
	while (!entra.eof() ) {
		entra.get(c);
		while (isalpha (c) || isspace (c) ) {
				*p = c;
				p++;
				entra.get(c);
		}
		*p = '\0';
		p = sueldo;
		entra.putback (c);
		entra.get(c);
		while (isdigit (c) || c == '.' ) {
				*p = c;
				p++;
				entra.get(c);
		}
		*p = '\0';
		sueldo_n = atof(sueldo);
		suma = suma + sueldo_n;
		entra.putback(c);
		cout << o_nombre << nombre << o_sueldo << sueldo_n << endl;
		p = nombre;
	}
	cout << endl;
	cout << o_nombre << "Total sueldos" << o_sueldo << suma << endl;
}

