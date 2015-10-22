#include<conio.h>
#include <stdlib.h>
#include <stdio.h>     //FUNCION STRCAT :Pega las dos cadenas de caracteres
#include<string.h>

void main(void)
{

   int n,n2;
   char *str ="hello man is a good day to go fishing",*str2="hola mundo";
   clrscr();
   printf("%s ",strcat(str,str2));
   getch();
}