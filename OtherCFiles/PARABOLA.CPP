

/* parabola.c - alturas para una antena parab�lica
**
** Autor: Pablo A. Straub
** Fecha: Mi�rcoles 28 de agosto de 1996
**        Mi�rcoles 12 de marzo de 1997, no se usa leer.c
*/

#include<stdio.h>
void main ()
{
    /* datos de entrada */
    float diametro;
    float ymax;
    int intervalos;
    
    /* datos de c�mputo inicial */
    float foco, a, radio, delta;
    
    /* variables de la iteraci�n */
    int intervalo;
    float x, y;
    
    /* Se piden los par�metros */
    
    printf("C�mputo de una Antena Parab�lica\n\n");

    printf("Ingrese el di�metro de la antena en [mm]: ");
    scanf("%f", &diametro);
    printf("Ingrese la altura de la par�bola para el"
           " radio m�ximo [mm]: ");
    scanf("%f", &ymax);
    printf("Ingrese el n�mero de intervalos: ");
    scanf("%d", &intervalos);

    /* C�mputo inicial */

    radio = diametro / 2.0;
    a = ymax / (radio * radio);
    foco = 1 / (4 * a);
    delta = radio / intervalos;
    
    /* Resultados iniciales */
        
    printf("\nEl radio es %6.1f [mm]\n", radio);
    printf("El par�metro a es %12.9f [1/mm]\n", a);
    printf("El foco est� a %6.1f [mm]\n", foco);
    
    /* Tabla de altura de parabola en funci�n del radio */
    
    printf("\nAltura en Funci�n del Radio\n\n");
    printf("  Intervalo   Radio (mm)  Altura (mm)\n");
    printf("--------------------------------------\n");

    for (intervalo = 0; intervalo <= intervalos; intervalo++) {
	x = delta * intervalo;
	y = a * x * x;
	printf("%7d %13.1f %12.1f\n", intervalo, x, y);
    }
}
