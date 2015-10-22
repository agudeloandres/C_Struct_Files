#include "iostream.h"
#include "graphics.h"
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

int main() {
	int unidad = -1,modo,error;

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	error = graphresult();
	if (error < 0) {
		printf ("Error -> ");
		getch();
		printf (" %d %s\n",error, grapherrormsg (error) );
		getch();
		exit (1);
	}
	return 0;
}
