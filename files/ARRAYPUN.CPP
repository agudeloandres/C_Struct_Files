#include <stdio.h>
#include <conio.h>
#include <dos.h>
main () {
clrscr();
int i,j;
char *  nombres [4]={"lola","paca","vilma","betty"};


printf("%s\n",nombres[1]); //Imprime todo el nombre "paca"


for (i=0;i<=3;i++){
  printf("%c",*(nombres[1]+i)); //Imprime por letras  "paca"
  delay(150);
  }
  printf("\n");

char * p;

p=nombres[1]; //Asignacion del puntero no lleva & por ser arreglo

for (i=0;i<=3;i++){
 printf("%c",*(p+i)); // Lo mismo que:   printf("%c",p[i]); "paca"
 delay(150);
 }
 printf("\n\n");

//imprimir todos los nombres

/*for(j=0;j<=3;j++){
  p=nombres[j];
  i=0;
  while ( *p != '\0'){
   printf("%c",*p);
   i++;
   }
   }  */

for (j=0;j<=3;j++)    //Imprime todos los nombres
 printf("%s\n",nombres[j]);

char **q;
q=nombres; //No lleva & por ser un array

printf("%c\n",*(*q+2)); // Imprime la 2da "l" de lola

printf("%c\n",*(*(q+2)+3)); // Imprime la "m" de vilma

printf("%c\n",*(*(q+3)+4)); //Imprime la "y" de betty

printf("%c\n",*(nombres[3]+4)); //Imprime la "y" de betty
getch();
}
