#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
void main() {
	double i;

	printf ("Por favor con los siguientes valores dibujar la grafica\n");
	printf ("de la funcion: y = f(x) = tanh (x)\n");
	for (i = -4.0; i <= +4.0; i = i + 0.25) {
		printf ("Coordenada X: %lf Coordenada Y: %lf\n",
				i,tanh(i)  );
		getch();
	}
	getch();

}



