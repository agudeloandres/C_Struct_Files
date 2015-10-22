#include "stdio.h"
#include "string.h"
#define PR(x) printf ("%s\n",x)
#include "conio.h"
void main()  {
	char s [20],*p;
	char   *F(char *,int); // En C++, el prototipo debe incluir
										// todos los parametros
	int i;

	i = 381;
	strcpy (s,"VENTANAS");
	p = F(s, i);
	PR(p);
	getch();

}

char *F (char *s, int i) {
	char *p;

	if (i % 20 > 10)
		p = _strerror (s);
	else p = _strerror ("Error en F()");
	return (p);
}
