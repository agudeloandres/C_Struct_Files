#include "iostream.h"
#include "stdio.h"
#include "conio.h"
#include "graphics.h"

int main() {
	int menor,mayor;
	getmoderange (ATT400,&menor,&mayor);
	printf ("Para la unidad ATT400:\n");
	printf ("Modo menor = %d\n",menor);
	printf ("Modo mayor =  %d \n",mayor);
	getch();
	closegraph();
	return 0;
}
