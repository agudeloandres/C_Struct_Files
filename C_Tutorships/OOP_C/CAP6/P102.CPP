#include "iostream.h"
#include "string.h"

char *G(char *s,char *t) {
	char *b;
	b = new char [strlen(s) + strlen (t) + 1];
	strcpy (b,s);
	strcat (b,t);
	return b;
}

main() {
	char *(*f)(char *,char *);
	char *G(char *, char *);
	f = G;
	char *p;
	p = f("alfa","beta");
	cout << p << endl;
	delete p;
}


