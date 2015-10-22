#include "iostream.h"
#include "string.h"
#include "conio.h"
#include "stdlib.h"

int F(int i,int j) { return i-j; }

int G(char *p, char *q) { return strcmp(p,q); }

main() {
	int i,j,k;
	char p[30],q[30],c;
	int (*f)(int,int);
	int (*g)(char *,char*);
	cout << "Que desea comparar? " << endl;
	cout << "n=numeros  c=cadenas " << endl;
	c = getche();
	cout << '\n';
	switch(c) {
		case 'n': case 'N' :
			cout << "De dos numeros separados por espacios\n";
			cin >> i >> j;
			f = F;
			k = f(i,j);
			break;
		case 'c': case 'C' :
			cout << "De la primera cadena\n";
			cin >> p;
			cout << "De la segunda cadena\n";
			cin >> q;
			g = G;
			k = g(p,q);
			break;
		default: cout << "error"; getch(); exit(1);
	}
	if (k < 0)
		cout << "Primer operando < segundo operando...\n";
	else if (k > 0)
		cout << "Primer operando > segundo operando...\n";
	else
		cout << "Primer operando = segundo operando...\n";
}


