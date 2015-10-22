#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>
#define NML 100      //Numero maximo de lineas

void main(){
 char *plinea[NML];   //Array de punteros a las cadenas
 char *p,linea[81];
 int i,longitud,nlineas=0;

 clrscr();
 printf("Introducir cadenas de caracteres. \n");
 printf("Finalizar con enter.\n\n");

 while ((longitud = strlen(gets(linea))) > 0 && nlineas < NML){
   //Asignar espacio para una cadena de caracteres
   p=(char *)malloc(longitud+1);
   if (p==NULL){
    printf("Insuficiente espacio de memoria\n");
    exit(1); //Terminar Proceso
   }
   else {
    //Copiar la cadena en el espacio de memoria asignado
    strcpy(p,linea);
    //Guardar el puntero a la cadena en el Array
    plinea[nlineas++]=p;
   }
  }

  //Escribir las cadenas almacenadas

  printf("Lineas Almacenadas : \n\n");
  for (i=0;i<nlineas;i++)
  printf("%s\n",plinea[i]);
  getch();
  }




