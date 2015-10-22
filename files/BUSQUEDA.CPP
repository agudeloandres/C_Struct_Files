/* secuencial.c - busqueda secuencial en un arreglo
**
** Pablo A. Straub, Jueves 13 de marzo de 1997
*/

#include <stdio.h>
#define LARGO 10
# include <conio.h>
int leer_entero (char texto[]) // prot
{

	 int n;
	 clrscr();
	 printf("%s ", texto);
	 scanf("%d", &n);
	 return n;

	 getch();
}

int secuencial (int numeros[], int num, int max);

void main ()
{
    int nums[LARGO] = {-3, 1, 0, 5, 3, -12, 45, 46, 8, 77};
    int buscado = leer_entero("Ingrese numero a buscar:");
    int posicion = secuencial(nums, buscado, LARGO);
	 if (posicion == LARGO)
	printf("%d no esta en el arreglo\n", buscado);
    else
	printf("%d esta en la posicion %d\n", buscado,
		posicion);
getch();
}

int secuencial (int numeros[], int num, int max)
{
    int j = 0;

    while (j < max && num != numeros[j])
	j++;
    return j;
}
