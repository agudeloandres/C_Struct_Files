#include<stdio.h>
#include<conio.h>            //Array de dos dimensiones

#define F 4   //Numero de filas
#define C 5   //Numero de columnas

void main(){
 static int tabla [F][C] = { {10,12,15,17,14},
			     {22,20,23,25,21},
			     {38,30,34,36,35},
			     {45,41,44,48,49} };
const int k=10;
int f,c;
clrscr();
//Multiplicar cada elemento por una constante k

for (f=0;f<F;f++)
 for (c=0;c<C;c++)
   tabla[f][c]*=k;

//Escribir el Array

for (f=0;f<F;f++){         //ESCRITURA DEL ARREGLO VERSION ARRAY
 for(c=0;c<C;c++)
  printf("%5d",tabla[f][c]);
 putchar('\n');
 }

putchar('\n\n');

for (f=0;f<F;f++){         //ESCRITURA DEL ARREGLO VERSION PUNTEROS
 for(c=0;c<C;c++)
  printf("%5d",*(*(tabla+f)+c));
 putchar('\n');
 }

getch();
}

