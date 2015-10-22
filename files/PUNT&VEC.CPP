// CUATRO MANERAS DIFERENTES DE IMPRIMIR UN VECTOR CON APUNTADORES
#include <stdio.h>
#include <conio.h>
main(){
clrscr();
int vector []={1,2,3,4,5,6,7,8,9,10},k;
int *vptr;
vptr=vector;  //no lleva & por ser un arreglo, Es equivalente a:
	     //vptr=&vector[0];

for(k=0;k<=9;k++)
printf("%5d",*(vptr+k)); // 1) Usando apuntadores con la variable de control

printf("\n\n");

for(k=0;k<=9;k++)
printf("%5d",vptr[k]); // 2) Utilizando el apuntador como  un vector

printf("\n\n");

for(k=0;k<=9;k++)
printf("%5d",*(vector+k)); // 3) Usando el arreglo como un apuntador

printf("\n\n");

for(k=0;k<=9;k++)
printf("%5d",vector[k]); // 4) Utilizando el vector de la manera convencional

getch();
//***************************************************************************
//***************CUATRO FORMAS DE IMPRIMIR DIRECIONES EN MEMORIA*************

printf("\n\n\n\n");

for(k=0;k<=9;k++)
printf("%lu\n",(vptr+k)); // 5) Imprime la direcciones en memoria del vector
getch();		 //     usando el apuntador

printf("\n\n");

for(k=0;k<=9;k++)
printf("%lu\n",(vector+k)); // 6) Imprime las direcciones en memoria del vector
getch();		   //    usando el vector como apuntador

printf("\n\n");

for(k=0;k<=9;k++)
printf("%lu\n",&vector[k]); // 7) Tomando la direccion del vector
getch();

printf("\n\n");

for(k=0;k<=9;k++)
printf("%lu\n",&vptr[k]); // 8) Tomando la direccion del apuntador que aqui
			 //    actua como vector


getch();
}