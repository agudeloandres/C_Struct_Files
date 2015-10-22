#include<stdio.h>
#include<conio.h>          //FUNCION REALLOC Y FREE
#include <stdlib.h>
#include<string.h>
const int BYTES = 40;

void main (){
 char *p;
 clrscr();
 //Asignar espacio para una cadena de caracteres
 p=(char*)malloc(BYTES * sizeof(char));
 //Asignar cadena de caracteres
 strcpy(p,"abcdef\0");

 //Reasignar el bloque para contener mas caracteres
 if (p!=NULL)
  p=(char *)realloc(p,BYTES * 2 * sizeof(char));
  if (p!=NULL){
   printf("Bloque reasignado\n");
   //Escribir la cadena original
   printf("%s\n",p);
   //Liberar el espacio de memoria
   free(p);
   printf("\nEl bloque ha sido liberado\n");
  }
  else {
   printf("La reasignacion no ha sido posible\n");
   printf("El espacio ocupado por el bloque ha sido liberado");
  }
getch();
}



