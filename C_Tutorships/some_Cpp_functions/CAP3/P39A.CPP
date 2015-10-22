#include "stdio.h"
#include "string.h"
#define PR(x) printf ("%s\n",x)
#include "conio.h"
#include "alloc.h"  // Prototipo de free()
void main()  {
	char a[20],b[20],*p;

	gets (a);
	p = strdup (a); /*  	Es lo mismo que p = malloc (20)   */
	PR(p);
	PR(a);
	free (p);  // O B L I G A T O R I O. Se debe liberar la memoria
	getch();

}



