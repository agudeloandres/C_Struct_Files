#include<stdio.h>
#include<conio.h>          //FUNCION CALLOC
#include <stdlib.h>
const int N=100;  //Numero Maximo de elementos para el Array
int *lista;
void main(){
 int i=0;
  clrscr();
  //Asignar espacio para N enteros
  lista=(int *)calloc(N,sizeof(int));
  if (lista ==NULL)
   printf("Insuficiente espacio de memoria\n");
  else
   printf("Espacio de memoria asignado para N enteros\n");
   lista[9]=100;
   while (i++ < N)
    printf("%8d",*lista++);
  getch();
  }
