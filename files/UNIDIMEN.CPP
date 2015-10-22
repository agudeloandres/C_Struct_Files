#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ALUM_MAX 100 /* numeros maximos de alumnos */

   main()
{
   float notas[ALUM_MAX], suma = 0;
   int i, nalumnos;

   system ("cls");
   clrscr;
   printf("numero de alumnos:");
   scanf("%d",&nalumnos);

   /* Entrada de datos */

   for (i = 1; i <= nalumnos; i++)
     {
	  printf("Alumno numero %3d, nota final: ",i);
	  scanf("%f",&notas[i-1]);
	  suma += notas[i-1];

     }

     /*  Escribiendo resultados */

     printf("\n\nNota nedia del curso: %5.2f\n",suma/nalumnos);
     getch();
}





