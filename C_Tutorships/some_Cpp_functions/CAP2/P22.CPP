#include "stdio.h"
#include "ctype.h"
#include "conio.h"
void main()  {
	int c;

	c = getch();
	if (isspace (c) )
		switch (c) {
		case 9 : printf ("Oprimio la tecla tabulacion horizontal\n");
			 break;
		case 10: printf ("Oprimio la tecla enter\n");
			 break;
		case 11: printf ("Oprimio la tecla nueva linea\n");
			 break;
		case 12: printf ("Oprimio la tecla tabulacion vertical\n");
			 break;
		case 13: printf ("Oprimio la tecla RETURN\n");
			 break;
		case 32: printf ("Oprimio la tecla space bar\n");
			 break;
		}
	else printf ("Esta funcion no identifica esta tecla\n");
	getch();
}



