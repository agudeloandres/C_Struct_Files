#include "stdio.h"
#include "ctype.h"
#include "conio.h"
void main()  {
	int c;

	c = getch();
	if (iscntrl (c))
		printf ("Oprimio una tecla de control(Funcion)\n");
	else {
		printf ("Oprimio una tecla (Minuscula o Mayuscula):\n");
		printf ("Alfabetica o numerica o de puntuacion \n");
		printf ("o un caracter especial\n");
	}
	getch();
}



