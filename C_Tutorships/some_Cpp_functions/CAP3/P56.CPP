#include "stdio.h"
#include "conio.h"
#include "string.h"
#define PR(x) printf ("%s\n",x)

char a[] = "p = p->x + 87.35 * 2.0 / 1.3 * 4.0";

void main()  {
	char *p;

	p = strtok (a,"=+*/");
	while (p != NULL) {
		if (*p == ' ')
			p++;
		PR(p);
		p = strtok (NULL,"=+*/");
	}
	getch();
}



