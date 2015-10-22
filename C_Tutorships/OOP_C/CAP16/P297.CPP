#include "iostream.h"

istream &datos (istream &s) {
	cout << "De numeros a elevar...\n";
	cout << "De valor de la base...\n";
	cout << "De valor del exponente...\n";
	return s;
}

main() {
	long base,exponente;
	cin >> datos >> base >> exponente;
	long a = base, b = exponente, z = 1;
	while (b != 0) {
		if (b % 2 != 0 ) {
			z = z * a;
			b--;
		}
		else {
			a = a * a;
			b = b / 2;
		}
	}
	cout << base << " ^ " << exponente <<  " = " << z << endl;
}
