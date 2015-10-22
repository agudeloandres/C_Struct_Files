#include "iostream.h"
#include "string.h"

int F(int x) { return 5+x; }

void F(char *y) {
	strcat (y,"+beta");
}

main() {
	int (*s)(int);
	void (*t)(char *);
	s = F;
	t = F;
	char *p = new char [20];
	strcpy (p,"alfa");
	cout << s(3) << endl;
	t(p);
	cout << p << endl;
}

