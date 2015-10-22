#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define NMAX 25   // Numero maximo de cadenas
#define CMAX 81   // Numero maximo de caracteres por cadena

main (){
  char cadena [NMAX][CMAX];   // Array de cadenas
  char *pcadena[NMAX];        // Array de punteros a cadenas
  int ncadenas;                // Numero de cadenas leidas

  int LeerCadena(char cadena [][CMAX],char *pcadena[],int nmc);
  void clasificar(char *pcadena[],int nc);
  void escribir (char *pcadena[],int nc);

  clrscr();
  printf("Clasificacion de cadenas por caracteres. \n\n");
  printf("Introducir cadenas a clasificar. Enter para salir. \n");
  if ((ncadenas=LeerCadena(cadena,pcadena,NMAX)) > 0){
    printf("Proceso de clasificacion .\n\n");
    clasificar(pcadena,ncadenas);
    escribir(pcadena,ncadenas);
  }
  else
    printf("Cero o demasiadas cadenas para clasificar. \n");

getch();
}

//***************************************************************************

// FUNCION LEER CADENAS
int LeerCadena(char cadena [][CMAX],char *pcadena[],int nmc){

  // nmc = numero maximo de cadenas
  int longitud,ncadenas=0;

  while ((longitud = strlen(gets(cadena[ncadenas]))) > 0){

   if (ncadenas >= nmc)
      return (-1);  // Demasiadas Cadenas a ordenar
   else
   //Guardar el apuntador a la cadena en el array
   pcadena[ncadenas++]=cadena[ncadenas];
  }
  return (ncadenas);  // Numero de cadenas leidas
}

//**************************************

// FUNCION CLASIFICAR

/* Ordena las cadenas pcadena[0] ... pcadena[nc-1] ascendentemente.
   nc = Numero de cadenas a ordenar.*/

void clasificar (char *pcadena[],int nc){
char *aux;   //Puntero auxiliar
int i,s=1;

while ((s = 1) && (--nc > 0)){
 s = 0;  //No permutacion
 for (i = 1;i <= nc; i++)
  if(strcmp(pcadena[i-1],pcadena[i]) > 0){
    aux=pcadena[i-1];
    pcadena[i-1]=pcadena[i];
    pcadena[i]=aux;
    s = 1;   // Permutacion
  }
 }
}
//*********************************

//FUNCION ESCRIBIR
void escribir (char *pcadena[],int nc){
// nc = numero de cadenas a escribir
while (--nc >= 0)
 printf ("%s \n",*pcadena++);
}




