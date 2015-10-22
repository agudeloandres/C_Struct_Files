

/* parabola.c - alturas para una antena parabólica
**
** Autor: Pablo A. Straub
** Fecha: Miércoles 28 de agosto de 1996
**        Miércoles 12 de marzo de 1997, no se usa leer.c
*/

#include<stdio.h>
void main ()
{
    /* datos de entrada */
    float diametro;
    float ymax;
    int intervalos;
    
    /* datos de cómputo inicial */
    float foco, a, radio, delta;
    
    /* variables de la iteración */
    int intervalo;
    float x, y;
    
    /* Se piden los parámetros */
    
    printf("Cómputo de una Antena Parabólica\n\n");

    printf("Ingrese el diámetro de la antena en [mm]: ");
    scanf("%f", &diametro);
    printf("Ingrese la altura de la parábola para el"
           " radio máximo [mm]: ");
    scanf("%f", &ymax);
    printf("Ingrese el número de intervalos: ");
    scanf("%d", &intervalos);

    /* Cómputo inicial */

    radio = diametro / 2.0;
    a = ymax / (radio * radio);
    foco = 1 / (4 * a);
    delta = radio / intervalos;
    
    /* Resultados iniciales */
        
    printf("\nEl radio es %6.1f [mm]\n", radio);
    printf("El parámetro a es %12.9f [1/mm]\n", a);
    printf("El foco está a %6.1f [mm]\n", foco);
    
    /* Tabla de altura de parabola en función del radio */
    
    printf("\nAltura en Función del Radio\n\n");
    printf("  Intervalo   Radio (mm)  Altura (mm)\n");
    printf("--------------------------------------\n");

    for (intervalo = 0; intervalo <= intervalos; intervalo++) {
	x = delta * intervalo;
	y = a * x * x;
	printf("%7d %13.1f %12.1f\n", intervalo, x, y);
    }
}
